#include "../head/semer.h"

FieldList hashTable[HASH_SIZE]; // hash ,which stores "variables"
int scope_id = 0;               // id for new scope
int current_id = 0;
scope scopeTable[50];

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

void initHashtable() {
  for (int i = 0; i < HASH_SIZE; i++) {
    hashTable[i] = nullptr;
  }
  scope sc;
  sc.id = 0;
  sc.parent_id = -1; // root layer
  sc.o[0] = 0;
  sc.oNum = 1;
  current_id = 0;
  // put current sc in scopeTable
  scopeTable[current_id] = sc;
}

void scope_enter() {
  scope_id++; // 2
  scope sc;
  sc.id = scope_id;                            // sc.id = 2
  sc.parent_id = current_id;                   // sc.parent_id = 0
  current_id = scope_id;                       // current_id = 2
  sc.oNum = scopeTable[sc.parent_id].oNum + 1; // sc.oNum = sc_table[0].oNum +1
  for (int i = 0; i < sc.oNum - 1; i++) {
    sc.o[i] = scopeTable[sc.parent_id].o[i];
  }
  sc.o[sc.oNum - 1] = sc.id;

  scopeTable[current_id] = sc; // update scopeTable
}

void scope_exit() {
  scope sc = scopeTable[current_id];
  if (current_id == 0) {
    printf("scope error!Current id is zero!!!");
  }
  current_id = sc.parent_id;
}

int insert(FieldList f) {
  if (f == nullptr || f->name == nullptr)
    return 0;
  size_t key;
  key = hash_pjw(f->name);
  // define whether its type is a function
  if (f->type->kind != Type_::FUNCTION) {
    while (1) {
      if (hashTable[key] == nullptr) {
        hashTable[key] = f;
        return 1;
      }
      key = (++key) % HASH_SIZE;
    }
  } else {
    while (1) {
      if (hashTable[key] == nullptr) {
        hashTable[key] = f;
        return 1;
      }
      // if hash has this function
      if (!strcmp(hashTable[key]->name, f->name)) {
        if (f->type->u.function.state == DEFIN &&
            hashTable[key]->type->u.function.state == DECLA) {
          hashTable[key] = f;
          return 1;
        }
      }
      key = (++key) % HASH_SIZE;
    }
  }
  return 0;
}

FieldList
search(const char *name,
       int flag // flag=1:function flag=0:variable   their names can be the same
) {
  if (name == nullptr) {
    return nullptr;
  }
  size_t key;
  key = hash_pjw(name);
  FieldList p = hashTable[key];
  while (p != nullptr) {
    if (strcmp(name, p->name) == 0) {
      scope sc = scopeTable[current_id];
      // from inside to outside
      for (int i = sc.oNum - 1; i >= 0; i--) {
        if (p->scope_id == sc.o[i]) {
          return p;
        }
      }
    }
    key = (++key) % HASH_SIZE;
    p = hashTable[key];
  }
  return nullptr;
}

FieldList ifexist(const char *name, int id) {
  if (name == nullptr) {
    return nullptr;
  }
  unsigned int key;
  key = hash_pjw(name);
  FieldList p = hashTable[key];
  while (p != nullptr) {
    if (strcmp(name, p->name) == 0) {
      if (p->scope_id == id) {
        return p;
      }
    }
    key = (++key) % HASH_SIZE;
    p = hashTable[key];
  }
  return nullptr;
}

void printSymbol() {
  printf("***************\n");
  for (int i = 0; i < HASH_SIZE; i++) {
    if (hashTable[i] != NULL)
      printf("type:%d scope:%d name:%s \n", hashTable[i]->type->kind,
             hashTable[i]->scope_id, hashTable[i]->name);
  }
  printf("***************\n");
}

// int TypeEqual(Type t1, Type t2) {
//   if ((t1 == nullptr) || (t2 == nullptr))
//     return 0;
//   if (t1->kind != t2->kind)
//     return 0;
//   if (t1->kind == Type_::BASIC) {
//     return (t1->u.basic == t2->u.basic);
//   }
//   if (t1->kind == Type_::ARRAY) {
//     return (TypeEqual(t1->u.array.elem, t2->u.array.elem));
//   }
//   if (t1->kind == Type_::FUNCTION) {

