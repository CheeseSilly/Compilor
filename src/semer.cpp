#include "../head/semer.h"

FieldList hashTable[HASH_SIZE]; // hash ,which stores "variables"
int scope_id = 0;               // id for new scope
int current_id = 0;
scope scopeTable[20];

unsigned int hash_pjw(char *name) {
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
      if (strcmp(hashTable[key]->name, f->name) == 0) {
        if (f->type->u.function.state == DEFIN) {
          hashTable[key] = f;
          return 1;
        }
      }
      key = (++key) % HASH_SIZE;
    }
  }
  return 0;
}

FieldList search(char *name,
                 int flag // flag=1:function flag=0:variable
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
          // todo:array
          return p;
        }
      }
    }
    key = (++key) % HASH_SIZE;
    p = hashTable[key];
  }
  return nullptr;
}

FieldList ifexist(char *name, int id) {
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
