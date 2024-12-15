#include "../head//asmer.h"

extern int IRsize;
extern InterCode *IRList;

VarList *varListReg; // Reg Table
VarList *varListMem; // Mem Table
int offset;
Register *regList[32];
int last;

const char *REG_NAME[32] = {
    "$0",  "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2",
    "$t3", "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5",
    "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"};

void insertIndexCode(int index, InterCode ir) {
  // move for the new index
  insertCode(IRList[IRsize - 1]);
  for (int i = IRsize - 2; i > index; i--) {
    IRList[i] = IRList[i - 1];
  }
  IRList[index] = ir;
}

int transition(Operand op, int index, int opth) {
  if (op == nullptr) {
    printf("debug op == NULL");
    return 0;
  }
  switch (op->kind) {
  case Operand_::VARIABLE_OP: // var name
    if (op->u.value != nullptr) {
      sprintf(op->name, "%s", op->u.value);
    }
    break;
  case Operand_::TEMPVAR_OP: // temp1
    sprintf(op->name, "temp%d", op->u.var_no);
    break;
  case Operand_::CONSTANT_OP: // const
    op->constant = atoi(op->u.value);
    break;
  case Operand_::ADDR_OP: //*temp1
    sprintf(op->name, "temp%d", op->u.var_no);
    if (opth == 0) // 左值 *x = y relop z 改为  t = y relop z  // *x = t
    {
      if (IRList[index]->kind == InterCode_::PLUS_IR ||
          IRList[index]->kind == InterCode_::MINUS_IR ||
          IRList[index]->kind == InterCode_::STAR_IR ||
          IRList[index]->kind == InterCode_::DIV_IR ||
          IRList[index]->kind == InterCode_::MOD_IR) {

        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t=y relop z
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = IRList[index]->kind;
        code1->operands[0] = t1;
        code1->operands[1] = IRList[index]->operands[1];
        code1->operands[2] = IRList[index]->operands[2];
        strcpy(code1->relop, IRList[index]->relop);
        // 改为*x = t
        IRList[index]->kind = InterCode_::ST_EQ_IR;
        op->kind = Operand_::TEMPVAR_OP;
        IRList[index]->operands[0] = op;
        IRList[index]->operands[1] = t1;
        IRList[index]->operands[2] = nullptr;
        insertIndexCode(index, code1);
        return 1;
      } else if (IRList[index]->kind ==
                 InterCode_::ASSIGN_IR) // *x = y 注意 *x = *y的可能
      {

        if (IRList[index]->operands[1]->kind == Operand_::ADDR_OP) {
          Operand t1 = new_temp();
          sprintf(t1->name, "temp%d", t1->u.var_no);
          // t = *y
          InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
          code1->kind = InterCode_::EQ_ST_IR;
          code1->operands[0] = t1;
          op->kind = Operand_::TEMPVAR_OP;
          IRList[index]->operands[1]->kind = Operand_::TEMPVAR_OP;
          sprintf(IRList[index]->operands[1]->name, "temp%d",
                  IRList[index]->operands[1]->u.var_no);
          code1->operands[1] = IRList[index]->operands[1];
          // *x = t
          IRList[index]->operands[1] = t1;
          IRList[index]->kind = InterCode_::ST_EQ_IR;
          insertIndexCode(index, code1);
          return 1; // 新插入一个 index+1
        } else {
          op->kind = Operand_::TEMPVAR_OP;
          IRList[index]->kind = InterCode_::ST_EQ_IR;
        }
      } else if (IRList[index]->kind == InterCode_::WRITE_IR) // t = *x WRITE t
      {
        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t=*x
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = InterCode_::EQ_ST_IR;
        code1->operands[0] = t1;
        op->kind = Operand_::TEMPVAR_OP;
        code1->operands[1] = op;
        // WRITE t
        IRList[index]->operands[0] = t1;
        insertIndexCode(index, code1);
        return 1;
      } else if (IRList[index]->kind ==
                 InterCode_::IF_GOTO_IR) // if *x > y goto ...
      {
        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t=*x
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = InterCode_::EQ_ST_IR;
        code1->operands[0] = t1;
        op->kind = Operand_::TEMPVAR_OP;
        code1->operands[1] = op;
        // if t > y goto ...
        IRList[index]->operands[0] = t1;
        insertIndexCode(index, code1);
        return 1;
      } else {
        printf("debug ADDR_OP2 %d", index);
      }
    } else if (opth == 1) // 右值 x = *y relop z
    {
      if (IRList[index]->kind == InterCode_::PLUS_IR ||
          IRList[index]->kind == InterCode_::MINUS_IR ||
          IRList[index]->kind == InterCode_::STAR_IR ||
          IRList[index]->kind == InterCode_::DIV_IR ||
          IRList[index]->kind == InterCode_::MOD_IR) {
        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t = *y
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = InterCode_::EQ_ST_IR;
        code1->operands[0] = t1;
        op->kind = Operand_::TEMPVAR_OP;
        code1->operands[1] = op;
        code1->operands[2] = nullptr;
        // x = t relop z
        IRList[index]->operands[1] = t1;
        insertIndexCode(index, code1);
        return 1; // 新插入一个 index+1
      } else if (IRList[index]->kind ==
                 InterCode_::ASSIGN_IR) // x = *y  //*x = *y的可能在前面处理过了
      {
        op->kind = Operand_::TEMPVAR_OP;
        IRList[index]->kind = InterCode_::EQ_ST_IR;
      } else if (IRList[index]->kind ==
                 InterCode_::IF_GOTO_IR) // if x > *y goto...
      {
        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t=*y
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = InterCode_::EQ_ST_IR;
        code1->operands[0] = t1;
        op->kind = Operand_::TEMPVAR_OP;
        code1->operands[1] = op;
        // if t > y goto ...
        IRList[index]->operands[1] = t1;
        insertIndexCode(index, code1);
        return 1;

      } else {
        printf("debug ADDR_OP3");
      }
    } else if (opth == 2) // 右值 x = y relop *z
    {
      if (IRList[index]->kind == InterCode_::PLUS_IR ||
          IRList[index]->kind == InterCode_::MINUS_IR ||
          IRList[index]->kind == InterCode_::STAR_IR ||
          IRList[index]->kind == InterCode_::DIV_IR ||
          IRList[index]->kind == InterCode_::MOD_IR) {
        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t = *z
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = InterCode_::EQ_ST_IR;
        code1->operands[0] = t1;
        op->kind = Operand_::TEMPVAR_OP;
        code1->operands[1] = op;
        // x = y relop t
        IRList[index]->operands[2] = t1;
        insertIndexCode(index, code1);
        return 1; // 新插入一个 index+1
      } else {
        printf("debug ADDR_OP4:%d %d", IRList[index]->kind, index);
      }
    }
    break;
  case Operand_::QU_ADDR_OP: //&变量名
    sprintf(op->name, "%s", op->u.value);
    if (IRList[index]->kind == InterCode_::PLUS_IR) {
      if (opth == 1) // x = &y + z
      {
        Operand t1 = new_temp();
        sprintf(t1->name, "temp%d", t1->u.var_no);
        // t = &y
        InterCode code1 = (InterCode)malloc(sizeof(InterCode_));
        code1->kind = InterCode_::QU_IR;
        code1->operands[0] = t1;
        op->kind = Operand_::VARIABLE_OP;
        code1->operands[1] = op;
        // x = t + z
        IRList[index]->operands[1] = t1;
        insertIndexCode(index, code1);
        return 1; // 新插入一个 index+1
      } else {
        printf("debug ADDR_OP5");
      }
    } else if (IRList[index]->kind == InterCode_::ARG_IR) {
      // do-nothing
    } else {
      printf("debug ADDR_OP6");
    }
    break;
  case Operand_::LABEL_OP: // label1
    sprintf(op->name, "label%d", op->u.label_no);
    break;
  case Operand_::FUNCTION_OP: // 函数名
    sprintf(op->name, "%s", op->u.value);
    break;
  }
  return 0;
}

