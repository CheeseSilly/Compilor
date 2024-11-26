run:
	./flex ./src/LexicalPl0.l
	./bison -d -v ./src/SyntaxPl0.y
	g++ -o code SyntaxPl0.tab.c lex.yy.c
	code < ./test/code.pl0
clean:
	del code.exe
	del lex.yy.c
	del SyntaxPl0.tab.c
	del SyntaxPl0.tab.h
	del SyntaxPl0.output