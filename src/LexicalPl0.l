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

void handle(const char * match,const char * yytext)
{
    yylval.node = createNode(match,yytext);
}

// void output(char type);
%}

/*Defination*/
Digit   [0-9]
Letter    [a-zA-Z]
KeyWord [iI][fF]|[tT][hH][eE][nN]|[eE][lL][sS][eE]|[wW][hH][iI][lL][eE]|[dD][oO]|[rR][eE][aA][dD]|[wW][rR][iI][tT][eE]|[cC][aA][lL][lL]|[bB][eE][gG][iI][nN]|[eE][nN][dD]|[cC][oO][nN][sS][tT]|[vV][aA][rR]|[pP][rR][oO][cC][eE][dD][uU][rR][eE]|[oO][dD][dD]|[rR][eE][tT][uU][rR][nN]
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
		handle("CONST",yytext);
		return CONST;
	}
	if(!strcasecmp(yytext, "VAR")){
		fprintf(fh, "VAR -> %s\n", yytext);
		handle("VAR",yytext);
		return VAR;
	}
	if(!strcasecmp(yytext, "PROCEDURE")){
		fprintf(fh, "PROCEDURE -> %s\n", yytext);
		handle("PROCEDURE",yytext);
		return PROCEDURE;
	}
	if(!strcasecmp(yytext, "BEGIN")){
		fprintf(fh, "_BEGIN_ -> %s\n", yytext);
		handle("_BEGIN_",yytext);
		return _BEGIN_;
	}
	if(!strcasecmp(yytext, "END")){
		fprintf(fh, "END -> %s\n", yytext);
		handle("END",yytext);
		return END;
	}
	if(!strcasecmp(yytext, "IF")){
		fprintf(fh, "IF -> %s\n", yytext);
		handle("IF",yytext);
		return IF;
	}
	if(!strcasecmp(yytext, "THEN")){
		fprintf(fh, "THEN -> %s\n", yytext);
		handle("THEN",yytext);
		return THEN;
	}
	if(!strcasecmp(yytext, "ELSE")){
		fprintf(fh, "ELSE -> %s\n", yytext);
		handle("ELSE",yytext);
		return ELSE;
	}
	if(!strcasecmp(yytext, "ODD")){
		fprintf(fh, "ODD -> %s\n", yytext);
		handle("ODD",yytext);
		return ODD;
	}
	if(!strcasecmp(yytext, "WHILE")){
		fprintf(fh, "WHILE -> %s\n", yytext);
		handle("WHILE",yytext);
		return WHILE;
	}
	if(!strcasecmp(yytext, "DO")){
		fprintf(fh, "DO -> %s\n", yytext);
		handle("DO",yytext);
		return DO;
	}
	if(!strcasecmp(yytext, "CALL")){
		fprintf(fh, "CALL -> %s\n", yytext);
		handle("CALL",yytext);
		return CALL;
	}
	if(!strcasecmp(yytext, "READ")){
		fprintf(fh, "READ -> %s\n", yytext);
		handle("READ",yytext);
		return READ;
	}
	if(!strcasecmp(yytext, "WRITE")){
		fprintf(fh, "WRITE -> %s\n", yytext);
		handle("WRITE",yytext);
		return WRITE;
	}
	if(!strcasecmp(yytext, "RETURN")){
		fprintf(fh, "RETURN-> %s\n", yytext);
		handle("RETURN",yytext);
		return RETURN;
	}
	column += yyleng;
}



