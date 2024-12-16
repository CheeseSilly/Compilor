%{
/*
Date: 2024.11.23
Author: CheeseSilly
ALL RIGHTS DESERVED
 */

#include"./head/main.h"
#include"./head/semer.h"
#include"./head/irer.h"
#include"./head/asmer.h"

FILE *fi;
FILE *fh;
extern int column;
extern int row;
Node* Root;

extern void yyerror(char const* s);
extern int yylex(void);
int yyrestart();

%}

/* declared types */
%union {
    struct Node* node;
}

%start Program 
%token<node> INTEGER_VAL
%token<node> IDENTIFIER
%token<node> PROCEDURE IF THEN ELSE WHILE DO READ WRITE CALL _BEGIN_ END CONST VAR ODD RETURN
%token<node> SL_PAREN SR_PAREN COMMA COLON SEMI DOT
%token<node> PLUS MINUS TIMES DIVIDE ASSIGN EQUAL LESS GREATER NOTEQUAL GREATER_EQUAL LESS_EQUAL
%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc ASSIGN
%nonassoc LESS GREATER EQUAL NOTEQUAL GREATER_EQUAL LESS_EQUAL
/* make a l_t_e,whose priority is lower than else.So,we can remove problem of if-then-if-then.....(about where is else) */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type<node> Program SubPro DeclarePart ConstDec ConstDef CDefine VarDec VarObj IdentiDef IdentiObject Array ArrayIndex ProDec ProceHead Statements Identifier INdex_Index AssignStm ComplexStm ComStates Condition CMP CondiStm Expr Term Factor WhileStm CallS Ccontent CconObj ReadS Rcontent RconObj WriteS Wcontent WconObj ReturnS

%%

Program     : SubPro DOT {
                fprintf(fi,"Program -> SubPro DOT\n");  
                fprintf(fh,"Program -> SubPro DOT\n");
                $$=createNode("Program","");addNode(2, $$, $1,$2);Root=$$;  
                  }
            ;
SubPro      : DeclarePart Statements {
                fprintf(fi,"SubPro -> DeclarePart Statement\n");  
                fprintf(fh,"SubPro -> DeclarePart Statement\n");
                $$=createNode("SubPro","");addNode(2, $$, $1,$2);}
            | Statements {
                fprintf(fi,"SubPro -> Statement\n");  
                fprintf(fh,"SubPro -> Statement\n");
                $$=createNode("SubPro","");addNode(1, $$, $1);  
            }
            ;
DeclarePart : ConstDec {
                  fprintf(fi,"DeclarePart -> ConstDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec\n");
                  $$=createNode("DeclarePart","");addNode(1, $$, $1);
            }
            |ConstDec VarDec {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec\n");
                  $$=createNode("DeclarePart","");addNode(2, $$, $1,$2);
            }
            |ConstDec ProDec {
                  fprintf(fi,"DeclarePart -> ConstDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec ProDec\n");
                  $$=createNode("DeclarePart","");addNode(2, $$, $1,$2);
            }
            |ConstDec VarDec ProDec {
                  fprintf(fi,"DeclarePart -> ConstDec VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> ConstDec VarDec ProDec\n");
                  $$=createNode("DeclarePart","");addNode(3, $$, $1,$2,$3);
            }
            |VarDec ProDec {
                  fprintf(fi,"DeclarePart -> VarDec ProDec\n");
                  fprintf(fh,"DeclarePart -> VarDec ProDec\n");
                  $$=createNode("DeclarePart","");addNode(2, $$, $1,$2);
            } 
            |VarDec {
                  fprintf(fi,"DeclarePart -> VarDec\n");
                  fprintf(fh,"DeclarePart -> VarDec\n");
                  $$=createNode("DeclarePart","");addNode(1, $$, $1);
            }
            |ProDec {
                  fprintf(fi,"DeclarePart -> ProDec\n");
                  fprintf(fh,"DeclarePart -> ProDec\n");
                  $$=createNode("DeclarePart","");addNode(1, $$, $1);
            }
            ;
