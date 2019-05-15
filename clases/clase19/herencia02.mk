all: herencia02m

herencia02m: herencia02m.o herencia01.o
	$(CXX) -o $@ $^

herencia02m.o: herencia02m.cpp herencia01.h

herencia01.o: herencia01.cpp herencia01.h
