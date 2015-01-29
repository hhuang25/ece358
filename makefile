all: lab1

lab1: random.o queue.o
	g++ random.o queue.o -g -o lab1.exe

random.o: Random.cpp
	g++ -c Random.cpp
queue.o: Queue.cpp
	g++ -c Queue.cpp
clean:
	rm lab1.exe
