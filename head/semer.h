#ifndef SEMER_H
#define SEMER_H

#include "main.h"
#include <cstdio>
#include <cstring>
#include <iostream>

// declar
#define DECLA 1
// define
#define DEFIN 2
#define HASH_SIZE 0x3fff

#define INT_TYPE 1

using Type = struct Type_ *;
using FieldList = struct FieldList_ *;
using scope = struct scope_;

extern struct Type_ {
  enum { BASIC, ARRAY, FUNCTION } kind; // type kind
  union {
    // basic type
    int basic;
    // type and size
    struct {
      // Type elem;
      int size;
    } array;
    // Function(it is Procedure in PL0)
    struct {
      int state;  // just state:)
      int lineno; // row
    } function;
  } u;
} Type_;

// scope,conected with parent and update itself with all parents!
extern struct scope_ {
  int id;
  int parent_id; // outside scope
  int oNum;      // number of all outside scope and self scope
  int o[50];     // outsides's id,use it with oNum!
} scope_;

// FieldList = variable
extern struct FieldList_ {
  char *name;     // name of field
  Type type;      // type of field
  bool is_const;  // check const
  int value;      // value for variable
  FieldList tail; // next field
  int scope_id;   // scope
} FieldList_;

// operation of field
void scope_enter();
void scope_exit();

// Symbol Table
// hash function,0x3fff defines the size of symbol table
unsigned int hash_pjw(const char *name);
// Init
void initHashtable();
// insert f into hashTable
int insert(FieldList f);
// search will look for outer layers to determine if it is undefined for use, so
// it must start from the current layer
FieldList search(const char *name, int flag);
// ifexist will look for the same layer to determine if it is redefined
FieldList ifexist(const char *name, int id);
// Check
int TypeEqual(Type type1, Type type2);
// just Print the symbol table
void printSymbol();

// AST
void program(Node *root);
void SubPro(Node *node);
void DeclarePart(Node *node);
void ConstDec(Node *node);
void ConstDef(Node *node);
void CDefine(Node *node);
void VarDec(Node *node);
void VarObj(Node *node);
void IdentiDef(Node *node);
void IdentiObject(Node *node);
void Array(Node *id, Node *node);
void ArrayIndex(Node *id, Node *node1, Node *node2);
void ProDec(Node *node);
void ProceHead(Node *node);
void Statements(Node *node);
void Identifier(Node *node);
void INdex_Index(Node *node);
void AssignStm(Node *node);
void ComplexStm(Node *node);
void ComStates(Node *node);
void Condition(Node *node);
void CondiStm(Node *node);
void Expr(Node *node);
void Term(Node *node);
void Factor(Node *node);
void WhileStm(Node *node);
void CallS(Node *node);
void ReadS(Node *node);
void Rcontent(Node *node);
void RconObj(Node *node);
void WconObj(Node *node);
void WriteS(Node *node);
void Wcontent(Node *node);
void WconObj(Node *node);
#endif // SEMER_H