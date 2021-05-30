all: main compile clean

compile: main.o
	g++ -o asociatyvuskont main.o
    
main: 
	g++ -c main.cpp

clean: main.o 
	rm *.o