//     // Num and type check
//     if (t1->u.function.paramNum != t2->u.function.paramNum)
//       return 0;
//     if (TypeEqual(t1->u.function.funcType, t2->u.function.funcType) == 0)
//       return 0;
//     FieldList p1 = t1->u.function.params;
//     FieldList p2 = t2->u.function.params;
//     for (int i = 0; i < t1->u.function.paramNum; i++) {
//       if (TypeEqual(p1->type, p2->type) == 0)
//         return 0;
//       p1 = p1->tail;
//       p2 = p2->tail;
//     }
//     return 1;
//   }
//   // printf("debug\n");
//   return 0;
// }

// Program     : SubPro DOT
void program(Node *root) {
  if (root == nullptr) {
    return;
  }
  // Program -> SubPro DOT
  if (!strcmp(root->child[0]->name, "SubPro") &&
      !strcmp(root->child[1]->name, "DOT")) {
    SubPro(root->child[0]);
  }
}

// SubPro      : DeclarePart Statements
//             | Statements
void SubPro(Node *node) {
  if (node == nullptr) {
    return;
  }
  // SubPro -> DeclarePart Statements
  if (!strcmp(node->child[0]->name, "DeclarePart") &&
      !strcmp(node->child[1]->name, "Statements") && node->childNum == 2) {
    DeclarePart(node->child[0]);
    Statements(node->child[1]);
  }
  // SubPro -> Statements
  else if (!strcmp(node->child[0]->name, "Statements") && node->childNum == 1) {
    Statements(node->child[0]);
  }
}

// DeclarePart : ConstDec
//            |ConstDec VarDec
//            |ConstDec ProDec
//            |ConstDec VarDec ProDec
//            |VarDec ProDec
//            |VarDec
//            |ProDec
void DeclarePart(Node *node) {
  if (node == nullptr) {
    return;
  }

  // DeclarePart -> ConstDec
  if (!strcmp(node->child[0]->name, "ConstDec") && node->childNum == 1) {
    ConstDec(node->child[0]);
  }

  // DeclarePart -> ConstDec VarDec
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "VarDec") && node->childNum == 2) {
    ConstDec(node->child[0]);
    VarDec(node->child[1]);
  }

  // DeclarePart -> ConstDec ProDec
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "ProDec") && node->childNum == 2) {
    ConstDec(node->child[0]);
    ProDec(node->child[1]);
  }

  // DeclarePart -> ConstDec VarDec ProDec
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "VarDec") &&
      !strcmp(node->child[2]->name, "ProDec") && node->childNum == 3) {
    ConstDec(node->child[0]);
    VarDec(node->child[1]);
    ProDec(node->child[2]);
  }
  // DeclarePart -> VarDec
  if (!strcmp(node->child[0]->name, "VarDec") && node->childNum == 1) {
    VarDec(node->child[0]);
  }

  // DeclarePart -> VarDec ProDec
  if (node->childNum == 2 && node->child[0] != nullptr &&
      node->child[1] != nullptr && !strcmp(node->child[0]->name, "VarDec") &&
      !strcmp(node->child[1]->name, "ProDec")) {
    VarDec(node->child[0]);
    ProDec(node->child[1]);
  }
  // DeclarePart -> ProDec
  if (!strcmp(node->child[0]->name, "ProDec") && node->childNum == 1) {
    ProDec(node->child[0]);
  }
}

// ConstDec    : ConstDec CONST ConstDef SEMI
//             | CONST ConstDef SEMI
void ConstDec(Node *node) {
  if (node == nullptr) {
    return;
  }
  // ConstDec -> ConstDec CONST ConstDef SEMI
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "CONST") &&
      !strcmp(node->child[2]->name, "ConstDef") &&
      !strcmp(node->child[3]->name, "SEMI")) {
    ConstDec(node->child[0]);
    ConstDef(node->child[2]);
  }
  // ConstDec -> CONST ConstDef SEMI
  if (!strcmp(node->child[0]->name, "CONST") &&
      !strcmp(node->child[1]->name, "ConstDef") &&
      !strcmp(node->child[2]->name, "SEMI")) {
    ConstDef(node->child[1]);
  }
}

// ConstDef    : ConstDef COMMA CDefine
//             | CDefine
void ConstDef(Node *node) {
  if (node == nullptr) {
    return;
  }
  // ConstDef -> ConstDef COMMA CDefine
  if (!strcmp(node->child[0]->name, "ConstDef") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "CDefine")) {
    ConstDef(node->child[0]);
    CDefine(node->child[2]);
  }
  // ConstDef -> CDefine
  if (!strcmp(node->child[0]->name, "CDefine")) {
    CDefine(node->child[0]);
  }
}

