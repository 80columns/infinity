all: demo

demo: libinfinity demo.o
	$(CXX) demo.o ./libinfinity.so -lm -o demo

demo.o: demo.cpp
	$(CXX) -c demo.cpp

libinfinity: infinity.o
	$(CXX) -shared -fPIC infinity.o -o libinfinity.so

infinity.o: infinity.cpp infinity.h
	$(CXX) -fPIC -c infinity.cpp

clean:
	rm -f *.o *.so demo
