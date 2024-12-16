# 《编译原理》课程实验4报告

## 0221120281 文天鑫

### 实验目的

根据所学内容为扩展PL0语言实现一个语义分析器与中间代码生成器。

### 实验环境

- `GNU Flex` --词法分析模块
- `GNU Bison` --语法分析模块
- `C++` --`C++`为实现语言

### 实验思路

本次实验主要在原来的`Lexer`与`Parser`基础上进行语义分析与中间代码生成,具体内容则是将PL0语言中对应的错误类型与行数打印出来.而操作则是针对语法树进行分类的操作，从而建立并维护一个符号表来联系上下文(`context`).

而在这之后的操作则是根据符号表与语法树来生成相应的中间代码。**为了较好的模块性与隔离性，我将分成两部分来介绍相应的内容**.

### 实验内容

#### 语义分析

即文件夹下的`Semer`部分。

语义分析，也叫**上下文相关分析**。是用来处理源代码中存在的逻辑问题。在我看来，这里面最重要的过程一个是进行分类讨论的类型检查，另一个则是构建符号表。

类型检查包括**重定义**、**未定义**、**对于不同类型变量的非法赋值**等等，这些检查是在遍历语法树的时候需要做的工作。

而符号表则是编译过程中，编译器使用符号表来记录源程序中各种名字的特性信息的工具。这里的名字包括各种变量、函数等名字，而特征信息则是类型、维度数、参数个数等信息。

对于符号表的操作基本是插与查，而符号表内容的构成则更是自由度高，还有如何构建一个符号表，似乎有很多种选择。

以上详细内容我会放到**实验结果**后的**亮点与改进**部分。

##### 实验结果

首先是我的源代码，其中包含的`bug`有重定义、未定义、非法赋值等等，也有一些不同作用域下赋值的实现。

```pascal
{The Man Who Sold the }World}
const z=0;
var head(9:10), foot, cock, rabbit, n;
var a;
procedure multiply;
	var a,b;
    var a;
	begin
		a:=x; b:=y; z:=0;
		while b>0 do
			begin
				if odd b then z:=z+a;
				a:=2*a; b:=b/2;
			end;
	end;
begin
    n := z;
    read(head(z), foot)
;
multiply:=3;
    cock := 1;
    while cock <= head do
    begin
        rabbit := head - cock;
        if cock * 2 + rabbit * 4 = foot then
        begin
            write(cock, rabbit);
            n := n + 1;
        end;
        cock := cock + 1;
    end;
    if n = 0 then write(0,0)else write(1,0);
    
end.
```

而下图则是运行结果,`Figure 1`是输出出来的错误报告，`Figure`则是符号表的输出。

![image-20241216221936426](C:\Users\13488\AppData\Roaming\Typora\typora-user-images\image-20241216221936426.png)

![image-20241216221958050](C:\Users\13488\AppData\Roaming\Typora\typora-user-images\image-20241216221958050.png)

##### 亮点与改进

###### 符号表

首先是符号表的构建，进一步来讲就是数据结构的选择。

鉴于资料中大部分都是链表的构建,我想用一种性能更好的数据结构来构建我的符号表。

最后我在**平衡二叉树**与**哈希表**中选择了哈希表。因为前者我认为难以维护，而且写出一个成功正确的红黑树时间消耗较大。所以我选择了使用哈希表。

同时我选择了由`P.J. Weinberger`提出的`hash`函数,并且使用了`Closed Hashing`的方式来处理冲突并让散列表中元素分布更加均衡一些.

```c++
unsigned int hash_pjw(const char *name) {
  unsigned int val = 0, i;
  for (; *name; ++name) {
    val = (val << 2) + *name;
    if (i = val & ~0x3fff) {
      val = (val ^ (i >> 12)) & 0x3fff;
    }
    return val % HASH_SIZE;
  }
}
```

###### 多层作用域

其次便是对于作用域问题的考虑。

我构造了一个结构体来维护作用域。

```c++
// scope,conected with parent and update itself with all parents!
extern struct scope_ {
  int id;
  int parent_id; // outside scope
  int oNum;      // number of all outside scope and self scope
  int o[50];     // outsides's id,use it with oNum!
} scope_;
int scope_id = 0;               // id for new scope
int current_id = 0;
scope scopeTable[50];
```

我们对作用域的用处有两个地方，一个是看该变量名能不能被定义，也就是说该名字有没有在同层下重复定义过.

此时就需要当前的作用域信息，这里我用`current_id`标记当前作用域，`scopeTable`则是一个记录作用域的散列表，这样就能通过`current_id`找到当前作用域.

