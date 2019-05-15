call: herencia01m

herencia01m: herencia01m.o herencia01.o
	$(CXX) -o $@ $^

herencia01m.o: herencia01m.cpp herencia01.h

herencia01.o: herencia01.cpp herencia01.h