// CDefine     : IDENTIFIER EQUAL INTEGER_VAL
void CDefine(Node *node) {
  if (node == nullptr) {
    return;
  }
  // CDefine -> IDENTIFIER EQUAL INTEGER_VAL
  if (!strcmp(node->child[0]->name, "IDENTIFIER") &&
      !strcmp(node->child[1]->name, "EQUAL") &&
      !strcmp(node->child[2]->name, "INTEGER_VAL")) {
    FieldList f = (FieldList)malloc(sizeof(FieldList_));
    f->name = node->child[0]->yytext;
    f->type = (Type)malloc(sizeof(Type_));
    f->type->kind = Type_::BASIC;
    f->type->u.basic = INT_TYPE;
    f->is_const = true;
    f->value = atoi(node->child[2]->yytext);
    f->scope_id = current_id;
    f->tail = nullptr;

    // check
    if (ifexist(f->name, f->scope_id) != nullptr) {
      printf("Error at Line %d: Redefined variable %s.\n",
             node->child[0]->lineRow, f->name);
    } else {
      insert(f);
    }
  }
}

// VarDec      : VarDec VarObj
//             | VarObj
void VarDec(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "VarDec") &&
      !strcmp(node->child[1]->name, "VarObj") && node->childNum == 2) {
    VarDec(node->child[0]);
    VarObj(node->child[1]);
  } else if (!strcmp(node->child[0]->name, "VarObj") && node->childNum == 1) {
    VarObj(node->child[0]);
  }
}

// VarObj      :VAR IdentiDef SEMI
void VarObj(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "VAR") &&
      !strcmp(node->child[1]->name, "IdentiDef") &&
      !strcmp(node->child[2]->name, "SEMI")) {
    IdentiDef(node->child[1]);
  }
}

// IdentiDef   : IdentiDef COMMA IdentiObject
//             | IdentiObject
void IdentiDef(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IdentiDef") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "IdentiObject")) {
    IdentiDef(node->child[0]);
    IdentiObject(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "IdentiObject")) {
    IdentiObject(node->child[0]);
  }
}

// IdentiObject : IDENTIFIER
//              | IDENTIFIER Array(: SL_PAREN ArrayIndex COLON ArrayIndex
//              SR_PAREN )
void IdentiObject(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IDENTIFIER") && node->childNum == 1) {
    FieldList f = (FieldList)malloc(sizeof(FieldList_));
    f->name = node->child[0]->yytext;
    f->type = (Type)malloc(sizeof(Type_));
    f->type->kind = Type_::BASIC;
    f->type->u.basic = INT_TYPE;
    f->is_const = false;
    f->value = atoi(node->child[0]->yytext);
    f->scope_id = current_id;
    f->tail = nullptr;

    // check
    if (ifexist(f->name, f->scope_id) != nullptr)
      printf("Error at Line %d: Redefined variable %s.\n", node->lineRow,
             f->name);
    else {
      insert(f);
    }
  } else if (!strcmp(node->child[0]->name, "IDENTIFIER") &&
             !strcmp(node->child[1]->name, "Array") && node->childNum == 2) {

    Array(node->child[0], node->child[1]);
  }
}

// Array       : SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN
void Array(Node *id, Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "SL_PAREN") &&
      !strcmp(node->child[1]->name, "ArrayIndex") &&
      !strcmp(node->child[2]->name, "COLON") &&
      !strcmp(node->child[3]->name, "ArrayIndex") &&
      !strcmp(node->child[4]->name, "SR_PAREN") && node->childNum == 5) {
    ArrayIndex(id, node->child[1], node->child[3]);
  }
}