另一个是使用变量时看先前有没有被定义，这就需要从里层往外层找变量的定义，此时就需要知道当前作用域和其外层作用域的范围，故而该结构需要知道`oNum`和`o`。其中计算其外层作用域范围的方法只需要用其`parent`作用域的`o`加上自己即可。（也可只往`parent`遍历）

同时我们还需要进行进入新的作用域和退出当前作用域的操作，而退出当前作用域也需要parent_id的存在。

而且，在我们退出作用域时不会删除这个作用域的变量，方便记录与观察,也许会对未来的某种分析产生一些帮助。

由于我的符号表不会生成多个，而是是自始至终在单个符 号表上进行动态维护.这种维护风格也是`Imperative Style`.

#### 中间代码生成

即文件夹下的`Irer`部分。

简单来讲就是将源代码翻译为中间代码，而中间代码的形式有抽象语法树`AST`或者三地址码`TAC`.

我在查资料的时候发现，大部分PL0的中间代码都是`P-CODE`.同时中间代码仍有一些不同的分类。

其实不难理解，本质上就是将源代码翻译为了不同程度的另一种语言，根据保留的高级特性与对目标语言的靠近，分为不同层次的中间代码。

当然也有用不同数据结构来构建中间代码的，比如树型或者线性等等.

以及我个人认为最重要的一部分则是如何翻译这些基本语句。

以上详细内容我会放到**实验结果**后的**亮点与改进**部分。

##### 实验结果

源代码

```pascal
const m=7, n=85;
var x,y,z,q,r,arr(1:3);
procedure multiply;
	var a,b;
	begin
		a:=x; b:=y; z:=0;
		while b>0 do
			begin
				if odd b then z:=z+a;
				a:=2*a; b:=b/2;
			end;
	end;
begin
	x:=m; y:=n; arr(1):=1; call multiply(z);
end.
```

中间代码

```pascal
m := #7
n := #85
DEC arr 12 
FUNCTION multiply : 
a := x
b := y
temp4 := #0
z := temp4
LABEL label1 : 
temp7 := #0
IF b > temp7 GOTO label2
GOTO label3
LABEL label2 : 
temp9 := b % #2
IF temp9 == #1 GOTO label4
GOTO label5
LABEL label4 : 
temp10 := z + a
z := temp10
LABEL label5 : 
temp15 := #2
temp13 := temp15 * a
a := temp13
temp20 := #2
temp17 := b / temp20
b := temp17
GOTO label1
LABEL label3 : 
x := m
y := n
temp26 := #1
temp25 := temp26 * #12
temp27 := &arr + temp25
temp29 := #1
arr := temp29
CALL multiply
```

##### 亮点与改进

前面便已经提到，为了很好的模块与隔离性，我的中间代码生成部分并没有插入进我之前的语义分析代码中，个人认为这样做也方便调试也维护。

###### 中间代码结构

对于中间代码的结构，我采用的是线性的动态数组,方便维护的同时也能更好地维护空间。但其实整体来看，对于中间代码的处理都在尾部插入，所以用链表也是合理的。

```c++
InterCode *IRList; // IR table
void insertCode(InterCode ir) {
  if (IRsize >= IRMAXSIZE) {
    IRList = (InterCode *)realloc(IRList, sizeof(InterCode) * IRMAXSIZE * 2);
    IRMAXSIZE = IRMAXSIZE * 2;
  }
  // printf("%d\n",IRMAXSIZE);
  IRList[IRsize] = ir;
  IRsize++;
}
void deletelastCode() {
  IRsize--;
  IRList[IRsize] = nullptr;
}
```

###### 翻译模式

这里只列举其中一个例子

![image-20241216233058318](C:\Users\13488\AppData\Roaming\Typora\typora-user-images\image-20241216233058318.png)

```c++
// WhileStm    : WHILE Condition DO Statements
void rWhileStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  Operand label1 = new_label();
  Operand label2 = new_label();
  Operand label3 = new_label();

  InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
  code1->kind = InterCode_::LABEL_IR;
  code1->operands[0] = label1;
  insertCode(code1);

  rCondition(node->child[1], label2, label3);

  InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
  code2->kind = InterCode_::LABEL_IR;
  code2->operands[0] = label2;
  insertCode(code2);

  rStatements(node->child[3]);

  InterCode code3 = (InterCode)malloc(sizeof(InterCode_));
  code3->kind = InterCode_::GOTO_IR;
  code3->operands[0] = label1;
  insertCode(code3);

  InterCode code4 = (InterCode)malloc(sizeof(InterCode_));
  code4->kind = InterCode_::LABEL_IR;
  code4->operands[0] = label3;
  insertCode(code4);
}
```

