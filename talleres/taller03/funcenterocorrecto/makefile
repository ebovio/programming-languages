CFLAGS = -c

funenterocorrecto: funenterocorrecto.o
		$(CXX) funenterocorrecto.o -o funenterocorrecto

funenterocorrecto.o: funenterocorrecto.cpp
		$(CXX) $(CFLAGS) funenterocorrecto.cpp

clean:
	 $(RM) *.o funenterocorrecto core
