#ifndef __IRER_H__
#define __IRER_H__
#include "main.h"
#include "semer.h"
#include "stdbool.h"
#include <iostream>

using Operand = struct Operand_ *;
extern struct Operand_ { // Operand
  enum {
    VARIABLE_OP,
    TEMPVAR_OP,
    CONSTANT_OP,
    ADDR_OP //*
    ,
    QU_ADDR_OP // & ARRAY
    ,
    LABEL_OP,
    FUNCTION_OP
  } kind;
  union {
    int var_no;     // temp
    int label_no;   // label
    char value[32]; // value
  } u;
  // int tempint;
  Type type;
} Operand_;

using InterCode = struct InterCode_ *;
extern struct InterCode_ {
  enum {
    LABEL_IR,
    FUNCTION_IR,
    ASSIGN_IR,
    PLUS_IR,
    MINUS_IR,
    STAR_IR,
    DIV_IR,
    ADDR_IR2, // x := &y
    ADDR_IR3,
    ADDR_VALUE_IR, // x := *y
    MEMORY_IR,     // *x := y
    GOTO_IR,
    IF_GOTO_IR,
    RETURN_IR,
    DEC_IR,
    ARG_IR,
    CALL_IR,
    PARAM_IR,
    READ_IR,
    WRITE_IR,
    MOD_IR,
    DEBUG_IR
  } kind;
  Operand operands[3];
  int size;
  char relop[32];
} InterCode_;

void initIRList();
void insertCode(InterCode ir);
void printCode(char *filename);
void repr(Operand op, FILE *file);
void deletelastCode();
void insertdebug(char *info);

FieldList allsearch(char *name,
                    int flag // flag=1:function  flag=0:same as semer.cpp:search
);

int getSpace(Type type);
Operand new_temp();
Operand new_label();
Operand new_constant(int i);

// tree
void rprogram(Node *root);
void rSubPro(Node *node);
void rDeclarePart(Node *node);
void rConstDec(Node *node);
void rConstDef(Node *node);
void rCDefine(Node *node);
void rVarDec(Node *node);
void rVarObj(Node *node);
void rIdentiDef(Node *node);
void rIdentiObject(Node *node);
void rArray(Node *id, Node *node);
void rArrayIndex(Node *id, Node *node1, Node *node2);
void rProDec(Node *node);
void rProceHead(Node *node);
void rStatements(Node *node);
void rIdentifier(Node *node);
void rINdex_Index(Node *node);
void rAssignStm(Node *node);
void rComplexStm(Node *node);
void rComStates(Node *node);
void rCondition(Node *node);
void rCondiStm(Node *node);
void rExpr(Node *node, Operand &place);
void rTerm(Node *node, Operand &place);
void rFactor(Node *node, Operand &place);
void rWhileStm(Node *node);
void rCallS(Node *node);
void rReadS(Node *node);
void rRcontent(Node *node);
void rRconObj(Node *node);
void rWconObj(Node *node);
void rWriteS(Node *node);
void rWcontent(Node *node);
void rWconObj(Node *node);

#endif