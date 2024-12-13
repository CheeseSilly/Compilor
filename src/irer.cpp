#include "../head/irer.h"

#define SIZE 10
int lnum = 1; // l->label
int tnum = 1; // t -> temp
int vnum = 1; // v -> value

InterCode *IRList; // IR table
int IRsize;
int IRMAXSIZE;
void repr(Operand op, FILE *fp);

// semer.cpp
extern FieldList hashTable[HASH_SIZE];
extern int scope_id;
extern int current_id;
extern scope scopeTable[50];

void initIRList() {
  IRList = (InterCode *)malloc(SIZE * sizeof(InterCode));
  if (IRList == nullptr) {
    printf("error\n");
    return;
  }
  IRMAXSIZE = SIZE;
  // printf("debug : %d\n",IRMAXSIZE);
  IRsize = 0;

  scope_id = 0;
  scope sc;
  sc.id = 0;
  sc.parent_id = -1;
  sc.o[0] = 0;
  sc.oNum = 1;
  current_id = 0;
  scopeTable[current_id] = sc;
}

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

void repr(Operand op, FILE *fp) {
  if (op == nullptr) {
    fputs("t0	", fp);
    return;
  }
  char str[50];
  memset(str, 0, sizeof(str));
  switch (op->kind) {

  case Operand_::VARIABLE_OP:
    if (op->u.value != nullptr) {
      sprintf(str, "%s", op->u.value);
      fputs(str, fp);
    }
    break;
  case Operand_::TEMPVAR_OP:
    sprintf(str, "temp%d", op->u.var_no);
    fputs(str, fp);
    break;
  case Operand_::CONSTANT_OP:
    sprintf(str, "#%s", op->u.value);
    fputs(str, fp);
    break;
  case Operand_::ADDR_OP:
    sprintf(str, "*temp%d", op->u.var_no);
    fputs(str, fp);
    break;
  case Operand_::QU_ADDR_OP:
    sprintf(str, "&%s", op->u.value);
    fputs(str, fp);
    break;
  case Operand_::LABEL_OP:
    sprintf(str, "label%d", op->u.label_no);
    fputs(str, fp);
    break;
  case Operand_::FUNCTION_OP:
    sprintf(str, "%s", op->u.value);
    fputs(str, fp);
    break;
  }
}
void printCode(char *filename) {
  FILE *fp;
  if (strcmp(filename, "stdout") == 0) {
    fp = stdout;
  } else {
    fp = fopen(filename, "w");
  }
  if (fp == nullptr) {
    printf("open file error!\n");
    return;
  }
  // printf("the number of IR:%d\n",IRsize);
  for (int i = 0; i < IRsize; i++) {
    InterCode ir = IRList[i];
    if (ir == nullptr) {
      continue;
    }
    switch (ir->kind) {
    case InterCode_::LABEL_IR:
      fputs("LABEL ", fp);
      repr(ir->operands[0], fp);
      fputs(" : ", fp);
      break;
    case InterCode_::FUNCTION_IR:
      fputs("FUNCTION ", fp);
      repr(ir->operands[0], fp);
      fputs(" : ", fp);
      break;
    case InterCode_::ASSIGN_IR:
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      break;
    case InterCode_::PLUS_IR:
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      fputs(" + ", fp);
      repr(ir->operands[2], fp);
      break;
    case InterCode_::MINUS_IR:
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      fputs(" - ", fp);
      repr(ir->operands[2], fp);
      break;
    case InterCode_::STAR_IR:
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      fputs(" * ", fp);
      repr(ir->operands[2], fp);
      break;
    case InterCode_::DIV_IR:
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      fputs(" / ", fp);
      repr(ir->operands[2], fp);
      break;
    case InterCode_::ADDR_IR2:
      repr(ir->operands[0], fp);
      fputs(" := &", fp);
      repr(ir->operands[1], fp);
      break;
    case InterCode_::ADDR_IR3:
      repr(ir->operands[0], fp);
      fputs(" := &", fp);
      repr(ir->operands[1], fp);
      fputs(" + ", fp);
      repr(ir->operands[2], fp);
      break;
    case InterCode_::ADDR_VALUE_IR:
      repr(ir->operands[0], fp);
      fputs(" := *", fp);
      repr(ir->operands[1], fp);
      break;
    case InterCode_::MEMORY_IR:
      fputs("*", fp);
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      break;
    case InterCode_::GOTO_IR:
      fputs("GOTO ", fp);
      repr(ir->operands[0], fp);
      break;
    case InterCode_::IF_GOTO_IR:
      fputs("IF ", fp);
      repr(ir->operands[0], fp);
      fputs(" ", fp);
      fputs(ir->relop, fp);
      fputs(" ", fp);
      repr(ir->operands[1], fp);
      fputs(" GOTO ", fp);
      repr(ir->operands[2], fp);
      break;
    // case InterCode_::RETURN_IR:
    //   fputs("RETURN ", fp);
    //   repr(ir->operands[0], fp);
    //   break;
    case InterCode_::DEC_IR:
      fputs("DEC ", fp);
      repr(ir->operands[0], fp);
      char str[10];
      memset(str, 0, sizeof(str));
      sprintf(str, " %d ", ir->size);
      fputs(str, fp);
      break;
    case InterCode_::ARG_IR:
      fputs("ARG ", fp);
      repr(ir->operands[0], fp);
      break;
    case InterCode_::CALL_IR:
      // repr(ir->operands[0], fp);
      fputs("CALL ", fp);
      repr(ir->operands[1], fp);
      break;
    case InterCode_::PARAM_IR:
      fputs("PARAM ", fp);
      repr(ir->operands[0], fp);
      break;
    case InterCode_::READ_IR:
      fputs("READ ", fp);
      repr(ir->operands[0], fp);
      break;
    case InterCode_::WRITE_IR:
      fputs("WRITE ", fp);
      repr(ir->operands[0], fp);
      break;
    case InterCode_::MOD_IR:
      repr(ir->operands[0], fp);
      fputs(" := ", fp);
      repr(ir->operands[1], fp);
      fputs(" % ", fp);
      repr(ir->operands[2], fp);
      break;
    case InterCode_::DEBUG_IR:
      fputs("DEBUG", fp);
      fputs(ir->operands[0]->u.value, fp);
      break;
    }
    fputs("\n", fp);
  }
  fclose(fp);
}