ConstDec    : ConstDec CONST ConstDef SEMI {
                fprintf(fi,"ConstDec -> ConstDec const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> ConstDec const ConstDef SEMI\n");
                $$=createNode("ConstDec","");addNode(4, $$, $1,$2,$3,$4);
                  }
            | CONST ConstDef SEMI {
                fprintf(fi,"ConstDec -> const ConstDef SEMI\n");
                fprintf(fh,"ConstDec -> const ConstDef SEMI\n");
                $$=createNode("ConstDec","");addNode(3, $$, $1,$2,$3);
                  }
            ;
ConstDef    : ConstDef COMMA CDefine {
                fprintf(fi,"ConstDef -> ConstDef , CDefine\n"); 
                fprintf(fh,"ConstDef -> ConstDef , CDefine\n");
                $$=createNode("ConstDef","");addNode(3, $$, $1,$2,$3);
                 }
            | CDefine{
                fprintf(fi,"ConstDef -> CDefine\n"); 
                fprintf(fh,"ConstDef -> CDefine\n");
                $$=createNode("ConstDef","");addNode(1, $$, $1);
            }
            ;
CDefine     :IDENTIFIER EQUAL INTEGER_VAL {
                fprintf(fi,"CDefine -> IDENTIFIER = INTEGER_VAL\n");
                fprintf(fh,"CDefine -> IDENTIFIER = INTEGER_VAL\n");
                $$=createNode("CDefine","");addNode(3, $$, $1,$2,$3);
                }
            ;

VarDec      : VarDec VarObj {
                fprintf(fi,"VarDec -> VarDec VarObj\n");
                fprintf(fh,"VarDec -> VarDec VarObj\n");
                $$=createNode("VarDec","");addNode(2, $$, $1,$2);
                }
            | VarObj{
                fprintf(fi,"VarDec -> VarObj\n");
                fprintf(fh,"VarDec -> VarObj\n");
                $$=createNode("VarDec","");addNode(1, $$, $1);
                
            }
            ;
VarObj      :VAR IdentiDef SEMI {
                fprintf(fi,"VarObj -> var IdentiDef SEMI\n"); 
                fprintf(fh,"VarObj -> var IdentiDef SEMI\n");
                $$=createNode("VarObj","");addNode(3, $$, $1,$2,$3);
                 }
            ;
IdentiDef   : IdentiDef COMMA IdentiObject {
                fprintf(fi,"IdentiDef -> IdentiDef , IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiDef , IdentiObject\n"); 
                $$=createNode("IdentiDef","");addNode(3, $$, $1,$2,$3);
            }
            | IdentiObject{
                fprintf(fi,"IdentiDef -> IdentiObject\n");  
                fprintf(fh,"IdentiDef -> IdentiObject\n"); 
                $$=createNode("IdentiDef","");addNode(1, $$, $1);
            }
            ;

IdentiObject   : IDENTIFIER {
                fprintf(fi,"IdentiObject -> IDENTIFIER\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER\n");
                $$=createNode("IdentiObject","");addNode(1, $$, $1);
            }
            | IDENTIFIER Array {
                fprintf(fi,"IdentiObject -> IDENTIFIER Array\n");
                fprintf(fh,"IdentiObject -> IDENTIFIER Array\n");
                $$=createNode("IdentiObject","");addNode(2, $$, $1,$2);
            }
            ;

Array       : SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN {
                fprintf(fi,"Array -> SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN\n");
                fprintf(fh,"Array -> SL_PAREN ArrayIndex COLON ArrayIndex SR_PAREN\n");
                $$=createNode("Array","");addNode(5, $$, $1,$2,$3,$4,$5);
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
                $$=createNode("ArrayIndex","");addNode(1, $$, $1);
            }
            | IDENTIFIER {
                fprintf(fi,"ArrayIndex -> IDENTIFIER\n");
                fprintf(fh,"ArrayIndex -> IDENTIFIER\n");
                $$=createNode("ArrayIndex","");addNode(1, $$, $1);
            }
            ;

