#include "../head/main.h"

Node *createNode(const char *name, const char *text) {
  Node *p = (Node *)malloc(sizeof(Node));
  strcpy(p->name, name);
  strcpy(p->yytext, text);
  p->lineRow = row;
  for (int i = 0; i < 10; i++) {
    p->child[i] = nullptr;
  }
  p->childNum = 0;
  return p;
}

void addNode(int childsum, Node *parent, ...) {
  va_list ap;
  va_start(ap, parent);
  parent->childNum = childsum;
  for (int i = 0; i < childsum; i++) {
    parent->child[i] = va_arg(ap, Node *);
  }
  parent->lineRow = parent->child[0]->lineRow;
  va_end(ap);
}

void printTree(Node *root, int number) {
  if (root == nullptr) {
    return;
  }
  // for layer Blank!
  for (int i = 0; i < number; i++) {
    printf(" ");
  }

  if (root->childNum != 0) {
    printf("%s (%d)\n", root->name, root->lineRow);
    for (int i = 0; i < root->childNum; i++) {
      printTree(root->child[i], number + 2);
    }
  }
  // no need to print rowNum
  else {
    if (strcmp("IDENTIFIER", root->name) == 0) {
      printf("%s: %s\n", root->name, root->yytext);
    } else if (strcmp("INTEGER_VAL", root->name) == 0) {
      printf("%s: %d\n", root->name, atoi(root->yytext));
    } else {
      printf("%s\n", root->name);
    }
  }
}