int getSpace(Type type) {
  if (type == nullptr) {
    return 0;
  }
  if (type->kind == Type_::ARRAY) {
    // recursive ,and can also deal with multi-dimensional array
    // but we don't need to notice multi-dimensional array
    int size = type->u.array.size * 4;

    return size;
  } else if (type->kind == Type_::BASIC) {
    if (type->u.basic == INT_TYPE) {
      return 4;
    }
  } else {
    // printf("debug: getspace type:%d", type->kind);
  }
  // printf("debug 1558");
  return 1;
}

Operand new_temp() {
  Operand t = (Operand)malloc(sizeof(Operand_));
  t->kind = Operand_::TEMPVAR_OP;
  t->u.var_no = tnum++;
  return t;
}

Operand new_label() {
  Operand t = (Operand)malloc(sizeof(Operand_));
  t->kind = Operand_::LABEL_OP;
  t->u.label_no = lnum++;
  return t;
}

Operand new_constant(int i) {
  Operand t = (Operand)malloc(sizeof(Operand_));
  t->kind = Operand_::CONSTANT_OP;
  // i->string to t->u.value
  sprintf(t->u.value, "%d", i);
  // printf("%s",t->u.value);
  return t;
}

// may be we can combine ifexist and search~~~
FieldList allsearch(char *name, int flag

) {
  if (name == nullptr) {
    return nullptr;
  }
  size_t key;
  key = hash_pjw(name);
  FieldList p = hashTable[key];
  while (p != nullptr) {
    if (strcmp(name, p->name) == 0) {
      return p;
    }
    key = (++key) % HASH_SIZE;
    p = hashTable[key];
  }
  return nullptr;
}

// Program     : SubPro DOT
void rprogram(Node *root) {
  if (root == nullptr) {
    return;
  }
  // Program -> SubPro DOT
  if (!strcmp(root->child[0]->name, "SubPro") &&
      !strcmp(root->child[1]->name, "DOT")) {
    rSubPro(root->child[0]);
  }
}

