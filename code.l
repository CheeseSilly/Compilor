%option noyywrap
%option yylineno
%{
/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */
#include<stdio.h>
extern int yywarp(void);
int col=1;
void print_out(char type);
%}


digit [0-9]
letter [a-zA-Z]
identifier {letter}({letter}|{digit})*
integer {digit}{digit}*
whitespace [ ]
newline [\n]
return_ [\r]
col_8 [\t]
comment \{([^}]|\})*\}
array {identifier}\((({identifier}:{integer}|{integer}:{identifier}|{integer}:{integer}|{identifier}:{identifier})|{identifier}(([\+\-\*/])({identifier}|{integer}))*?)\)
illegal ([^a-zA-Z0-9\t(\t-4)\n>=<:\'\(\)\;\[\]\.\!\+\-\/\*\"\,]+)


%%

if|then|else|while|do|read(\(.*\))*|write(\(.*\))*|call|begin|end|const|var|procedure|odd   {print_out('K');col = col + yyleng;} /*add else*/

{whitespace} {
	//print_out('T');
col = col + yyleng;
} /*space*/
{newline} { col = 1;} /*\n*/
{return_} {/*print_out('T');*/col = 1;} /*return to first col of current row*/
{col_8} {/*print_out('T');*/col += 8;} /*Tab*/
{comment} {/*print_out('T');*/} /*Of Course Comment:)*/

{integer} {
	/*also check*/
	if(yyleng > 14)
	{
		printf("Error! The length of this number is too long!\n");
		exit(0);
	}
	print_out('C');col = col + yyleng;
}


{identifier} {
	/*check whether out of range*/
	if(yyleng > 10){
		printf("Error! The length of this idetifier is too long!\n");
		exit(0);
	}
	print_out('I');col = col + yyleng;
}

{identifier}\(.*\) {
    if (strcmp(yytext, "read") == 0 || strcmp(yytext, "write") == 0) {
        print_out('K');
    } else {
        printf("Error! Invalid array definition: %s\n", yytext);
    }
    col = col + yyleng;
}



"+"|"-"|"*"|"/"|"#"|"<"|">"|"="|"<>"|"!="|">="|"<="|":="	{print_out('O');col = col + yyleng;} /*算符*/
"\["|"("|")"|","|":"|";"|"."|"\]"|".."		{print_out('D');col = col + yyleng;} /*界符*/

{illegal} {
	/*deal with error and illegal*/
	/*head is identifier*/
	/*real里是错误类型*/
	printf("This word is incorrect! ");
	print_out('T');
}

{array} {
	print_out('C');col = col + yyleng;
}

%%

void print_out(char type)
{
     printf("%s:%c,(%d,%d)\n",yytext,type,yylineno,col);
}

int main(int argc,char** argv)
{

    FILE * fIn;			
	switch(argc)
	{
	case 1: 			//if nothing		
		fIn=fopen("test.frag","r");	
		if(fIn==NULL){
			printf("default file is not found\n");
			exit(1);
		}
		else	yyin = fIn;
		break;		
	case 2: 			//open the test file with yyin
		if ((fIn = fopen(argv[1],"r")) == NULL) {
	            printf("File %s is not found.\n",argv[1]);
	            exit(1);
	        }
	        else	yyin=fIn;
		break;
	default:
		printf("useage:flex [filename]\n");
		exit(1);
	}
    yylex();
  	
	
	fclose(fIn);
	return 0;

}