all: main

main: main.o automatizador.o cambios.o helper.o
	g++ -o main main.o automatizador.o cambios.o helper.o

main.o: main.cpp automatizador.h cambios.h helper.h
	g++ -c main.cpp

automatizador.o: automatizador.cpp automatizador.h
	g++ -c automatizador.cpp

cambios.o: cambios.cpp cambios.h
	g++ -c cambios.cpp

helper.o: helper.cpp helper.h
	g++ -c helper.cpp