// SubPro      : DeclarePart Statements
//             | Statements
void rSubPro(Node *node) {
  if (node == nullptr) {
    return;
  }
  // SubPro -> DeclarePart Statements
  if (!strcmp(node->child[0]->name, "DeclarePart") &&
      !strcmp(node->child[1]->name, "Statements") && node->childNum == 2) {
    rDeclarePart(node->child[0]);
    rStatements(node->child[1]);
  }
  // SubPro -> Statements
  else if (!strcmp(node->child[0]->name, "Statements") && node->childNum == 1) {

    rStatements(node->child[0]);
  }
}

// DeclarePart : ConstDec
//            |ConstDec VarDec
//            |ConstDec ProDec
//            |ConstDec VarDec ProDec
//            |VarDec ProDec
//            |VarDec
//            |ProDec
void rDeclarePart(Node *node) {
  if (node == nullptr) {
    return;
  }

  // DeclarePart -> ConstDec
  if (!strcmp(node->child[0]->name, "ConstDec") && node->childNum == 1) {
    rConstDec(node->child[0]);
  }

  // DeclarePart -> ConstDec VarDec
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "VarDec") && node->childNum == 2) {
    rConstDec(node->child[0]);
    rVarDec(node->child[1]);
  }

  // DeclarePart -> ConstDec ProDec
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "ProDec") && node->childNum == 2) {
    rConstDec(node->child[0]);
    rProDec(node->child[1]);
  }

  // DeclarePart -> ConstDec VarDec ProDec
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "VarDec") &&
      !strcmp(node->child[2]->name, "ProDec") && node->childNum == 3) {
    rConstDec(node->child[0]);
    rVarDec(node->child[1]);
    rProDec(node->child[2]);
  }
  // DeclarePart -> VarDec
  if (!strcmp(node->child[0]->name, "VarDec") && node->childNum == 1) {
    rVarDec(node->child[0]);
  }

  // DeclarePart -> VarDec ProDec
  if (node->childNum == 2 && node->child[0] != nullptr &&
      node->child[1] != nullptr && !strcmp(node->child[0]->name, "VarDec") &&
      !strcmp(node->child[1]->name, "ProDec")) {
    rVarDec(node->child[0]);
    rProDec(node->child[1]);
  }
  // DeclarePart -> ProDec
  if (!strcmp(node->child[0]->name, "ProDec") && node->childNum == 1) {
    rProDec(node->child[0]);
  }
}

// ConstDec    : ConstDec CONST ConstDef SEMI
//             | CONST ConstDef SEMI
void rConstDec(Node *node) {
  if (node == nullptr) {
    return;
  }
  // ConstDec -> ConstDec CONST ConstDef SEMI
  if (!strcmp(node->child[0]->name, "ConstDec") &&
      !strcmp(node->child[1]->name, "CONST") &&
      !strcmp(node->child[2]->name, "ConstDef") &&
      !strcmp(node->child[3]->name, "SEMI")) {
    rConstDec(node->child[0]);
    rConstDef(node->child[2]);
  }
  // ConstDec -> CONST ConstDef SEMI
  if (!strcmp(node->child[0]->name, "CONST") &&
      !strcmp(node->child[1]->name, "ConstDef") &&
      !strcmp(node->child[2]->name, "SEMI")) {
    rConstDef(node->child[1]);
  }
}

// ConstDef    : ConstDef COMMA CDefine
//             | CDefine
void rConstDef(Node *node) {
  if (node == nullptr) {
    return;
  }
  // ConstDef -> ConstDef COMMA CDefine
  if (!strcmp(node->child[0]->name, "ConstDef") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "CDefine")) {
    rConstDef(node->child[0]);
    rCDefine(node->child[2]);
  }
  // ConstDef -> CDefine
  if (!strcmp(node->child[0]->name, "CDefine")) {
    rCDefine(node->child[0]);
  }
}

// CDefine     : IDENTIFIER EQUAL INTEGER_VAL
void rCDefine(Node *node) {
  if (node == nullptr) {
    return;
  }
  // CDefine -> IDENTIFIER EQUAL INTEGER_VAL
  if (!strcmp(node->child[0]->name, "IDENTIFIER") &&
      !strcmp(node->child[1]->name, "EQUAL") &&
      !strcmp(node->child[2]->name, "INTEGER_VAL")) {
    // printf("debug: const %s\n", node->child[0]->yytext);
    Operand place = new_constant(atoi(node->child[2]->yytext));
    FieldList p = allsearch(node->child[0]->yytext, 0);
    if (p == nullptr) {
      printf("Error at Line %d: Undefined variable %s.\n", node->lineRow,
             node->child[0]->yytext);
      return;
    }
    Operand op1 = (Operand)malloc(sizeof(Operand_));
    op1->kind = Operand_::VARIABLE_OP;
    strcpy(op1->u.value, p->name);
    InterCode ir = (InterCode)malloc(sizeof(InterCode_));
    ir->kind = InterCode_::ASSIGN_IR;
    ir->operands[0] = op1;
    ir->operands[1] = place;
    insertCode(ir);
  }
}

