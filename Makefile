all: mini_l

mini_l.tab.c mini_l.tab.h:	mini_l.y
	bison -v -d mini_l.y

lex.yy.c: mini_l.l mini_l.tab.h
	flex mini_l.l

mini_l: lex.yy.c mini_l.tab.c mini_l.tab.h
	gcc -o mini_l mini_l.tab.c lex.yy.c -ll -v

clean:
	rm mini_l mini_l.tab.c lex.yy.c mini_l.tab.h