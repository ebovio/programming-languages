all: herencia04m

herencia04m: herencia04m.o herencia03.o
	$(CXX) -o $@ $^

herencia04m.o: herencia04m.cpp herencia03.h

herencia03.o: herencia03.cpp herencia03.h