void writeCode(char *filename) {
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
  printAssemblyCode(fp);
  fclose(fp);
  return;
}

void printAssemblyCode(FILE *fp) {

  fprintf(fp, ".data\n");
  fprintf(fp, "_prompt: .asciiz \"Enter an integer:\"\n");
  fprintf(fp, "_ret: .asciiz \"\\n\"\n");
  fprintf(fp, ".globl main\n");
  // read
  fprintf(fp, ".text\n");
  fprintf(fp, "read:\n");
  fprintf(fp, "  li $v0, 4\n");
  fprintf(fp, "  la $a0, _prompt\n");
  fprintf(fp, "  syscall\n");
  fprintf(fp, "  li $v0, 5\n");
  fprintf(fp, "  syscall\n");
  fprintf(fp, "  jr $ra\n\n");
  // write
  fprintf(fp, "write:\n");
  fprintf(fp, "  li $v0, 1\n");
  fprintf(fp, "  syscall\n");
  fprintf(fp, "  li $v0, 4\n");
  fprintf(fp, "  la $a0, _ret\n");
  fprintf(fp, "  syscall\n");
  fprintf(fp, "  move $v0, $0\n");
  fprintf(fp, "  jr $ra\n\n");

  // Reg Init
  for (int i = 0; i < 32; ++i) {
    regList[i] = (Register *)malloc(sizeof(Register));
    regList[i]->isEmpty = 1;
    regList[i]->name = REG_NAME[i];
  }
  regList[0]->isEmpty = 0;
  last = 0;
  // 变量表初始化
  VarList *p1 = (VarList *)malloc(sizeof(VarList));
  p1->head = nullptr;
  p1->tail = nullptr;
  varListReg = p1;
  VarList *p2 = (VarList *)malloc(sizeof(VarList));
  p2->head = nullptr;
  p2->tail = nullptr;
  varListMem = p2;
  offset = 0;

  for (int i = 0; i < IRsize; i++) {
    InterCode ir = IRList[i];
    if (ir == nullptr) {
      continue;
    }
    switch (ir->kind) {
    case InterCode_::LABEL_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::FUNCTION_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::ASSIGN_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      break;
    case InterCode_::PLUS_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      i += transition(ir->operands[2], i, 2);
      break;
    case InterCode_::MINUS_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      i += transition(ir->operands[2], i, 2);
      break;
    case InterCode_::STAR_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      i += transition(ir->operands[2], i, 2);
      break;
    case InterCode_::DIV_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      i += transition(ir->operands[2], i, 2);
      break;

    case InterCode_::GOTO_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::IF_GOTO_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      i += transition(ir->operands[2], i, 2);
      break;
    case InterCode_::RETURN_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::DEC_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::ARG_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::CALL_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      break;
    case InterCode_::PARAM_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::READ_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::WRITE_IR:
      i += transition(ir->operands[0], i, 0);
      break;
    case InterCode_::MOD_IR:
      i += transition(ir->operands[0], i, 0);
      i += transition(ir->operands[1], i, 1);
      i += transition(ir->operands[2], i, 2);
      break;
    }
  }

  for (int i = 0; i < IRsize; i++)
    transToAssem(fp, i);
}

