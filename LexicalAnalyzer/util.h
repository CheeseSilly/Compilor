/**
 * util.h: This header file contains the function declarations and global variables used in the lexical analysis program.
 * 
 * @author CheeseSilly
 * @date 2024-10-16
 */
# pragma once
//test code file
#define CODE "code.txt" //code、code1、code2
//result file
#define RESULT "result.txt"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <windows.h>

/**
 * The token array is used to receive keywords, variables, operators, and delimiters.
 * Here, the length of the variable name is limited to a maximum of 10.
 * The prog array stores the source code string length. 
 * @param token: The token array used to store keywords, variables, operators, and delimiters.
 * @param prog: The prog array stores the source code string length.
 * @param ch: The current character being processed.
 * @param arr_flag: The arr variable is used to track the array.
 * @param arr_value: The arr_value variable is used to store the array's name.
 * @param arr_num: The arr_num variable is used to store the array's index.
 * @param syn: The syn variable stores the number corresponding to each word or symbol.
 * @param p: The p variable is used to track the index of the prog array.
 * @param m: The m variable is used to track the index of the token array.
 * @param n: The n variable is used to track the index of the rwtab1 and rwtab2 arrays.
 * @param line: The line variable is used to track the current line number.
 * @param sum: The sum variable is used to store the number.
 * @param rwtab1: The rwtab1 array stores the reserved words and delimiters.
 * @param rwtab2: The rwtab2 array stores the reserved words and delimiters.
*/
char token[20];
char *prog;
char ch;
int arr_flag{0};
char arr_value[20];
int arr_num{0};
int syn, p, m = 0, n, line, sum = 0;
std::string rwtab1[10] = { "begin","if","then","else","while","do","end" };
std::string rwtab2[4] = { "const","var","procedure","call" };

/**
 * scaner(): This function is used to scan the source code and identify the keywords, variables, operators, and delimiters.
 * 
 */
void scaner();

//read the code from the file
void read();