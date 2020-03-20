# part of the makefile

CFLAGS = -O0 -g

all: myLang.tab.c lex.yy.c ast.c main.c genllvm.c
	gcc -o calc $(CFLAGS) myLang.tab.c lex.yy.c ast.c genllvm.c main.c


myLang.tab.c : myLang.y
	bison -d myLang.y

lex.yy.c : myLang.l
	flex myLang.l
	


clean:
	$(RM) *.o *.exe myLang.tab.c myLang.tab.h lex.yy.c