all: output

bison: mini_l.y
	bison -v -d mini_l.y

flex: mini_l.l
	flex mini_l.l

mini_l: bison flex
	g++ -o compile lex.yy.c mini_l.tab.c main.cc -g -ansi -Wno-write-strings -std=c++11 -w

output: mini_l
	cat ../tests/fibonacci.min.txt | ./compile > _fib.txt
	cat ../tests/mytest.min.txt | ./compile > _mytest.txt
	cat ../tests/primes.min.txt |  ./compile > _primes.txt

clean:
	rm *.o lex.yy.c lex.yy.cc mini_l.tab.hh mini_l.tab.h mini_l.tab.cc mini_l.tab.c compile rules.txt mini_l.output bison.c tok.h stack.hh
	rm *.txt