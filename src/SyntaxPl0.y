%{
/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */

#include"./head/main.h"

FILE *fi;
FILE *fh;
extern int column;
extern int row;

extern void yyerror(char const* s);
extern int yylex(void);

%}

/* declared types */
%union {
 int m_int;
 char* m_ID;
}

%start Program 
%token<m_int> INTEGER_VAL
%token<m_ID> IDENTIFIER
%token PROCEDURE IF THEN ELSE WHILE DO READ WRITE CALL _BEGIN_ END CONST VAR ODD 
%token SL_PAREN SR_PAREN LEFTBRAC RIGHTBRAC COMMA COLON SEMI DOT
%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc ASSIGN
%nonassoc LESS GREATER EQUAL NOTEQUAL GREATER_EQUAL LESS_EQUAL
/* make a l_t_e,whose priority is lower than else.So,we can remove problem of if-then-if-then.....(about where is else) */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

Program     : SubPro DOT {
                fprintf(fi,"Program -> SubPro DOT\n");  
                fprintf(fh,"Program -> SubPro DOT\n");  }
            ;
SubPro      : DeclarePart Statements {
                fprintf(fi,"SubPro -> DeclarePart Statement\n");  
                fprintf(fh,"SubPro -> DeclarePart Statement\n");  }
            | Statements {
                fprintf(fi,"SubPro -> Statement\n");  
                fprintf(fh,"SubPro -> Statement\n");  
            }
            ;
DeclarePart : ConstDec {
                  fprintf(fi,"DeclarePart -> ConstDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec\n");
            }
            |ConstDec VarDec {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec\n");
            }
            |ConstDec ProDec {
                  fprintf(fi,"DeclarePart -> ConstDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec ProDec\n");
            }
            |ConstDec VarDec ProDec {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec ProDec\n");
            }
            |VarDec ProDec {
                  fprintf(fi,"DeclarePart -> VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> VarDec ProDec\n");
            } 
            |VarDec {
                  fprintf(fi,"DeclarePart -> VarDec\n");
                  fprintf(fh,"DeclarePart -> VarDec\n");
            }
            |ProDec {
                  fprintf(fi,"DeclarePart -> ProDec\n");
                  fprintf(fh,"DeclarePart -> ProDec\n");
            }
            ;
ConstDec    : ConstDec CONST ConstDef SEMI {
                fprintf(fi,"ConstDec -> ConstDec const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> ConstDec const ConstDef SEMI\n");
                  }
            | CONST ConstDef SEMI {
                fprintf(fi,"ConstDec -> const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> const ConstDef SEMI\n");
                  }
            ;
ConstDef    : ConstDef COMMA CDefine {
                fprintf(fi,"ConstDef -> ConstDef , CDefine\n"); 
                fprintf(fh,"ConstDef -> ConstDef , CDefine\n");
                 }
            | CDefine{
                fprintf(fi,"ConstDef -> CDefine\n"); 
                fprintf(fh,"ConstDef -> CDefine\n");
            }
            ;
CDefine     :IDENTIFIER EQUAL INTEGER_VAL {
                fprintf(fi,"CDefine -> IDENTIFIER = INTEGER_VAL\n");
                fprintf(fh,"CDefine -> IDENTIFIER = INTEGER_VAL\n");
                }
            ;

VarDec      : VarDec VarObj {
                fprintf(fi,"VarDec -> VarDec VarObj\n");
                 fprintf(fh,"VarDec -> VarDec VarObj\n");
                }
            | VarObj{
                fprintf(fi,"VarDec -> VarObj\n");
                 fprintf(fh,"VarDec -> VarObj\n");
                
            }
            ;
VarObj      :VAR IdentiDef SEMI {
                fprintf(fi,"VarObj -> var IdentiDef SEMI\n"); 
                fprintf(fh,"VarObj -> var IdentiDef SEMI\n");
                 }
            ;
