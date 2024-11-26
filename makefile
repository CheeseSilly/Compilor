run:
	./flex code.l
	g++ -o code lex.yy.c
	./code code.pl0
clean:
	del code.exe
	del lex.yy.c