ProDec      : ProceHead SubPro SEMI {
                fprintf(fi,"ProDec -> ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProceHead SubPro SEMI\n"); 
                $$=createNode("ProDec","");addNode(3, $$, $1,$2,$3);
            }
            | ProDec ProceHead SubPro SEMI {
                fprintf(fi,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                fprintf(fh,"ProDec -> ProDec ProceHead SubPro SEMI\n"); 
                $$=createNode("ProDec","");addNode(4, $$, $1,$2,$3,$4);
            }
            ;
ProceHead   : PROCEDURE IDENTIFIER SEMI {
                fprintf(fi,"ProceHead -> procedure IDENTIFIER SEMI\n");
                fprintf(fh,"ProceHead -> procedure IDENTIFIER SEMI\n");
                $$=createNode("ProceHead","");addNode(3, $$, $1,$2,$3);
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
/* States      : Statements {
                fprintf(fi,"States -> Statement\n"); 
                fprintf(fh,"States -> Statement\n");
                 }
            | States Statements {
                fprintf(fi,"States -> States Statement\n"); 
                fprintf(fh,"States -> States Statement\n");
                 } */
Statements  : AssignStm  {
                fprintf(fi,"Statements -> AssignStm \n");
                fprintf(fh,"Statements -> AssignStm \n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                  }
            | ComplexStm  { 
                fprintf(fi,"Statements -> ComplexStm\n");
                fprintf(fh,"Statements -> ComplexStm\n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                }
            | CondiStm {
                fprintf(fi,"Statements -> CondiStm\n"); 
                fprintf(fh,"Statements -> CondiStm\n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                 }
            | WhileStm {
                fprintf(fi,"Statements -> WhileStm \n");
                fprintf(fh,"Statements -> WhileStm \n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                }
            | CallS {
                fprintf(fi,"Statements -> CallS \n");
                fprintf(fh,"Statements -> CallS \n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                  }
            | ReadS {
                fprintf(fi,"Statements -> ReadS \n"); 
                fprintf(fh,"Statements -> ReadS \n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                 }
            | WriteS {
                fprintf(fi,"Statements -> WriteS \n");
                fprintf(fh,"Statements -> WriteS \n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                  }
            | ReturnS {
                fprintf(fi,"Statements -> ReturnS \n");
                fprintf(fh,"Statements -> ReturnS \n");
                $$=createNode("Statements","");addNode(1, $$, $1);
                  }
            ;

Identifier  : IDENTIFIER SL_PAREN INdex_Index SR_PAREN {
                fprintf(fi,"Identifier -> IDENTIFIER SL_PAREN INdex_Index SR_PAREN\n");
                fprintf(fh,"Identifier -> IDENTIFIER SL_PAREN INdex_Index SR_PAREN\n");
                $$=createNode("Identifier","");addNode(4, $$, $1,$2,$3,$4);
            }
            | IDENTIFIER {
                fprintf(fi,"Identifier -> IDENTIFIER\n");
                fprintf(fh,"Identifier -> IDENTIFIER\n");
                $$=createNode("Identifier","");addNode(1, $$, $1);
            }
            ;
INdex_Index  : Expr {
                fprintf(fi,"INdex_Index -> Expr\n");
                fprintf(fh,"INdex_Index -> Expr\n");
                $$=createNode("INdex_Index","");addNode(1, $$, $1);
            }
            ;
AssignStm    : Identifier ASSIGN Expr {
                
                fprintf(fi,"AssignStm -> Identifier ASSIGN Expr\n");
                fprintf(fh,"AssignStm -> Identifier ASSIGN Expr\n");
                $$=createNode("AssignStm","");addNode(3, $$, $1,$2,$3);
            }
            ;

ComplexStm    : _BEGIN_ ComStates END  {
                fprintf(fi,"ComplexStm -> _BEGIN_ ComStates END\n"); 
                fprintf(fh,"ComplexStm -> _BEGIN_ ComStates END\n"); 
                $$=createNode("ComplexStm","");addNode(3, $$, $1,$2,$3);
                }
            ;

ComStates  : Statements SEMI  {
                fprintf(fi,"ComStates -> Statement SEMI\n");
                fprintf(fh,"ComStates -> Statement SEMI\n");
                $$=createNode("ComStates","");addNode(2, $$, $1,$2);
                 }
            | ComStates  Statements SEMI  {
                fprintf(fi,"ComStates ->ComStates  Statement SEMI\n");
                fprintf(fh,"ComStates ->ComStates  Statement SEMI\n");
                $$=createNode("ComStates","");addNode(3, $$, $1,$2,$3);
                }
            
            ;

Condition   : Expr CMP Expr {
                fprintf(fi,"Condition -> Expr CMP Expr\n");
                fprintf(fh,"Condition -> Expr CMP Expr\n");
                $$=createNode("Condition","");addNode(3, $$, $1,$2,$3);
                }
            | ODD Expr {
                fprintf(fi,"Condition -> ODD Expr\n");
                fprintf(fh,"Condition -> ODD Expr\n");
                $$=createNode("Condition","");addNode(2, $$, $1,$2);
              }
            ;
CMP          : EQUAL {
                fprintf(fi,"CMP -> EQUAL\n"); 
                fprintf(fh,"CMP -> EQUAL\n"); 
                $$=createNode("CMP","");addNode(1, $$, $1);
             }
            | NOTEQUAL {
                fprintf(fi,"CMP -> NOTEQUAL\n");
                fprintf(fh,"CMP -> NOTEQUAL\n");
                $$=createNode("CMP","");addNode(1, $$, $1);
              }
            | LESS {
                fprintf(fi,"CMP -> LESS\n"); 
                fprintf(fh,"CMP -> LESS\n");
                $$=createNode("CMP","");addNode(1, $$, $1);
            }
            | GREATER {
                fprintf(fi,"CMP -> GREATER\n");
                fprintf(fh,"CMP -> GREATER\n");
                $$=createNode("CMP","");addNode(1, $$, $1);
              }
            | LESS_EQUAL {
                fprintf(fi,"CMP -> LESS_EQUAL\n"); 
                fprintf(fh,"CMP -> LESS_EQUAL\n"); 
                $$=createNode("CMP","");addNode(1, $$, $1);
             }
            | GREATER_EQUAL {
                fprintf(fi,"CMP -> GREATER_EQUAL\n");  
                fprintf(fh,"CMP -> GREATER_EQUAL\n");
                $$=createNode("CMP","");addNode(1, $$, $1);
            }
            ;
CondiStm    : IF Condition THEN Statements %prec LOWER_THAN_ELSE {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement\n"); 
                fprintf(fh,"CondiStm -> IF Condition THEN Statement\n"); 
                $$=createNode("CondiStm","");addNode(4, $$, $1,$2,$3,$4);
                 }
            | IF Condition THEN Statements ELSE Statements {
                fprintf(fi,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                fprintf(fh,"CondiStm -> IF Condition THEN Statement ELSE Statement\n");
                $$=createNode("CondiStm","");addNode(6, $$, $1,$2,$3,$4,$5,$6);
                  }
            ;
Expr        : Expr PLUS Term {
                
                fprintf(fi,"Expr -> Expr PLUS Term\n"); 
                fprintf(fh,"Expr -> Expr PLUS Term\n");
                $$=createNode("Expr","");addNode(3, $$, $1,$2,$3);
                }
            | Expr MINUS Term {
                
                fprintf(fi,"Expr -> Expr MINUS Term\n");
                fprintf(fh,"Expr -> Expr MINUS Term\n");
                $$=createNode("Expr","");addNode(3, $$, $1,$2,$3);
                  }
            | PLUS Term {
                
                fprintf(fi,"Expr -> PLUS Term\n");  
                fprintf(fh,"Expr -> PLUS Term\n"); 
                $$=createNode("Expr","");addNode(2, $$, $1,$2);
                }
            | MINUS Term {
                
                fprintf(fi,"Expr -> MINUS Term\n"); 
                fprintf(fh,"Expr -> MINUS Term\n");
                $$=createNode("Expr","");addNode(2, $$, $1,$2);
                 }
            | Term {
                
                fprintf(fi,"Expr -> Term\n"); 
                fprintf(fh,"Expr -> Term\n");
                $$=createNode("Expr","");addNode(1, $$, $1);
                 }
            ;
Term        : Term TIMES Factor {
                
                fprintf(fi,"Term -> Term TIMES Factor\n"); 
                fprintf(fh,"Term -> Term TIMES Factor\n");
                $$=createNode("Term","");addNode(3, $$, $1,$2,$3);
                 }
            | Term DIVIDE Factor {
                
                fprintf(fi,"Term -> Term DIVIDE Factor\n"); 
                fprintf(fh,"Term -> Term DIVIDE Factor\n");
                $$=createNode("Term","");addNode(3, $$, $1,$2,$3);
                 }
            | Factor {
                
                fprintf(fi,"Term -> Factor\n"); 
                fprintf(fh,"Term -> Factor\n"); 
                $$=createNode("Term","");addNode(1, $$, $1);
                 }
            ;
Factor      : Identifier {
                // $$=$1;
                fprintf(fi,"Factor -> Identifier\n"); 
                fprintf(fh,"Factor -> Identifier\n");
                $$=createNode("Factor","");addNode(1, $$, $1);
                 }
            | INTEGER_VAL {
                //$$=$1;
                fprintf(fi,"Factor -> INTEGER_VAL\n"); 
                fprintf(fh,"Factor -> INTEGER_VAL\n");
                $$=createNode("Factor","");addNode(1, $$, $1);
                 }
            | SL_PAREN Expr SR_PAREN {
                //$$=$2;
                fprintf(fi,"Factor -> SL_PAREN Expr SR_PAREN\n");
                fprintf(fh,"Factor -> SL_PAREN Expr SR_PAREN\n");
                $$=createNode("Factor","");addNode(3, $$, $1,$2,$3);
                  }
            ;
WhileStm    : WHILE Condition DO Statements {
                fprintf(fi,"WhileStm -> WHILE Condition DO Statement\n"); 
                fprintf(fh,"WhileStm -> WHILE Condition DO Statement\n");
                $$=createNode("WhileStm","");addNode(4, $$, $1,$2,$3,$4);
            }
            ;
CallS       : CALL IDENTIFIER  {
                fprintf(fi,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN IDENTIFIER SR_PAREN\n"); 
                $$=createNode("CallS","");addNode(2, $$, $1,$2);
            }
            | CALL IDENTIFIER SL_PAREN Ccontent SR_PAREN {
                fprintf(fi,"CallS -> call SL_PAREN Ccontent SR_PAREN\n");  
                fprintf(fh,"CallS -> call SL_PAREN Ccontent SR_PAREN\n"); 
                $$=createNode("CallS","");addNode(5, $$, $1,$2,$3,$4,$5);
            } 
            ;
Ccontent   : Ccontent COMMA CconObj {
                fprintf(fi,"Ccontent -> Ccontent COMMA CconObj\n"); 
                fprintf(fh,"Ccontent -> Ccontent COMMA CconObj\n");
                $$=createNode("Ccontent","");addNode(3, $$, $1,$2,$3);
                 }
            | CconObj{
                fprintf(fi,"Ccontent -> CconObj\n"); 
                fprintf(fh,"Ccontent -> CconObj\n");
                $$=createNode("Ccontent","");addNode(1, $$, $1);
                 }
            ;
CconObj     : Expr {
                fprintf(fi,"CconObj -> Expr\n");
                fprintf(fh,"CconObj -> Expr\n");
                $$=createNode("CconObj","");addNode(1, $$, $1);
                }
ReadS       : READ SL_PAREN Rcontent SR_PAREN{
                fprintf(fi,"ReadS -> read SL_PAREN Rcontent SR_PAREN\n");
                fprintf(fh,"ReadS -> read SL_PAREN Rcontent SR_PAREN\n");
                $$=createNode("ReadS","");addNode(4, $$, $1,$2,$3,$4);
                  }
            ;
Rcontent    : Rcontent COMMA RconObj {
                fprintf(fi,"Rcontent -> Rcontent COMMA RconObj\n"); 
                fprintf(fh,"Rcontent -> Rcontent COMMA RconObj\n");
                $$=createNode("Rcontent","");addNode(3, $$, $1,$2,$3);
                 }
            | RconObj{
                fprintf(fi,"Rcontent -> RconObj\n"); 
                fprintf(fh,"Rcontent -> RconObj\n");
                $$=createNode("Rcontent","");addNode(1, $$, $1);
                 }
            ;
RconObj     : Identifier {
                fprintf(fi,"RconObj -> Identifier\n");
                fprintf(fh,"RconObj -> Identifier\n");
                $$=createNode("RconObj","");addNode(1, $$, $1);
                }
            ;

WriteS      : WRITE SL_PAREN Wcontent SR_PAREN{
                fprintf(fi,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                fprintf(fh,"WriteS -> write SL_PAREN Wcontent SR_PAREN\n");
                $$=createNode("WriteS","");addNode(4, $$, $1,$2,$3,$4);
                  }
            ;
Wcontent    : Wcontent COMMA WconObj {
                fprintf(fi,"Wcontent -> Wcontent COMMA WconObj\n"); 
                fprintf(fh,"Wcontent -> Wcontent COMMA WconObj\n");
                $$=createNode("Wcontent","");addNode(3, $$, $1,$2,$3);
                 }
            | WconObj{
                fprintf(fi,"Wcontent -> WconObj\n"); 
                fprintf(fh,"Wcontent -> WconObj\n");
                $$=createNode("Wcontent","");addNode(1, $$, $1);
                 }
            ;
WconObj     : Expr {
                fprintf(fi,"WconObj -> Expr\n");
                fprintf(fh,"WconObj -> Expr\n");
                $$=createNode("WconObj","");addNode(1, $$, $1);
                }
            ;
ReturnS     : RETURN INTEGER_VAL {
                fprintf(fi,"ReturnS -> return INTEGER_VAL\n");
                fprintf(fh,"ReturnS -> return INTEGER_VAL\n");
                $$=createNode("ReturnS","");addNode(2, $$, $1,$2);
                  }
            | RETURN IDENTIFIER {
                fprintf(fi,"ReturnS -> return IDENTIFIER\n");
                fprintf(fh,"ReturnS -> return IDENTIFIER\n");
                $$=createNode("ReturnS","");addNode(2, $$, $1,$2);
                  }
            ;

%%

int main(int argc, char** argv)
{
    
    FILE* f = fopen(argv[1], "r");
    fi = fopen("./output/SynOutput.txt", "w+");
    fh = fopen("./output/helperOutput.txt", "w+");
    yyparse();
    //printTree(Root,0);
    initHashtable();
    program(Root);
    printSymbol();
    initIRList();
    //printf("IRList:\n");
    rprogram(Root);
    //printCode("stdout");
    //code *.pl0
    printCode("./output/irer.ir");
    if(argc == 1)
        {
            //printCode("stdout");
            writeCode("stdout");
        }
    //code *.pl0 *.
        else if(argc == 2)
        {
            //printCode(argv[1]);
            writeCode(argv[1]);
        }
    return 0;
}

void yyerror(const char* s)
{
    if (s != nullptr) {
        printf("%s, (%d, %d)\n", s, row, column);
    } else {
        printf("Error message is null, (%d, %d)\n", row, column);
    }
    return;
}