void transToAssem(FILE *fp, int index) {
  InterCode interCode = IRList[index];
  int kind = interCode->kind;
  if (kind == InterCode_::LABEL_IR) {
    fprintf(fp, "%s:\n", interCode->operands[0]->name);
  } else if (kind == InterCode_::FUNCTION_IR) {
    fprintf(fp, "\n%s:\n", interCode->operands[0]->name);
    fprintf(fp, "  move $gp, $sp\n");
    {
      // flash reg
      for (int i = 1; i < 32; ++i)
        regList[i]->isEmpty = 1;
      // flash varList
      clearVarList(varListReg);
      clearVarList(varListMem);
      offset = 0;
    }

    FieldList field = search(interCode->operands[0]->name, 1); // func
    int paramNum = 0;

    for (int i = index + 1; i < IRsize; i++) // param
    {
      addVarible(varListMem, (paramNum++) * 4 + 8, IRList[i]->operands[0]);
    }

    for (int i = index + 1;
         i < IRsize && IRList[i]->kind != InterCode_::FUNCTION_IR;
         i++) // before the next func
    {
      InterCode temp = IRList[i];
      Operand op = nullptr;
      switch (temp->kind) {
      case InterCode_::READ_IR:
      case InterCode_::ASSIGN_IR:
      case InterCode_::CALL_IR:
      case InterCode_::PLUS_IR:
      case InterCode_::MINUS_IR:
      case InterCode_::STAR_IR:
      case InterCode_::DIV_IR:
      case InterCode_::MOD_IR:
      case InterCode_::DEC_IR:
        op = temp->operands[0];
        break;
      case InterCode_::QU_IR:
      case InterCode_::EQ_ST_IR:
        op = temp->operands[0];
        break;
      default:
        op = nullptr;
        break;
      }
      if (op != nullptr) {
        if (temp->kind == InterCode_::DEC_IR) {
          offset -= temp->size + 4;
          fprintf(fp, "  addi $sp, $sp, -%d\n", temp->size);
          fprintf(fp, "  sw $sp, -4($sp)\n");
          fprintf(fp, "  addi $sp, $sp, -4\n");
          addVarible(varListMem, offset, op);
        } else {
          fprintf(fp, "  addi $sp, $sp, -4\n");
          offset -= 4;
          addVarible(varListMem, offset, op);
        }
      }
    }
  } else if (kind == InterCode_::READ_IR) {
    fprintf(fp, "  addi $sp, $sp, -4\n");
    fprintf(fp, "  sw $ra, 0($sp)\n");
    fprintf(fp, "  jal read\n");
    fprintf(fp, "  lw $ra, 0($sp)\n");
    fprintf(fp, "  addi $sp, $sp, 4\n");
    int reg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  move %s, $v0\n", regList[reg]->name);
    saveToStack(fp, reg, interCode->operands[0]);
  } else if (kind == InterCode_::WRITE_IR) {
    fprintf(fp, "  addi $sp, $sp, -8\n");
    fprintf(fp, "  sw $a0, 0($sp)\n");
    fprintf(fp, "  sw $ra, 4($sp)\n");
    int reg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  move $a0, %s\n", regList[reg]->name);
    fprintf(fp, "  jal write\n");
    fprintf(fp, "  lw $a0, 0($sp)\n");
    fprintf(fp, "  lw $ra, 4($sp)\n");
    fprintf(fp, "  addi $sp, $sp, 8\n");
  }

  else if (kind == InterCode_::ASSIGN_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    // printf("leftReg:%d\n", leftReg);
    if (interCode->operands[1]->kind == Operand_::CONSTANT_OP) {
      fprintf(fp, "  li %s, %s\n", regList[leftReg]->name,
              interCode->operands[1]->u.value);
    } else {
      // printf("%s\n", regList[saveToReg(fp, interCode->operands[1])]->name);
      fprintf(fp, "  move %s, %s\n", regList[leftReg]->name,
              regList[saveToReg(fp, interCode->operands[1])]->name);
    }
    addVarible(varListMem, leftReg, interCode->operands[0]);
    saveToStack(fp, leftReg, interCode->operands[0]);
  }

  else if (kind == InterCode_::PLUS_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    int c1 = atoi(interCode->operands[1]->u.value);
    int c2 = atoi(interCode->operands[2]->u.value);
    if (interCode->operands[1]->kind == Operand_::CONSTANT_OP &&
        interCode->operands[2]->kind == Operand_::CONSTANT_OP)
      fprintf(fp, "  li %s, %d\n", regList[leftReg]->name, c1 + c2);
    else if (interCode->operands[2]->kind == Operand_::CONSTANT_OP)
      fprintf(fp, "  addi %s, %s, %d\n", regList[leftReg]->name,
              regList[saveToReg(fp, interCode->operands[1])]->name, c2);
    else if (interCode->operands[1]->kind == Operand_::CONSTANT_OP)
      fprintf(fp, "  addi %s, %s, %d\n", regList[leftReg]->name,
              regList[saveToReg(fp, interCode->operands[2])]->name, c1);
    else
      fprintf(fp, "  add %s, %s, %s\n", regList[leftReg]->name,
              regList[saveToReg(fp, interCode->operands[1])]->name,
              regList[saveToReg(fp, interCode->operands[2])]->name);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::MINUS_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    int c1 = atoi(interCode->operands[1]->u.value);
    int c2 = atoi(interCode->operands[2]->u.value);
    if (interCode->operands[1]->kind == Operand_::CONSTANT_OP &&
        interCode->operands[2]->kind == Operand_::CONSTANT_OP)
      fprintf(fp, "  li %s, %d\n", regList[leftReg]->name, c1 - c2);
    else if (interCode->operands[1]->kind != Operand_::CONSTANT_OP &&
             interCode->operands[2]->kind == Operand_::CONSTANT_OP)
      fprintf(fp, "  addi %s, %s, %d\n", regList[leftReg]->name,
              regList[saveToReg(fp, interCode->operands[1])]->name, -c2);
    else
      fprintf(fp, "  sub %s, %s, %s\n", regList[leftReg]->name,
              regList[saveToReg(fp, interCode->operands[1])]->name,
              regList[saveToReg(fp, interCode->operands[2])]->name);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::STAR_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  mul %s, %s, %s\n", regList[leftReg]->name,
            regList[saveToReg(fp, interCode->operands[1])]->name,
            regList[saveToReg(fp, interCode->operands[2])]->name);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::DIV_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  div %s, %s\n",
            regList[saveToReg(fp, interCode->operands[1])]->name,
            regList[saveToReg(fp, interCode->operands[2])]->name);
    fprintf(fp, "  mflo %s\n", regList[leftReg]->name);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::MOD_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  div %s, %s\n",
            regList[saveToReg(fp, interCode->operands[1])]->name,
            regList[saveToReg(fp, interCode->operands[2])]->name);
    fprintf(fp, "  mfhi %s\n", regList[leftReg]->name);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::QU_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    Varible *temp;
    for (temp = varListMem->head;
         strcmp(temp->op->name, interCode->operands[1]->name) != 0;
         temp = temp->next)
      ;
    fprintf(fp, "  lw %s, %d($gp)\n", regList[leftReg]->name, temp->reg);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::EQ_ST_IR) {

    int leftReg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  lw %s, 0(%s)\n", regList[leftReg]->name,
            regList[saveToReg(fp, interCode->operands[1])]->name);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::ST_EQ_IR) {
    fprintf(fp, "  sw %s, 0(%s)\n",
            regList[saveToReg(fp, interCode->operands[1])]->name,
            regList[saveToReg(fp, interCode->operands[0])]->name);
  } else if (kind == InterCode_::GOTO_IR) {
    fprintf(fp, "  j %s\n", interCode->operands[0]->name);
  } else if (kind == InterCode_::IF_GOTO_IR) {
    char *relop = interCode->relop;
    int leftReg = saveToReg(fp, interCode->operands[0]);
    int rightReg = saveToReg(fp, interCode->operands[1]);
    if (strcmp(relop, "==") == 0)
      fprintf(fp, "  beq ");
    else if (strcmp(relop, "!=") == 0)
      fprintf(fp, "  bne ");
    else if (strcmp(relop, ">") == 0)
      fprintf(fp, "  bgt ");
    else if (strcmp(relop, "<") == 0)
      fprintf(fp, "  blt ");
    else if (strcmp(relop, ">=") == 0)
      fprintf(fp, "  bge ");
    else if (strcmp(relop, "<=") == 0)
      fprintf(fp, "  ble ");
    fprintf(fp, "%s, %s, %s\n", regList[leftReg]->name, regList[rightReg]->name,
            interCode->operands[2]->name);
  } else if (kind == InterCode_::RETURN_IR) {
    fprintf(fp, "  move $v0, %s\n",
            regList[saveToReg(fp, interCode->operands[0])]->name);
    fprintf(fp, "  jr $ra\n");
  }

  else if (kind == InterCode_::CALL_IR) {
    int leftReg = saveToReg(fp, interCode->operands[0]);
    fprintf(fp, "  addi $sp, $sp, -72\n");
    offset -= 72;
    for (int i = T0; i <= T9; ++i)
      fprintf(fp, "  sw %s, %d($sp)\n", regList[i]->name, (i - T0) * 4);
    // int paramNum = 0;
    // int ParamNum = 0;
    // fprintf(fp, "  addi $sp, $sp, -%d\n", ParamNum * 4);
    // offset -= ParamNum * 4;
    // for (int i = index - 1; i < IRsize && paramNum < ParamNum; i--) {
    //   InterCode arg = IRList[i];
    //   if (arg->kind ==
    //       InterCode_::ARG_IR) // 有没有&是一样的？ 但是有&就不是一个变量
    //     fprintf(fp, "  sw %s, %d($sp)\n",
    //             regList[saveToReg(fp, arg->operands[0])]->name,
    //             4 * (paramNum++));
    // }
    fprintf(fp, "  addi $sp, $sp, -8\n");
    offset -= 8;
    fprintf(fp, "  sw $ra, 0($sp)\n");
    fprintf(fp, "  sw $gp, 4($sp)\n");
    fprintf(fp, "  jal %s\n", interCode->operands[1]->name);
    fprintf(fp, "  move $sp, $gp\n");
    fprintf(fp, "  lw $ra, 0($sp)\n");
    fprintf(fp, "  lw $gp, 4($sp)\n");
    fprintf(fp, "  addi $sp, $sp, 8\n");
    offset += 8;
    for (int i = T0; i <= T9; ++i)
      fprintf(fp, "  lw %s, %d($sp)\n", regList[i]->name, (i - T0) * 4);
    fprintf(fp, "  addi $sp, $sp, 72\n");
    offset += 72;
    fprintf(fp, "  move %s, $v0\n", regList[leftReg]->name);
    // addVarible(varListReg, leftReg, interCode->operands[0]);
    addVarible(varListMem, leftReg, interCode->operands[0]);
    saveToStack(fp, leftReg, interCode->operands[0]);
  } else if (kind == InterCode_::PARAM_IR) {
  } else if (kind == InterCode_::DEC_IR) {
  } else if (kind == InterCode_::ARG_IR) {
  } else {
    printf(" error ir kind !\n");
  }
}