IdentiDef   : IdentiDef COMMA IdentiObject {
                fprintf(fi,"IdentiDef -> IdentiDef , IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiDef , IdentiObject\n"); 
            }
            | IdentiObject{
                fprintf(fi,"IdentiDef -> IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiObject\n"); 
            }
            ;

IdentiObject   : IDENTIFIER {
                fprintf(fi,"IdentiObject -> IDENTIFIER\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER\n");
            }
            | IDENTIFIER Array {
                fprintf(fi,"IdentiObject -> IDENTIFIER Array\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER Array\n");
            }
            ;

Array       : SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN {
                fprintf(fi,"Array -> SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN\n");
                fprintf(fh,"Array -> SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN\n");
            }
            /* | SL_PAREN Array SR_PAREN {
                fprintf(fi,"Array -> SL_PAREN Array SR_PAREN\n");
                fprintf(fh,"Array -> SL_PAREN Array SR_PAREN\n");
            }
            |  SL_PAREN ArrayIndex SR_PAREN {
                fprintf(fi,"Array -> SL_PAREN ArrayIndex SR_PAREN\n");
                fprintf(fh,"Array -> SL_PAREN ArrayIndex SR_PAREN\n");
            } */
            ;


ArrayIndex : INTEGER_VAL {
                fprintf(fi,"ArrayIndex -> INTEGER_VAL\n");
                fprintf(fh,"ArrayIndex -> INTEGER_VAL\n");
            }
            | IDENTIFIER {
                fprintf(fi,"ArrayIndex -> IDENTIFIER\n");
                fprintf(fh,"ArrayIndex -> IDENTIFIER\n");
            }
            ;