"+"|"-"|"*"|"/"|"<"|">"|"="|"!="|">="|"<="|":="	{column+=yyleng;
	fprintf(fh, "%s\n", yytext);
    if(!strcasecmp(yytext, "+")){
		fprintf(fh, "PLUS -> %s\n", yytext);
		handle("PLUS",yytext);
		return PLUS;
	}
    if(!strcasecmp(yytext, "-")){
		fprintf(fh, "MINUS -> %s\n", yytext);
		handle("MINUS",yytext);
		return MINUS;
	}
    if(!strcasecmp(yytext, "*")){
		fprintf(fh, "TIMES -> %s\n", yytext);
		handle("TIMES",yytext);
		return TIMES;
	}
    if(!strcasecmp(yytext, "/")){
		fprintf(fh, "DIVIDE -> %s\n", yytext);
		handle("DIVIDE",yytext);
		return DIVIDE;
	}
    if(!strcasecmp(yytext, "<")){
		fprintf(fh, "LESS -> %s\n", yytext);
		handle("LESS",yytext);
		return LESS;
	}
    if(!strcasecmp(yytext, ">")){
		fprintf(fh, "GREATER -> %s\n", yytext);
		handle("GREATER",yytext);
		return GREATER;
	}
    if(!strcasecmp(yytext, "=")){
		fprintf(fh, "EQUAL -> %s\n", yytext);
		handle("EQUAL",yytext);
		return EQUAL;
	}
    if(!strcasecmp(yytext, "!=")){
		fprintf(fh, "NOTEQUAL -> %s\n", yytext);
		handle("NOTEQUAL",yytext);
		return NOTEQUAL;
	}
    if(!strcasecmp(yytext, ">=")){
		fprintf(fh, "GREATER_EQUAL -> %s\n", yytext);
		handle("GREATER_EQUAL",yytext);
		return GREATER_EQUAL;
	}
    if(!strcasecmp(yytext, "<=")){
		fprintf(fh, "LESS_EQUAL -> %s\n", yytext);
		handle("LESS_EQUAL",yytext);
		return LESS_EQUAL;
	}
    if(!strcasecmp(yytext, ":=")){
		fprintf(fh, "ASSIGN -> %s\n", yytext);
		handle("ASSIGN",yytext);
		return ASSIGN;
	}

}

"("|")"|"["|"]"|","|":"|";"|"."		{column+=yyleng;
	fprintf(fh, "%s\n", yytext);
    if(!strcasecmp(yytext, "(")){
		fprintf(fh, "SL_PAREN -> %s\n", yytext);
		handle("SL_PAREN",yytext);
		return SL_PAREN;
	}
    if(!strcasecmp(yytext, ")")){
		fprintf(fh, "SR_PAREN -> %s\n", yytext);
		handle("SR_PAREN",yytext);
		return SR_PAREN;
	}
    // if(!strcasecmp(yytext, "[")){
	// 	fprintf(fh, "LEFTBRAC -> %s\n", yytext);
	// 	handle("LEFTBRAC",yytext);
	// 	return LEFTBRAC;
	// }
    // if(!strcasecmp(yytext, "]")){
	// 	fprintf(fh, "RIGHTBRAC -> %s\n", yytext);
	// 	handle("RIGHTBRAC",yytext);
	// 	return RIGHTBRAC;
	// }
    if(!strcasecmp(yytext, ",")){
		fprintf(fh, "COMMA -> %s\n", yytext);
		handle("COMMA",yytext);
		return COMMA;
	}
    if(!strcasecmp(yytext, ":")){
		fprintf(fh, "COLON -> %s\n", yytext);
		handle("COLON",yytext);
		return COLON;
	}
    if(!strcasecmp(yytext, ";")){
		fprintf(fh, "SEMI -> %s\n", yytext);
		handle("SEMI",yytext);
		return SEMI;
	}
    if(!strcasecmp(yytext, ".")){
		fprintf(fh, "DOT -> %s\n", yytext);
		handle("DOT",yytext);
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
    // yylval.m_int=atoi(yytext);
	handle("INTEGER_VAL",yytext);
    return INTEGER_VAL;
}
{Identifier} {
	fprintf(fh, "%s\n", yytext);
	fprintf(fh, "IDENTIFIER -> %s\n", yytext);
    column+=yyleng;
    // yylval.m_ID=yytext;
	handle("IDENTIFIER",yytext);
    return IDENTIFIER;
}
{illegal} {
    printf("Error! Illegal input!\n");
    exit(0);
}

%%
