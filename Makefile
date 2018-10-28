# all: mini_l

# mini_l.tab.cc mini_l.tab.hh:	mini_l.y
# 	bison -v -d --language=c++ mini_l.y

# lex.yy.cc: mini_l.l mini_l.tab.hh
# 	flex++ mini_l.l

# mini_l: lex.yy.cc mini_l.tab.cc mini_l.tab.hh
# 	g++ -o mini_l mini_l.tab.cc lex.yy.cc -lfl -v

# clean:
# 	rm stack.hh mini_l.tab.cc lex.yy.cc mini_l.tab.hh mini_l.output

all: output

bison: mini_l.y
	bison -v -d mini_l.y

flex: mini_l.l
	flex mini_l.l

mini_l: bison flex
	gcc -o mini_l lex.yy.c mini_l.tab.c main.c -lfl

output: mini_l
	cat mytest.min.txt | ./mini_l > yacc.txt

clean:
	rm *.o lex.yy.c lex.yy.cc mini_l.tab.hh mini_l.tab.h mini_l.tab.cc mini_l.tab.c mini_l yacc.txt