// ArrayIndex  : INTEGER_VAL
//             | IDENTIFIER
void ArrayIndex(Node *id, Node *node1, Node *node2) {
  if (node1 == nullptr || node2 == nullptr) {
    return;
  }
  int i = 0, j = 0;
  if (!strcmp(node1->child[0]->name, "INTEGER_VAL")) {
    i = atoi(node1->child[0]->yytext);
  } else {
    if (ifexist(node1->child[0]->yytext, current_id) == nullptr) {
      printf("Error at Line %d: Undefined variable %s.\n", node1->lineRow,
             node1->child[0]->yytext);
    } else {
      i = ifexist(node1->child[0]->yytext, current_id)->value;
    }
  }
  if (!strcmp(node2->child[0]->name, "INTEGER_VAL")) {
    j = atoi(node2->child[0]->yytext);
  } else {
    if (ifexist(node2->child[0]->yytext, current_id) == nullptr) {
      printf("Error at Line %d: Undefined variable %s.\n", node2->lineRow,
             node2->child[0]->yytext);
    } else {
      j = ifexist(node2->child[0]->yytext, current_id)->value;
    }
  }
  int size = j - i + 1;
  if (size <= 0) {
    printf("Error at Line %d: Array size is less than 0.\n", node1->lineRow);
    return;
  }
  FieldList f = (FieldList)malloc(sizeof(FieldList_));
  f->name = id->yytext;
  f->type = (Type)malloc(sizeof(Type_));
  f->type->kind = Type_::ARRAY;
  f->is_const = false;
  f->type->u.array.size = size;
  if (ifexist(f->name, f->scope_id) != nullptr)
    printf("Error at Line %d: Redefined Array %s.\n", node1->lineRow, f->name);
  else {
    insert(f);
    //   FieldList a = search(f->name, 0);
    //   if (a != nullptr)
    //   // printf("name:%s size:%d\n", a->name, a->type->u.array.size);
  }
}

// ProDec      : ProceHead SubPro SEMI
//             | ProDec ProceHead SubPro SEMI
void ProDec(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "ProDec") &&
      !strcmp(node->child[1]->name, "ProceHead") &&
      !strcmp(node->child[2]->name, "SubPro") &&
      !strcmp(node->child[3]->name, "SEMI")) {
    ProDec(node->child[0]);
    ProceHead(node->child[1]);
    scope_enter();
    SubPro(node->child[2]);
    scope_exit();
  } else if (!strcmp(node->child[0]->name, "ProceHead") &&
             !strcmp(node->child[1]->name, "SubPro") &&
             !strcmp(node->child[2]->name, "SEMI")) {
    ProceHead(node->child[0]);
    scope_enter();
    SubPro(node->child[1]);
    scope_exit();
  }
}

// ProceHead   : PROCEDURE IDENTIFIER SEMI
void ProceHead(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "PROCEDURE") &&
      !strcmp(node->child[1]->name, "IDENTIFIER") &&
      !strcmp(node->child[2]->name, "SEMI")) {
    FieldList f = (FieldList)malloc(sizeof(FieldList_));
    f->name = node->child[1]->yytext;
    f->type = (Type)malloc(sizeof(Type_));
    f->type->kind = Type_::FUNCTION;
    f->type->u.function.state = DEFIN;
    f->scope_id = current_id;
    f->tail = nullptr;

    // check
    if (ifexist(f->name, f->scope_id) != nullptr)
      printf("Error at Line %d: Redefined Function %s.\n", node->lineRow,
             f->name);
    else {
      insert(f);
    }
  }
}

// Statements  : AssignStm
//             | ComplexStm
//             | CondiStm
//             | WhileStm
//             | CallS
//             | ReadS
//             | WriteS
void Statements(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "AssignStm")) {
    AssignStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "ComplexStm")) {
    ComplexStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "CondiStm")) {
    CondiStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "WhileStm")) {
    WhileStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "CallS")) {
    CallS(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "ReadS")) {
    ReadS(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "WriteS")) {
    WriteS(node->child[0]);
  }
}

// Identifier  : IDENTIFIER SL_PAREN INdex_Index SR_PAREN
//              | IDENTIFIER
void Identifier(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IDENTIFIER") && node->childNum == 1) {
    if (search(node->child[0]->yytext, 0) == nullptr) {
      printf("Error at Line %d: Undefined variable %s.\n", node->lineRow,
             node->child[0]->yytext);
    } else {
      FieldList f = search(node->child[0]->yytext, 0);
      if (f->type->kind == Type_::ARRAY) {
        printf("Error at Line %d: %s is an array.\n", node->lineRow,
               node->child[0]->yytext);
        return;
      }
      insert(f);
    }
  } else if (node->childNum == 4 &&
             !strcmp(node->child[0]->name, "IDENTIFIER") &&
             !strcmp(node->child[1]->name, "SL_PAREN") &&
             !strcmp(node->child[2]->name, "INdex_Index") &&
             !strcmp(node->child[3]->name, "SR_PAREN")) {
    if (search(node->child[0]->yytext, 0) == nullptr) {
      printf("Error at Line %d: Undefined variable(array) %s.\n", node->lineRow,
             node->child[0]->yytext);
    } else {
      FieldList f = search(node->child[0]->yytext, 0);
      if (f->type->kind != Type_::ARRAY) {
        printf("Error at Line %d: %s is not an array.\n", node->lineRow,
               node->child[0]->yytext);
        return;
      }
      insert(f);
      INdex_Index(node->child[2]);
    }
  }
}