ProDec      : ProceHead SubPro SEMI {
                fprintf(fi,"ProDec -> ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProceHead SubPro SEMI\n"); 
            }
            | ProDec ProceHead SubPro SEMI {
                fprintf(fi,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
            }
            ;
ProceHead   : PROCEDURE IDENTIFIER SEMI {
                fprintf(fi,"ProceHead -> procedure IDENTIFIER SEMI\n");
                fprintf(fh,"ProceHead -> procedure IDENTIFIER SEMI\n");
            }
            ;

/* Statement   : ComplexStm {
                fprintf(fi,"Statement -> ComplexStm\n");
                fprintf(fh,"Statement -> ComplexStm\n");
                  }
            | { // empty
                //fprintf(fi,"Statement -> Empty\n");
                //fprintf(fh,"Statement -> Empty\n");
                  }
            ; */
/* ComplexStm    : _BEGIN_ States END {
                fprintf(fi,"ComplexStm -> _BEGIN_ States END\n"); 
                fprintf(fh,"ComplexStm -> _BEGIN_ States END\n"); 
                }
                
            ; */
States      : Statements {
                fprintf(fi,"States -> Statement\n"); 
                fprintf(fh,"States -> Statement\n");
                 }
            | States Statements {
                fprintf(fi,"States -> States Statement\n"); 
                fprintf(fh,"States -> States Statement\n");
                 }
Statements  : AssignStm SEMI {
                fprintf(fi,"Statements -> AssignStm SEMI\n");
                fprintf(fh,"Statements -> AssignStm SEMI\n");
                  }
            | ComplexStm { 
                fprintf(fi,"Statements -> ComplexStm\n");
                fprintf(fh,"Statements -> ComplexStm\n");
                }
            | CondiStm {
                fprintf(fi,"Statements -> CondiStm\n"); 
                fprintf(fh,"Statements -> CondiStm\n");
                 }
            | WhileStm SEMI{
                fprintf(fi,"Statements -> WhileStm SEMI\n");
                fprintf(fh,"Statements -> WhileStm SEMI\n");
                }
            | CallS SEMI{
                fprintf(fi,"Statements -> CallS SEMI\n");
                fprintf(fh,"Statements -> CallS SEMI\n");
                  }
            | ReadS SEMI{
                fprintf(fi,"Statements -> ReadS SEMI\n"); 
                fprintf(fh,"Statements -> ReadS SEMI\n");
                 }
            | WriteS SEMI{
                fprintf(fi,"Statements -> WriteS SEMI\n");
                fprintf(fh,"Statements -> WriteS SEMI\n");
                  }
            ;

Identifier  : IDENTIFIER SL_PAREN INdex_Index SR_PAREN {
                fprintf(fi,"Identifier -> IDENTIFIER SL_PAREN INdex_Index SR_PAREN\n");
                fprintf(fh,"Identifier -> IDENTIFIER SL_PAREN INdex_Index SR_PAREN\n");
            }
            | IDENTIFIER {
                fprintf(fi,"Identifier -> IDENTIFIER\n");
                fprintf(fh,"Identifier -> IDENTIFIER\n");
            }
            ;
INdex_Index  : Expr {
                fprintf(fi,"INdex_Index -> Expr\n");
                fprintf(fh,"INdex_Index -> Expr\n");
            }
            ;
AssignStm    : Identifier ASSIGN Expr {
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN Expr\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN Expr\n");
            }
            ;

ComplexStm    : _BEGIN_ States END {
                fprintf(fi,"ComplexStm -> _BEGIN_ States END\n"); 
                fprintf(fh,"ComplexStm -> _BEGIN_ States END\n"); 
                }
            ;

Condition   : Expr CMP Expr {
                fprintf(fi,"Condition -> Expr CMP Expr\n");
                fprintf(fh,"Condition -> Expr CMP Expr\n");
                }
            | ODD Expr {
                fprintf(fi,"Condition -> ODD Expr\n");
                fprintf(fh,"Condition -> ODD Expr\n");
              }
            ;
CMP          : EQUAL {
                fprintf(fi,"CMP -> EQUAL\n"); 
                fprintf(fh,"CMP -> EQUAL\n"); 
             }
            | NOTEQUAL {
                fprintf(fi,"CMP -> NOTEQUAL\n");
                fprintf(fh,"CMP -> NOTEQUAL\n");
              }
            | LESS {
                fprintf(fi,"CMP -> LESS\n"); 
                fprintf(fh,"CMP -> LESS\n");
            }
            | GREATER {
                fprintf(fi,"CMP -> GREATER\n");
                fprintf(fh,"CMP -> GREATER\n");
              }
            | LESS_EQUAL {
                fprintf(fi,"CMP -> LESS_EQUAL\n"); 
                fprintf(fh,"CMP -> LESS_EQUAL\n"); 
             }
            | GREATER_EQUAL {
                fprintf(fi,"CMP -> GREATER_EQUAL\n");  
                fprintf(fh,"CMP -> GREATER_EQUAL\n");
            }
            ;
CondiStm    : IF Condition THEN Statements %prec LOWER_THAN_ELSE {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement\n"); 
                fprintf(fh,"CondiStm -> IF Condition THEN Statement\n"); 
                 }
            | IF Condition THEN Statements ELSE Statements {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                fprintf(fh,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                  }
            ;
Expr        : Expr PLUS Term {
                
                fprintf(fi,"Expr -> Expr PLUS Term\n"); 
                fprintf(fh,"Expr -> Expr PLUS Term\n");
                }
            | Expr MINUS Term {
                
                fprintf(fi,"Expr -> Expr MINUS Term\n");
                fprintf(fh,"Expr -> Expr MINUS Term\n");
                  }
            | PLUS Term {
                
                fprintf(fi,"Expr -> PLUS Term\n");  
                fprintf(fh,"Expr -> PLUS Term\n"); 
                }
            | MINUS Term {
                
                fprintf(fi,"Expr -> MINUS Term\n"); 
                fprintf(fh,"Expr -> MINUS Term\n");
                 }
            | Term {
                
                fprintf(fi,"Expr -> Term\n"); 
                fprintf(fh,"Expr -> Term\n");
                 }
            ;
Term        : Term TIMES Factor {
                
                fprintf(fi,"Term -> Term TIMES Factor\n"); 
                fprintf(fh,"Term -> Term TIMES Factor\n");
                 }
            | Term DIVIDE Factor {
                
                fprintf(fi,"Term -> Term DIVIDE Factor\n"); 
                fprintf(fh,"Term -> Term DIVIDE Factor\n");
                 }
            | Factor {
                
                fprintf(fi,"Term -> Factor\n"); 
                fprintf(fh,"Term -> Factor\n"); 
                 }
            ;
Factor      : Identifier {
                //$$=$1;
                fprintf(fi,"Factor -> Identifier\n"); 
                fprintf(fh,"Factor -> Identifier\n");
                 }
            | INTEGER_VAL {
                //$$=$1;
                fprintf(fi,"Factor -> INTEGER_VAL\n"); 
                fprintf(fh,"Factor -> INTEGER_VAL\n");
                 }
            | SL_PAREN Expr SR_PAREN {
                //$$=$2;
                fprintf(fi,"Factor -> SL_PAREN Expr SR_PAREN\n");
                fprintf(fh,"Factor -> SL_PAREN Expr SR_PAREN\n");
                  }
            ;
WhileStm    : WHILE Condition DO Statements {
                fprintf(fi,"WhileStm -> WHILE Condition DO Statement\n"); 
                fprintf(fh,"WhileStm -> WHILE Condition DO Statement\n");
            }
            ;
CallS       : CALL IDENTIFIER  {
                fprintf(fi,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n"); 
            }
            | CALL IDENTIFIER SL_PAREN Ccontent SR_PAREN {
                fprintf(fi,"CallS -> call SL_PAREN Ccontent SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN Ccontent SR_PAREN\n"); 
            } 
            ;
Ccontent   : Ccontent COMMA CconObj {
                fprintf(fi,"Ccontent -> Ccontent COMMA CconObj\n"); 
                fprintf(fh,"Ccontent -> Ccontent COMMA CconObj\n");
                 }
            | CconObj{
                fprintf(fi,"Ccontent -> CconObj\n"); 
                fprintf(fh,"Ccontent -> CconObj\n");
                 }
            ;
CconObj     : Expr {
                fprintf(fi,"CconObj -> Expr\n");
                fprintf(fh,"CconObj -> Expr\n");
                }
ReadS       : READ SL_PAREN Rcontent SR_PAREN{
                fprintf(fi,"ReadS -> read SL_PAREN Rcontent SR_PAREN\n");
                fprintf(fh,"ReadS -> read SL_PAREN Rcontent SR_PAREN\n");
                  }
            ;
Rcontent    : Rcontent COMMA RconObj {
                fprintf(fi,"Rcontent -> Rcontent COMMA RconObj\n"); 
                fprintf(fh,"Rcontent -> Rcontent COMMA RconObj\n");
                 }
            | RconObj{
                fprintf(fi,"Rcontent -> RconObj\n"); 
                fprintf(fh,"Rcontent -> RconObj\n");
                 }
            ;
RconObj     : Identifier {
                fprintf(fi,"RconObj -> Identifier\n");
                fprintf(fh,"RconObj -> Identifier\n");
                }
            ;

WriteS      : WRITE SL_PAREN Wcontent SR_PAREN{
                fprintf(fi,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                fprintf(fh,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                  }
            ;
Wcontent    : Wcontent COMMA WconObj {
                fprintf(fi,"Wcontent -> Wcontent COMMA WconObj\n"); 
                fprintf(fh,"Wcontent -> Wcontent COMMA WconObj\n");
                 }
            | WconObj{
                fprintf(fi,"Wcontent -> WconObj\n"); 
                fprintf(fh,"Wcontent -> WconObj\n");
                 }
            ;
WconObj     : Expr {
                fprintf(fi,"WconObj -> Expr\n");
                fprintf(fh,"WconObj -> Expr\n");
                }
            ;

%%

int main()
{
    fi = fopen("./output/SynOutput.txt", "w+");
    fh = fopen("./output/helperOutput.txt", "w+");
    if(!yyparse())
        return 0;
    return 1;
}

void yyerror(char const* s)
{
    printf("%s,(%d,%d)\n",s,row,column);
    return;
}