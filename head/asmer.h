#ifndef _ASMER_H_
#define _ASMER_H_

#include "irer.h"

using Register = struct _register;
using Varible = struct varible;
using Registers = struct registers;
using VarList = struct varList;
using VarTable = struct varTable;
typedef enum reg {
  ZERO,
  AT,
  V0,
  V1,
  A0,
  A1,
  A2,
  A3,
  T0,
  T1,
  T2,
  T3,
  T4,
  T5,
  T6,
  T7,
  S0,
  S1,
  S2,
  S3,
  S4,
  S5,
  S6,
  S7,
  T8,
  T9,
  K0,
  K1,
  GP,
  SP,
  FP,
  RA,
} reg;

struct _register {
  const char *name;
  unsigned isEmpty;
}; // Register

struct varible {
  int reg;
  Operand op;
  Varible *next;
}; // variable,List

struct varList {
  Varible *head;
  Varible *tail;
}; // varList

extern VarList *varListReg; // Reg's varList Table
extern VarList *varListMem; // Mem's varList Table
extern int offset;
extern Register *regList[32];
extern int last;

void clearVarList(VarList *varList);

// add var,reg and op to varList
void addVarible(VarList *varList, int reg, Operand op);
// delete var from varList
void delVarible(VarList *varList, Varible *var);
// assign var to a reg,return the reg
int saveToReg(FILE *fp, Operand op);
// algorithm of assign reg
int assignReg(Operand op);
// 存到栈里-将寄存器内op的值写回内存里对应的变量
void saveToStack(FILE *fp, int reg, Operand op);

void printAssemblyCode(FILE *fp);
void transToAssem(FILE *fp, int index);

void writeCode(char *filename);

#endif