void addVarible(VarList *varList, int reg, Operand op) {
  Varible *newVar = (Varible *)malloc(sizeof(Varible));
  newVar->reg = reg;
  newVar->op = op;
  newVar->next = nullptr;
  if (varList->head == nullptr) // 尾部追加
    varList->head = newVar;
  else
    varList->tail->next = newVar;
  varList->tail = newVar;
}
void delVarible(VarList *varList, Varible *var) {
  if (var == varList->head)
    varList->head = varList->head->next;
  else {
    Varible *temp = varList->head;
    while (temp && temp->next != var)
      temp = temp->next;
    if (varList->tail == var)
      varList->tail = temp;
    temp->next = var->next;
  }
  var->next = nullptr;
  free(var);
}
void clearVarList(VarList *varList) {
  Varible *temp = varList->head;
  while (temp) {
    Varible *p = temp;
    temp = temp->next;
    free(p);
  }
  varList->head = nullptr;
  varList->tail = nullptr;
}

void saveToStack(FILE *fp, int reg, Operand op) {
  Varible *temp;
  for (temp = varListMem->head; temp != nullptr;
       temp = temp->next) // 在内存中找到对应变量
  {
    // printf("%s\n", temp->op->name);
    if (strcmp(temp->op->name, op->name) == 0)
      break;
  }
  // if (temp == nullptr) {
  //   addVarible(varListMem, reg, op);
  //   for (temp = varListMem->head; temp != nullptr;
  //        temp = temp->next) // 在内存中找到对应变量
  //   {
  //     // printf("%s\n", temp->op->name);
  //     if (strcmp(temp->op->name, op->name) == 0)
  //       break;
  //   }
  // }
  // printf("%s\n", temp->op->name);
  fprintf(fp, "  sw %s, %d($gp)\n", regList[reg]->name, temp->reg);
}

int saveToReg(FILE *fp, Operand op) {
  if (op->kind !=
      Operand_::CONSTANT_OP) // it has been in mem if it is not a const
                             // find it in mem,and assign it to reg
  {
    int reg = assignReg(op);
    for (Varible *temp = varListMem->head; temp != nullptr;
         temp = temp->next) // 从内存中找到它
      if (strcmp(temp->op->name, op->name) == 0) {
        // printf("  lw %s, %d($gp)\n", regList[reg]->name, temp->reg);
        fprintf(fp, "  lw %s, %d($gp)\n", regList[reg]->name, temp->reg);
        return reg;
      }
    return reg;
  } else {
    if (op->constant == 0)
      return ZERO;
    int reg = assignReg(op);

    fprintf(fp, "  li %s, %d\n", regList[reg]->name, op->constant);
    return reg;
  }
}

int assignReg(Operand op) {
  for (int i = T0; i <= T9; ++i) {
    if (regList[i]->isEmpty) {
      regList[i]->isEmpty = 0;
      addVarible(varListReg, i, op);
      return i;
    }
  }
  // spill
  Varible *temp = varListReg->head;
  int reg = temp->reg;
  delVarible(varListReg, temp);
  addVarible(varListReg, reg, op);
  return reg;
}