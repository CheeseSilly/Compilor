%{
/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */
int row_num = 0, col_num = 0;  //row and column number
FILE *fp;  //pointer which points outputfile. Constant [-]?([0-9])|([1-9][0-9]+[\.]?[0-9]*)
%}

KeyWord [iI][fF]|[eE][lL][sS][eE]|[tT][hH][eE][nN]|[wW][hH][iI][lL][eE]|[dD][oO]|[rR][eE][aA][dD]|[wW][rR][iI][tT][eE]|[cC][aA][lL][lL]|[bB][eE][gG][iI][nN]|[eE][nN][dD]|[cC][oO][nN][sS][tT]|[vV][aA][rR]|[pP][rR][oO][cC][eE][dD][uU][rR][eE]|[oO][dD][dD]|[cC][aA][sS][eE]|[eE][nN][dD][cC][aA][sS][eE]
Identifier [A-Za-z][A-Za-z0-9]*
Zero [0]
PossiInt ([+]?[1-9][0-9]*)
NegatiInt ([-]?[0-9]+)
Float {Zero}|{PossiInt}|{NegatiInt}(.[0-9]+)
Constant {PossiInt}|{NegatiInt}|{Zero}
Operator [\.\[\]\^\-\*\+\?\{\}\"\\\(\)\|\/\$\<\>]|:=
Delimiter  [\,\;\.]
Space (\ )
Tab (\t)
Other [^{KeyWord}{Identifier}{Constant}{Operator}{Delimiter}]

%%

	

{KeyWord} {fprintf(fp, "%s : K, (%d, %d)\n", yytext, row_num, col_num); col_num += yyleng;}
{Identifier} {
	if(yyleng > 10){
		fprintf(fp, "Error!Expected a shorter IDENTIFIER!(%d, %d)\n", row_num, col_num);
		col_num += yyleng;
	}
	else{
		fprintf(fp, "%s : I, (%d, %d)\n", yytext, row_num, col_num); col_num += yyleng;
	}
}  
{Constant} {
	if(yyleng > 14){
		fprintf(fp, "Error!Expected a shorter CONSTANT!(%d, %d)\n", row_num, col_num);
		col_num += yyleng;
	}
	else{
		fprintf(fp, "%s : C, (%d, %d)\n", yytext, row_num, col_num);
		col_num += yyleng;
	}
}
{Operator} {fprintf(fp, "%s : O, (%d, %d)\n", yytext, row_num, col_num); col_num += yyleng;}
{Delimiter} {fprintf(fp, "%s : D, (%d, %d)\n", yytext, row_num, col_num); ++col_num;}
\n {++row_num; col_num = 1;}  //row number +1, column number = 1
{Space} {;}
{Tab} {;}
{Other} {fprintf(fp, "%s : T, (%d, %d)\n", yytext, row_num, col_num); col_num += yyleng;}

%%
main(){
fp = fopen("E:/.../.../Compiling Principle/Lab1/Output.txt", "w+");
yylex();

}
int yywrap(){
	return 1;
}