// VarDec      : VarDec VarObj
//             | VarObj
void rVarDec(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "VarDec") &&
      !strcmp(node->child[1]->name, "VarObj") && node->childNum == 2) {
    rVarDec(node->child[0]);
    rVarObj(node->child[1]);
  } else if (!strcmp(node->child[0]->name, "VarObj") && node->childNum == 1) {
    rVarObj(node->child[0]);
  }
}

// VarObj      :VAR IdentiDef SEMI
void rVarObj(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "VAR") &&
      !strcmp(node->child[1]->name, "IdentiDef") &&
      !strcmp(node->child[2]->name, "SEMI")) {
    rIdentiDef(node->child[1]);
  }
}

// IdentiDef   : IdentiDef COMMA IdentiObject
//             | IdentiObject
void rIdentiDef(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IdentiDef") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "IdentiObject")) {
    rIdentiDef(node->child[0]);
    rIdentiObject(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "IdentiObject")) {
    rIdentiObject(node->child[0]);
  }
}

// IdentiObject : IDENTIFIER
//              | IDENTIFIER Array(: SL_PAREN ArrayIndex COLON ArrayIndex
//              SR_PAREN )
void rIdentiObject(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IDENTIFIER") && node->childNum == 1) {
    return;
  } else if (!strcmp(node->child[0]->name, "IDENTIFIER") &&
             !strcmp(node->child[1]->name, "Array")) {

    rArray(node->child[0], node->child[1]);
  }
}

// Array       : SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN
void rArray(Node *id, Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "SL_PAREN") &&
      !strcmp(node->child[1]->name, "ArrayIndex") &&
      !strcmp(node->child[2]->name, "COLON") &&
      !strcmp(node->child[3]->name, "ArrayIndex") &&
      !strcmp(node->child[4]->name, "SR_PAREN")) {
    rArrayIndex(id, node->child[1], node->child[3]);
  }
}

// ArrayIndex  : INTEGER_VAL
//             | IDENTIFIER
void rArrayIndex(Node *id, Node *node1, Node *node2) {
  if (node1 == nullptr || node2 == nullptr) {
    return;
  }
  FieldList f = allsearch(id->yytext, 0);
  Operand op = (Operand)malloc(sizeof(Operand_));
  op->kind = Operand_::VARIABLE_OP;
  strcpy(op->u.value, f->name);

  InterCode decIR = (InterCode)malloc(sizeof(InterCode_));
  decIR->kind = InterCode_::DEC_IR;
  decIR->operands[0] = op;
  decIR->size = getSpace(f->type);

  insertCode(decIR);
}

// ProDec      : ProceHead SubPro SEMI
//             | ProDec ProceHead SubPro SEMI
void rProDec(Node *node) {
  if (node == nullptr) {
    return;
  }

  if (!strcmp(node->child[0]->name, "ProDec") &&
      !strcmp(node->child[1]->name, "ProceHead") &&
      !strcmp(node->child[2]->name, "SubPro") &&
      !strcmp(node->child[3]->name, "SEMI")) {
    rProDec(node->child[0]);
    rProceHead(node->child[1]);
    scope_enter();
    rSubPro(node->child[2]);
    scope_exit();
  } else if (!strcmp(node->child[0]->name, "ProceHead") &&
             !strcmp(node->child[1]->name, "SubPro") &&
             !strcmp(node->child[2]->name, "SEMI")) {
    rProceHead(node->child[0]);
    scope_enter();
    rSubPro(node->child[1]);
    scope_exit();
  }
}

// ProceHead   : PROCEDURE IDENTIFIER SEMI
void rProceHead(Node *node) {
  if (node == nullptr) {
    return;
  }
  FieldList f = allsearch(node->child[1]->yytext, 1);
  Operand op = (Operand)malloc(sizeof(Operand_));
  op->kind = Operand_::FUNCTION_OP;
  strcpy(op->u.value, node->child[1]->yytext);
  InterCode IR = (InterCode)malloc(sizeof(InterCode_));
  IR->kind = InterCode_::FUNCTION_IR;
  IR->operands[0] = op;
  insertCode(IR);
}

