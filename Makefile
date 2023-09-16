CXX = g++
CXXFLAGS = -std=c++11

all: my_program

listing_1.1: ./CAP_1/listing_1.1.c
	gcc $(CFLAGS) -c ./CAP_1/listing_1.1.c 
	g++ -o  listing_1.1 listing_1.1.o
	./listing_1.1

clean:
	rm -f my_program

run: my_program
	./my_program
