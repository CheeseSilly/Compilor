%option noyywrap
%option yylineno 
%{
/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */

#include"./head/main.h"
#include"SyntaxPl0.tab.h"


int column=1;
int row=1;
extern int yylex(void);
extern int yywarp(void);
extern FILE* fh;


void output(char type);
%}

/*Defination*/
Digit   [0-9]
Letter    [a-zA-Z]
KeyWord [iI][fF]|[tT][hH][eE][nN]|[eE][lL][sS][eE]|[wW][hH][iI][lL][eE]|[dD][oO]|[rR][eE][aA][dD]|[wW][rR][iI][tT][eE]|[cC][aA][lL][lL]|[bB][eE][gG][iI][nN]|[eE][nN][dD]|[cC][oO][nN][sS][tT]|[vV][aA][rR]|[pP][rR][oO][cC][eE][dD][uU][rR][eE]|[oO][dD][dD]
Identifier  ({Letter}({Letter}|{Digit})*)
Integer {Digit}+

Newline [\n]
Blank [ ]
Tab [\t]
comment \{([^}]|\})*\}

illegal (\'.{2,}\')

/*Rules*/
%%
{Blank} { }
{Tab} { }
{comment} { } /*Of Course Comment:)*/

{Newline}   {row+=1;column=1;}

{KeyWord} {
	fprintf(fh, "%s\n", yytext);
	if(!strcasecmp(yytext, "CONST")){
		fprintf(fh, "CONST -> %s\n", yytext);
		return CONST;
	}
	if(!strcasecmp(yytext, "VAR")){
		fprintf(fh, "VAR -> %s\n", yytext);
		return VAR;
	}
	if(!strcasecmp(yytext, "PROCEDURE")){
		fprintf(fh, "PROCEDURE -> %s\n", yytext);
		return PROCEDURE;
	}
	if(!strcasecmp(yytext, "BEGIN")){
		fprintf(fh, "_BEGIN_ -> %s\n", yytext);
		return _BEGIN_;
	}
	if(!strcasecmp(yytext, "END")){
		fprintf(fh, "END -> %s\n", yytext);
		return END;
	}
	if(!strcasecmp(yytext, "IF")){
		fprintf(fh, "IF -> %s\n", yytext);
		return IF;
	}
	if(!strcasecmp(yytext, "THEN")){
		fprintf(fh, "THEN -> %s\n", yytext);
		return THEN;
	}
	if(!strcasecmp(yytext, "ELSE")){
		fprintf(fh, "ELSE -> %s\n", yytext);
		return ELSE;
	}
	if(!strcasecmp(yytext, "ODD")){
		fprintf(fh, "ODD -> %s\n", yytext);
		return ODD;
	}
	if(!strcasecmp(yytext, "WHILE")){
		fprintf(fh, "WHILE -> %s\n", yytext);
		return WHILE;
	}
	if(!strcasecmp(yytext, "DO")){
		fprintf(fh, "DO -> %s\n", yytext);
		return DO;
	}
	if(!strcasecmp(yytext, "CALL")){
		fprintf(fh, "CALL -> %s\n", yytext);
		return CALL;
	}
	if(!strcasecmp(yytext, "READ")){
		fprintf(fh, "READ -> %s\n", yytext);
		return READ;
	}
	if(!strcasecmp(yytext, "WRITE")){
		fprintf(fh, "WRITE -> %s\n", yytext);
		return WRITE;
	}
	column += yyleng;
}



"+"|"-"|"*"|"/"|"<"|">"|"="|"!="|">="|"<="|":="	{column+=yyleng;
	fprintf(fh, "%s\n", yytext);
    if(!strcasecmp(yytext, "+")){
		fprintf(fh, "PLUS -> %s\n", yytext);
		return PLUS;
	}
    if(!strcasecmp(yytext, "-")){
		fprintf(fh, "MINUS -> %s\n", yytext);
		return MINUS;
	}
    if(!strcasecmp(yytext, "*")){
		fprintf(fh, "TIMES -> %s\n", yytext);
		return TIMES;
	}
    if(!strcasecmp(yytext, "/")){
		fprintf(fh, "DIVIDE -> %s\n", yytext);
		return DIVIDE;
	}
    if(!strcasecmp(yytext, "<")){
		fprintf(fh, "LESS -> %s\n", yytext);
		return LESS;
	}
    if(!strcasecmp(yytext, ">")){
		fprintf(fh, "GREATER -> %s\n", yytext);
		return GREATER;
	}
    if(!strcasecmp(yytext, "=")){
		fprintf(fh, "EQUAL -> %s\n", yytext);
		return EQUAL;
	}
    if(!strcasecmp(yytext, "!=")){
		fprintf(fh, "NOTEQUAL -> %s\n", yytext);
		return NOTEQUAL;
	}
    if(!strcasecmp(yytext, ">=")){
		fprintf(fh, "GREATER_EQUAL -> %s\n", yytext);
		return GREATER_EQUAL;
	}
    if(!strcasecmp(yytext, "<=")){
		fprintf(fh, "LESS_EQUAL -> %s\n", yytext);
		return LESS_EQUAL;
	}
    if(!strcasecmp(yytext, ":=")){
		fprintf(fh, "ASSIGN -> %s\n", yytext);
		return ASSIGN;
	}

}

"("|")"|"["|"]"|","|":"|";"|"."		{column+=yyleng;
	fprintf(fh, "%s\n", yytext);
    if(!strcasecmp(yytext, "(")){
		fprintf(fh, "SL_PAREN -> %s\n", yytext);
		return SL_PAREN;
	}
    if(!strcasecmp(yytext, ")")){
		fprintf(fh, "SR_PAREN -> %s\n", yytext);
		return SR_PAREN;
	}
    if(!strcasecmp(yytext, "[")){
		fprintf(fh, "LEFTBRAC -> %s\n", yytext);
		return LEFTBRAC;
	}
    if(!strcasecmp(yytext, "]")){
		fprintf(fh, "RIGHTBRAC -> %s\n", yytext);
		return RIGHTBRAC;
	}
    if(!strcasecmp(yytext, ",")){
		fprintf(fh, "COMMA -> %s\n", yytext);
		return COMMA;
	}
    if(!strcasecmp(yytext, ":")){
		fprintf(fh, "COLON -> %s\n", yytext);
		return COLON;
	}
    if(!strcasecmp(yytext, ";")){
		fprintf(fh, "SEMI -> %s\n", yytext);
		return SEMI;
	}
    if(!strcasecmp(yytext, ".")){
		fprintf(fh, "DOT -> %s\n", yytext);
		return DOT;
	}
}


{Integer} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "INTEGER_VAL -> %s\n", yytext);
    if(yyleng>14)
    {
        printf("Error! Word length is overproof!\n");
        exit(0);
    }
    column+=yyleng;
    yylval.m_int=atoi(yytext);
    return INTEGER_VAL;
}
{Identifier} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "IDENTIFIER -> %s\n", yytext);
    column+=yyleng;
    yylval.m_ID=yytext;
    return IDENTIFIER;
}
{illegal} {
    printf("Error! Illegal input!\n");
    exit(0);
}

%%