// Statements  : AssignStm
//             | ComplexStm
//             | CondiStm
//             | WhileStm
//             | CallS
//             | ReadS
//             | WriteS
void rStatements(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "AssignStm")) {
    // printf("debug: %s\n", node->child[0]->name);
    rAssignStm(node->child[0]);

  } else if (!strcmp(node->child[0]->name, "ComplexStm")) {
    rComplexStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "CondiStm")) {
    rCondiStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "WhileStm")) {
    rWhileStm(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "CallS")) {
    rCallS(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "ReadS")) {
    rReadS(node->child[0]);
  } else if (!strcmp(node->child[0]->name, "WriteS")) {
    rWriteS(node->child[0]);
  }
}

// Expr        : Expr PLUS Term
//             | Expr MINUS Term
//             | PLUS Term
//             | MINUS Term
//             | Term
void rExpr(Node *node, Operand &place) {
  if (node == nullptr) {
    return;
  }
  // Expr -> Expr PLUS Term
  if (!strcmp(node->child[0]->name, "Expr") &&
      !strcmp(node->child[1]->name, "PLUS") &&
      !strcmp(node->child[2]->name, "Term")) {
    Operand t1 = new_temp();
    rExpr(node->child[0], t1);
    Operand t2 = new_temp();
    rTerm(node->child[2], t2);
    InterCode code = (InterCode)malloc(sizeof(InterCode_));
    code->kind = InterCode_::PLUS_IR;
    code->operands[0] = place;
    code->operands[1] = t1;
    code->operands[2] = t2;
    insertCode(code);
  }
  // Expr -> Expr MINUS Term
  if (!strcmp(node->child[0]->name, "Expr") &&
      !strcmp(node->child[1]->name, "MINUS") &&
      !strcmp(node->child[2]->name, "Term")) {
    Operand t1 = new_temp();
    rExpr(node->child[0], t1);
    Operand t2 = new_temp();
    rTerm(node->child[2], t2);
    InterCode code = (InterCode)malloc(sizeof(InterCode_));
    code->kind = InterCode_::MINUS_IR;
    code->operands[0] = place;
    code->operands[1] = t1;
    code->operands[2] = t2;
    insertCode(code);
  }
  // Expr -> PLUS Term
  if (!strcmp(node->child[0]->name, "PLUS") &&
      !strcmp(node->child[1]->name, "Term")) {
    rTerm(node->child[1], place);
  }
  // Expr -> Term
  if (!strcmp(node->child[0]->name, "Term")) {
    // printCode("stdout");
    rTerm(node->child[0], place);
  }
}

// Term        : Term TIMES Factor
//             | Term DIVIDE Factor
//             | Factor
void rTerm(Node *node, Operand &place) {
  if (node == nullptr) {
    return;
  }
  // Term -> Term TIMES Factor
  if (!strcmp(node->child[0]->name, "Term") &&
      !strcmp(node->child[1]->name, "TIMES") &&
      !strcmp(node->child[2]->name, "Factor")) {
    Operand t1 = new_temp();
    rTerm(node->child[0], t1);
    Operand t2 = new_temp();
    rFactor(node->child[2], t2);
    InterCode code = (InterCode)malloc(sizeof(InterCode_));
    code->kind = InterCode_::STAR_IR;
    code->operands[0] = place;
    code->operands[1] = t1;
    code->operands[2] = t2;
    insertCode(code);
  }
  // Term -> Term DIVIDE Factor
  if (!strcmp(node->child[0]->name, "Term") &&
      !strcmp(node->child[1]->name, "DIVIDE") &&
      !strcmp(node->child[2]->name, "Factor")) {
    Operand t1 = new_temp();
    rTerm(node->child[0], t1);
    Operand t2 = new_temp();
    rFactor(node->child[2], t2);
    InterCode code = (InterCode)malloc(sizeof(InterCode_));
    code->kind = InterCode_::DIV_IR;
    code->operands[0] = place;
    code->operands[1] = t1;
    code->operands[2] = t2;
    insertCode(code);
  }
  // Term -> Factor
  if (!strcmp(node->child[0]->name, "Factor")) {
    rFactor(node->child[0], place);
  }
}

