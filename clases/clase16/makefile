all: main main2

main2: main.o aa.o
	g++ -o main2 main.o aa.o

main: main.o a.o
	g++ -o main main.o a.o

main.o: main.cpp a.h
	g++ -c main.cpp

a.o: a.cpp a.h
	g++ -c a.cpp

aa.o: aa.cpp a.h
	g++ -c aa.cpp
