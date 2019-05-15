all: herencia03m

herencia03m: herencia03m.o herencia03.o
	$(CXX) -o $@ $^

herencia03m.o: herencia03m.cpp herencia03.h

herencia03.o: herencia03.cpp herencia03.h
