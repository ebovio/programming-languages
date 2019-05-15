
all: notpol

notpol: notpolparser.o notpolscanner.o
	gcc -o $@ notpolparser.o notpolscanner.o

notpolparser.o: notpolparser.c
	gcc -c $<

notpolscanner.o: notpolscanner.c
	gcc -c $<

notpolparser.c: notpol.y
	bison -d -o $@ $<

notpolscanner.c: notpol.lex
	flex -o $@ $<

clean:
	rm -f notpolparser.c notpolscanner.c notpolparser.o notpolscanner.o notpolparser.h \
	notpol
	rm -f *.*~ *~
