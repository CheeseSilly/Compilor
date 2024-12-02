#ifndef MAIN_H
#define MAIN_H

/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */

#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdio.h> //printf&FILE

extern int row;
extern int column;
struct Node {
  char name[32];
  char yytext[32];
  struct Node *child[10];
  int childNum;
  int lineRow;
};

using Node = struct Node;

Node *createNode(const char *name, const char *text);

void addNode(int childsum, Node *parent, ...);

void printTree(Node *root, int number);
#endif // MAIN_H