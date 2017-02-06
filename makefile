all: psleep
psleep: main.o random.o time.o
	g++ main.o random.o time.o -o psleep
main.o: main.cpp random.cpp time.cpp
	g++ -c main.cpp random.cpp time.cpp
random.o: random.cpp random.hpp
	g++ -c random.cpp
time.o: time.cpp time.hpp
	g++ -c time.cpp
clean:
	rm *o psleep	
run: psleep
	./psleep
	