all: mini_l

bison: mini_l.y
	bison -v -d mini_l.y

flex: mini_l.l
	flex mini_l.l

mini_l: bison flex
	g++ -o compile lex.yy.c mini_l.tab.c main.cc -g -ansi -Wno-write-strings -std=c++11 -w -Wfatal-errors

output: mini_l
	cat ../tests/fibonacci.min.txt | ./compile > _fib.txt
	cat ../tests/mytest.min.txt | ./compile > _mytest.txt
	cat ../tests/primes.min.txt |  ./compile > _primes.txt
	cat ../tests/myCustom.txt |  ./compile > _myCustom.txt
	cat ../tests/custom.min.txt | ./compile > _custom.txt
	cat ../tests/errors.min.txt | ./compile > _errors.txt

clean:
	rm lex.yy.c mini_l.tab.h mini_l.tab.c compile mini_l.output *.txt