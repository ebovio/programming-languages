
all: ccalc

ccalc: calcparser.o calclexer.o
	gcc -o $@ calcparser.o calclexer.o

calcparser.o: calcparser.c
	gcc -c $<

calclexer.o: calclexer.c
	gcc -c $<

calcparser.c: calc.y
	bison -d -o $@ $<

calclexer.c: calc.lex
	flex -o $@ $<

clean:
	rm -f calcparser.c calclexer.c calcparser.o calclexer.o calcparser.h \
	ccalc
