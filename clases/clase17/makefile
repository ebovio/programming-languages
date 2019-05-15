all: main main2 main3

main3: main3.o
	g++ -o main3 main3.o

main2: main.o aa.o
	g++ -o main2 main.o aa.o

main: main.o a.o
	g++ -o main main.o a.o

main3.o: main3.cpp

main.o: main.cpp a.h

a.o: a.cpp a.h

aa.o: aa.cpp a.h
