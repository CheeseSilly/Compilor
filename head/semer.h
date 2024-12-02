#include <cstdio>
#include <cstring>
#include <iostream>

// declar
#define DECLA 1
// define
#define DEFIN 2
#define HASH_SIZE 0x3fff

using Type = struct Type_ *;
using FieldList = struct FieldList_ *;
using scope = struct scope_;

struct Type_ {
  enum { BASIC, ARRAY, FUNCTION } kind; // type kind
  union {
    // basic type
    int basic;
    // type and size
    struct {
      Type elem;
      int size;
    } array;
    // Function(it is Procedure in PL0)
    struct {
      FieldList params; // param
      Type funcType;    // return value
      int paramNum;     // number of param
      int state;        // just state:)
      int lineno;       // row
    } function;
  } u;
} Type_;

// scope,conected with parent and update itself with all parents!
struct scope_ {
  int id;
  int parent_id; // outside scope
  int oNum;      // number of all outside scope and self scope
  int o[20];     // outsides's id,use it with oNum!
} scope_;

// FieldList = variable
struct FieldList_ {
  char *name;     // name of field
  Type type;      // type of field
  FieldList tail; // next field
  int scope_id;   // scope
} FieldList_;

// operation of field
void scope_enter();
void scope_exit();

// Symbol Table
// hash function,0x3fff defines the size of symbol table
unsigned int hash_pjw(char *name);
// Init
void initHashtable();
// insert f into hashTable
int insert(FieldList f);
// search will look for outer layers to determine if it is undefined for use, so
// it must start from the current layer
FieldList search(char *name, int flag);
// ifexist will look for the same layer to determine if it is redefined
FieldList ifexist(char *name, int id);
// Check
int TypeEqual(Type type1, Type type2);
// just Print
void printSymbol();
