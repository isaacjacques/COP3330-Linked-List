main: main.o linklist.o
	g++ -o main -std=c++11 main.o linklist.o

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

linklist.o: linklist.cpp linklist.h
	g++ -c -std=c++11 linklist.cpp

clean:
	rm -f *.h.gch
	rm -f *.o