// Factor      : Identifier
//             | INTEGER_VAL
//             | SL_PAREN Expr SR_PAREN
void rFactor(Node *node, Operand &place) {
  if (node == nullptr) {
    return;
  }
  // Factor -> Identifier
  if (!strcmp(node->child[0]->name, "Identifier")) {
    FieldList f = allsearch(node->child[0]->child[0]->yytext, 0);
    if (f->type->u.basic == INT_TYPE) {
      place->kind = Operand_::VARIABLE_OP;

      strcpy(place->u.value, f->name);
    }
    if (f->type->kind == Type_::ARRAY) {
      place->kind = Operand_::QU_ADDR_OP;
      strcpy(place->u.value, f->name);
    }
  }
  // Factor -> INTEGER_VAL
  if (!strcmp(node->child[0]->name, "INTEGER_VAL")) {
    // Operand op = new_constant(atoi(node->child[0]->yytext));
    // place = op;
    InterCode intIR = (InterCode)malloc(sizeof(InterCode_));
    intIR->kind = InterCode_::ASSIGN_IR;
    Operand intOp = (Operand)malloc(sizeof(Operand_));
    intOp->kind = Operand_::CONSTANT_OP;
    strcpy(intOp->u.value, node->child[0]->yytext);
    intIR->operands[1] = intOp;
    place->kind = Operand_::TEMPVAR_OP;
    place->u.var_no = tnum++;
    intIR->operands[0] = place;
    insertCode(intIR);
  }
  // Factor -> SL_PAREN Expr SR_PAREN
  if (!strcmp(node->child[0]->name, "SL_PAREN") &&
      !strcmp(node->child[1]->name, "Expr") &&
      !strcmp(node->child[2]->name, "SR_PAREN")) {
    rExpr(node->child[1], place);
  }
}

// Identifier  : IDENTIFIER SL_PAREN INdex_Index SR_PAREN
//              | IDENTIFIER
// AssignStm   : Identifier ASSIGN Expr
void rAssignStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  FieldList f = allsearch(node->child[0]->child[0]->yytext, 0);
  // INT
  if (f->type->u.basic == INT_TYPE) {
    Operand left = (Operand)malloc(sizeof(Operand_));
    left->kind = Operand_::VARIABLE_OP;
    strcpy(left->u.value, f->name);
    Operand right = new_temp();
    rExpr(node->child[2], right);
    InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
    code2->kind = InterCode_::ASSIGN_IR;
    code2->operands[0] = left;
    code2->operands[1] = right;
    insertCode(code2);
    // printCode("stdout");
    // printf("debug: %s\n", node->child[0]->child[0]->yytext);
  }
  // Array
  if (f->type->kind == Type_::ARRAY) {
    // left
    Operand left = (Operand)malloc(sizeof(Operand_));
    left->kind = Operand_::VARIABLE_OP;
    strcpy(left->u.value, f->name);
    Operand t1 = new_temp();
    Operand t2 = new_temp();
    Operand t3 = new_temp();
    rExpr(node->child[0]->child[0], t1);
    rExpr(node->child[0]->child[2], t2);
    FieldList f = allsearch(node->child[0]->child[0]->yytext, 0);
    int size = getSpace(f->type);
    InterCode code3 = (InterCode)malloc(sizeof(InterCode_));
    code3->kind = InterCode_::STAR_IR;
    code3->operands[0] = t3;
    code3->operands[1] = t2;
    code3->operands[2] = new_constant(size);
    insertCode(code3);
    Operand t4 = new_temp();
    InterCode code4 = (InterCode)malloc(sizeof(InterCode_));
    code4->kind = InterCode_::PLUS_IR;
    code4->operands[0] = t4;
    code4->operands[1] = t1;
    code4->operands[2] = t3;
    left->kind = Operand_::ADDR_OP;
    left->u.var_no = t4->u.var_no;
    insertCode(code4);

    // right
    Operand right = new_temp();
    rExpr(node->child[2], right);

    InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
    code2->kind = InterCode_::ASSIGN_IR;
    code2->operands[0] = left;
    code2->operands[1] = right;
    insertCode(code2);
  }
}

// ComplexStm    : _BEGIN_ ComStates END
void rComplexStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "_BEGIN_") &&
      !strcmp(node->child[1]->name, "ComStates") &&
      !strcmp(node->child[2]->name, "END")) {
    scope_enter();
    rComStates(node->child[1]);
    scope_exit();
  }
}