// INdex_Index  : Expr
void INdex_Index(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Expr")) {
    Expr(node->child[0]);
  }
}

// AssignStm   : Identifier ASSIGN Expr
void AssignStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Identifier") &&
      !strcmp(node->child[1]->name, "ASSIGN") &&
      !strcmp(node->child[2]->name, "Expr") && node->childNum == 3) {
    Identifier(node->child[0]);
    FieldList f;
    // printf("%s\n", node->child[0]->child[0]->yytext);
    f = search(node->child[0]->child[0]->yytext, 0);
    if (f != nullptr) {
      if (f->is_const == true) {
        printf("Error at Line %d: %s is a const variable.\n", node->lineRow,
               node->child[0]->child[0]->yytext);
        return;
      }
      Expr(node->child[2]);
    }
  }
}

// ComplexStm    : _BEGIN_ ComStates END
void ComplexStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "_BEGIN_") &&
      !strcmp(node->child[1]->name, "ComStates") &&
      !strcmp(node->child[2]->name, "END")) {
    scope_enter();
    ComStates(node->child[1]);
    scope_exit();
  }
}

// ComStates    : ComStates Statements SEMI
//              | Statements SEMI
void ComStates(Node *node) {
  if (node == nullptr) {
    return;
  }

  // ComStates -> Statements SEMI
  if (node->childNum == 2 && node->child[0] != nullptr &&
      node->child[1] != nullptr &&
      !strcmp(node->child[0]->name, "Statements") &&
      !strcmp(node->child[1]->name, "SEMI")) {
    Statements(node->child[0]);
  }
  // ComStates -> ComStates  Statements SEMI
  else if (node->childNum == 3 && node->child[0] != nullptr &&
           node->child[1] != nullptr && node->child[2] != nullptr &&
           !strcmp(node->child[0]->name, "ComStates") &&
           !strcmp(node->child[1]->name, "Statements") &&
           !strcmp(node->child[2]->name, "SEMI")) {
    ComStates(node->child[0]);
    Statements(node->child[1]);
  }
}

// Condition   : Expr CMP Expr
//             | ODD Expr
void Condition(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Expr") &&
      !strcmp(node->child[1]->name, "CMP") &&
      !strcmp(node->child[2]->name, "Expr")) {
    Expr(node->child[0]);
    Expr(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "ODD") &&
             !strcmp(node->child[1]->name, "Expr")) {
    Expr(node->child[1]);
  }
}

// CondiStm    : IF Condition THEN Statements %prec LOWER_THAN_ELSE
//             | IF Condition THEN Statements ELSE Statements
void CondiStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IF") &&
      !strcmp(node->child[1]->name, "Condition") &&
      !strcmp(node->child[2]->name, "THEN") &&
      !strcmp(node->child[3]->name, "Statements")) {
    Condition(node->child[1]);
    Statements(node->child[3]);
  } else if (!strcmp(node->child[0]->name, "IF") &&
             !strcmp(node->child[1]->name, "Condition") &&
             !strcmp(node->child[2]->name, "THEN") &&
             !strcmp(node->child[3]->name, "Statements") &&
             !strcmp(node->child[4]->name, "ELSE") &&
             !strcmp(node->child[5]->name, "Statements")) {
    Condition(node->child[1]);
    Statements(node->child[3]);
    Statements(node->child[5]);
  }
}

