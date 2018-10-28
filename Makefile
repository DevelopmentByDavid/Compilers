# all: mini_l

# mini_l.tab.cc mini_l.tab.hh:	mini_l.y
# 	bison -v -d --language=c++ mini_l.y

# lex.yy.cc: mini_l.l mini_l.tab.hh
# 	flex++ mini_l.l

# mini_l: lex.yy.cc mini_l.tab.cc mini_l.tab.hh
# 	g++ -o mini_l mini_l.tab.cc lex.yy.cc -lfl -v

# clean:
# 	rm stack.hh mini_l.tab.cc lex.yy.cc mini_l.tab.hh mini_l.output

all: mini_l

flex: mini_l.l
	flex mini_l.l

mini_l: flex
	g++ -o mini_l lex.yy.c main.cc

clean:
	rm *.o lex.yy.c 