// ComStates    : ComStates Statements SEMI
//              | Statements SEMI
void rComStates(Node *node) {
  if (node == nullptr) {
    return;
  }
  // ComStates -> Statements SEMI
  if (node->childNum == 2 && node->child[0] != nullptr &&
      node->child[1] != nullptr &&
      !strcmp(node->child[0]->name, "Statements") &&
      !strcmp(node->child[1]->name, "SEMI")) {
    rStatements(node->child[0]);
  }
  // ComStates -> ComStates  Statements SEMI
  else if (node->childNum == 3 && node->child[0] != nullptr &&
           node->child[1] != nullptr && node->child[2] != nullptr &&
           !strcmp(node->child[0]->name, "ComStates") &&
           !strcmp(node->child[1]->name, "Statements") &&
           !strcmp(node->child[2]->name, "SEMI")) {
    rComStates(node->child[0]);
    rStatements(node->child[1]);
  }
}

// Condition   : Expr CMP Expr
//             | ODD Expr
void rCondition(Node *node, Operand label_true, Operand label_false) {
  if (node == nullptr) {
    return;
  }
  // Condition -> Expr CMP Expr
  if (!strcmp(node->child[0]->name, "Expr") &&
      !strcmp(node->child[1]->name, "CMP") &&
      !strcmp(node->child[2]->name, "Expr")) {
    Operand t1 = new_temp();
    Operand t2 = new_temp();
    rExpr(node->child[0], t1);
    rExpr(node->child[2], t2);
    char *op = node->child[1]->child[0]->yytext;
    InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
    code1->kind = InterCode_::IF_GOTO_IR;
    code1->operands[0] = t1;
    code1->operands[1] = t2;
    code1->operands[2] = label_true;
    strcpy(code1->relop, op);
    insertCode(code1);

    InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
    code2->kind = InterCode_::GOTO_IR;
    code2->operands[0] = label_false;
    insertCode(code2);
  }
  // Condition -> ODD Expr
  if (!strcmp(node->child[0]->name, "ODD") &&
      !strcmp(node->child[1]->name, "Expr")) {
    Operand t1 = new_temp();
    Operand t2 = new_constant(2);
    rExpr(node->child[1], t1);
    Operand t3 = new_temp();
    InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
    code1->kind = InterCode_::MOD_IR;
    code1->operands[0] = t3;
    code1->operands[1] = t1;
    code1->operands[2] = t2;
    insertCode(code1);

    InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
    code2->kind = InterCode_::IF_GOTO_IR;
    code2->operands[0] = t3;
    code2->operands[1] = new_constant(0);
    code2->operands[2] = label_true;
    strcpy(code2->relop, "==");
    insertCode(code2);

    InterCode code3 = (InterCode)malloc(sizeof(InterCode_));
    code3->kind = InterCode_::GOTO_IR;
    code3->operands[0] = label_false;
    insertCode(code3);

    // printCode("stdout");
  }
}