// Expr        : Expr PLUS Term
//             | Expr MINUS Term
//             | PLUS Term
//             | MINUS Term
//             | Term
void Expr(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Expr") &&
      !strcmp(node->child[1]->name, "PLUS") &&
      !strcmp(node->child[2]->name, "Term")) {
    Expr(node->child[0]);
    Term(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "Expr") &&
             !strcmp(node->child[1]->name, "MINUS") &&
             !strcmp(node->child[2]->name, "Term")) {
    Expr(node->child[0]);
    Term(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "PLUS") &&
             !strcmp(node->child[1]->name, "Term")) {
    Term(node->child[1]);
  } else if (!strcmp(node->child[0]->name, "MINUS") &&
             !strcmp(node->child[1]->name, "Term")) {
    Term(node->child[1]);
  } else if (!strcmp(node->child[0]->name, "Term")) {
    Term(node->child[0]);
  }
}

// Term        : Term TIMES Factor
//             | Term DIVIDE Factor
//             | Factor
void Term(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Term") &&
      !strcmp(node->child[1]->name, "TIMES") &&
      !strcmp(node->child[2]->name, "Factor")) {
    Term(node->child[0]);
    Factor(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "Term") &&
             !strcmp(node->child[1]->name, "DIVIDE") &&
             !strcmp(node->child[2]->name, "Factor")) {
    Term(node->child[0]);
    Factor(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "Factor")) {
    Factor(node->child[0]);
  }
}

// Factor      : Identifier
//             | INTEGER_VAL
//             | SL_PAREN Expr SR_PAREN
void Factor(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Identifier")) {
    Identifier(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "INTEGER_VAL")) {
    // do nothing
  } else if (!strcmp(node->child[0]->name, "SL_PAREN") &&
             !strcmp(node->child[1]->name, "Expr") &&
             !strcmp(node->child[2]->name, "SR_PAREN")) {
    Expr(node->child[1]);
  }
}

// WhileStm    : WHILE Condition DO Statements
void WhileStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "WHILE") &&
      !strcmp(node->child[1]->name, "Condition") &&
      !strcmp(node->child[2]->name, "DO") &&
      !strcmp(node->child[3]->name, "Statements")) {
    Condition(node->child[1]);
    Statements(node->child[3]);
  }
}

// CallS       : CALL IDENTIFIER
void CallS(Node *node) {
  if (node == nullptr) {
    return;
  }
  // printf("debug\n");
  if (!strcmp(node->child[0]->name, "CALL") &&
      !strcmp(node->child[1]->name, "IDENTIFIER") && node->childNum == 2) {
    if (search(node->child[1]->yytext, 1) == nullptr) {
      printf("Error at Line %d: Undefined function %s.\n", node->lineRow,
             node->child[1]->yytext);
    } else {
      FieldList f = search(node->child[1]->yytext, 1);
      if (f->type->kind != Type_::FUNCTION) {
        printf("Error at Line %d: %s is not a function.\n", node->lineRow,
               node->child[1]->yytext);
        return;
      }
      f->type->u.function.state = DECLA;
      insert(f);
    }
  }
}

// ReadS       : READ SL_PAREN Rcontent SR_PAREN
void ReadS(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "READ") &&
      !strcmp(node->child[1]->name, "SL_PAREN") &&
      !strcmp(node->child[2]->name, "Rcontent") &&
      !strcmp(node->child[3]->name, "SR_PAREN")) {
    Rcontent(node->child[2]);
  }
}

// Rcontent     : Rcontent COMMA RconObj
//              | RconObj
void Rcontent(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Rcontent") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "RconObj")) {
    Rcontent(node->child[0]);
    RconObj(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "RconObj")) {
    RconObj(node->child[0]);
  }
}

// RconObj     : Identifier
void RconObj(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Identifier")) {
    Identifier(node->child[0]);
  }
}

// WriteS      : WRITE SL_PAREN Wcontent SR_PAREN
void WriteS(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "WRITE") &&
      !strcmp(node->child[1]->name, "SL_PAREN") &&
      !strcmp(node->child[2]->name, "Wcontent") &&
      !strcmp(node->child[3]->name, "SR_PAREN")) {
    Wcontent(node->child[2]);
  }
}

// Wcontent     : Wcontent COMMA WconObj
//              | WconObj
void Wcontent(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Wcontent") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "WconObj")) {
    Wcontent(node->child[0]);
    WconObj(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "WconObj")) {
    WconObj(node->child[0]);
  }
}

// WconObj     : Expr
void WconObj(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Expr")) {
    Expr(node->child[0]);
  }
}