// CondiStm    : IF Condition THEN Statements %prec LOWER_THAN_ELSE
//             | IF Condition THEN Statements ELSE Statements
void rCondiStm(Node *node) {
  if (node == nullptr) {
    return;
  }
  // CondiStm -> IF Condition THEN Statements
  if (node->child[0] != nullptr && node->child[1] != nullptr &&
      node->child[2] != nullptr && node->child[3] != nullptr &&
      !strcmp(node->child[0]->name, "IF") &&
      !strcmp(node->child[1]->name, "Condition") &&
      !strcmp(node->child[2]->name, "THEN") &&
      !strcmp(node->child[3]->name, "Statements")) {
    Operand label1 = new_label();
    Operand label2 = new_label();
    rCondition(node->child[1], label1, label2);

    InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
    code1->kind = InterCode_::LABEL_IR;
    code1->operands[0] = label1;
    insertCode(code1);
    rStatements(node->child[3]);

    InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
    code2->kind = InterCode_::LABEL_IR;
    code2->operands[0] = label2;
    insertCode(code2);
  }
  // CondiStm -> IF Condition THEN Statements ELSE Statements
  if (node->child[0] != nullptr && node->child[1] != nullptr &&
      node->child[2] != nullptr && node->child[3] != nullptr &&
      node->child[4] != nullptr && node->child[5] != nullptr &&
      !strcmp(node->child[0]->name, "IF") &&
      !strcmp(node->child[1]->name, "Condition") &&
      !strcmp(node->child[2]->name, "THEN") &&
      !strcmp(node->child[3]->name, "Statements") &&
      !strcmp(node->child[4]->name, "ELSE") &&
      !strcmp(node->child[5]->name, "Statements")) {
    Operand label1 = new_label();
    Operand label2 = new_label();
    Operand label3 = new_label();
    rCondition(node->child[1], label1, label2);
    InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
    code1->kind = InterCode_::LABEL_IR;
    code1->operands[0] = label1;
    insertCode(code1);
    rStatements(node->child[3]);
    // goto label3
    InterCode code2 = (InterCode)malloc(sizeof(InterCode_));
    code2->kind = InterCode_::GOTO_IR;
    code2->operands[0] = label3;
    insertCode(code2);
    // label2
    InterCode code3 = (InterCode)malloc(sizeof(InterCode_));
    code3->kind = InterCode_::LABEL_IR;
    code3->operands[0] = label2;
    insertCode(code3);
    rStatements(node->child[5]);
    // label3
    InterCode code4 = (InterCode)malloc(sizeof(InterCode_));
    code4->kind = InterCode_::LABEL_IR;
    code4->operands[0] = label3;
    insertCode(code4);
  }
}

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

// CallS       : CALL IDENTIFIER
void rCallS(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "CALL") &&
      !strcmp(node->child[1]->name, "IDENTIFIER")) {
    Operand op = (Operand)malloc(sizeof(Operand_));
    op->kind = Operand_::FUNCTION_OP;
    strcpy(op->u.value, node->child[1]->yytext);
    InterCode ir = (InterCode)malloc(sizeof(InterCode_));
    ir->kind = InterCode_::CALL_IR;
    ir->operands[1] = op;
    insertCode(ir);
  }
}

// ReadS       : READ SL_PAREN Rcontent SR_PAREN
void rReadS(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "READ") &&
      !strcmp(node->child[1]->name, "SL_PAREN") &&
      !strcmp(node->child[2]->name, "Rcontent") &&
      !strcmp(node->child[3]->name, "SR_PAREN")) {
    rRcontent(node->child[2]);
  }
}

// Rcontent     : Rcontent COMMA RconObj
//              | RconObj
void rRcontent(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Rcontent") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "RconObj")) {
    rRcontent(node->child[0]);
    rRconObj(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "RconObj")) {
    rRconObj(node->child[0]);
  }
}

// RconObj      : IDENTIFIER
void rRconObj(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "IDENTIFIER")) {
    Operand op = (Operand)malloc(sizeof(Operand_));
    op->kind = Operand_::VARIABLE_OP;
    strcpy(op->u.value, node->child[0]->yytext);
    InterCode ir = (InterCode)malloc(sizeof(InterCode_));
    ir->kind = InterCode_::READ_IR;
    ir->operands[0] = op;
    insertCode(ir);
  }
}

// WriteS      : WRITE SL_PAREN Wcontent SR_PAREN
void rWriteS(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "WRITE") &&
      !strcmp(node->child[1]->name, "SL_PAREN") &&
      !strcmp(node->child[2]->name, "Wcontent") &&
      !strcmp(node->child[3]->name, "SR_PAREN")) {
    rWcontent(node->child[2]);
  }
}

// Wcontent     : Wcontent COMMA WconObj
//              | WconObj
void rWcontent(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Wcontent") &&
      !strcmp(node->child[1]->name, "COMMA") &&
      !strcmp(node->child[2]->name, "WconObj")) {
    rWcontent(node->child[0]);
    rWconObj(node->child[2]);
  } else if (!strcmp(node->child[0]->name, "WconObj")) {
    rWconObj(node->child[0]);
  }
}

// WconObj     : Expr
void rWconObj(Node *node) {
  if (node == nullptr) {
    return;
  }
  if (!strcmp(node->child[0]->name, "Expr")) {
    Operand t1 = new_temp();
    rExpr(node->child[0], t1);
    InterCode ir = (InterCode)malloc(sizeof(InterCode_));
    ir->kind = InterCode_::WRITE_IR;
    ir->operands[0] = t1;
    insertCode(ir);
  }
}