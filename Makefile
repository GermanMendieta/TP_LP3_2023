listing_1.1: ./src/CAP_1/listing_1.1/listing_1.1.c
	mkdir -p build/CAP_1/listing_1.1
	gcc $(CFLAGS) -c ./src/CAP_1/listing_1.1/listing_1.1.c -o ./build/CAP_1/listing_1.1/listing_1.1.o
	g++ -o ./build/CAP_1/listing_1.1/listing_1.1 ./build/CAP_1/listing_1.1/listing_1.1.o ./src/CAP_1/listing_1.1/reciprocal.cpp

listing_1.2: listing_1.1

listing_1.3: listing_1.1

listing_2.1: ./src/CAP_2/listing_2.1/listing_2.1.c
	mkdir -p build/CAP_2/listing_2.1
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.1/listing_2.1.c -o ./build/CAP_2/listing_2.1/listing_2.1.o
	g++ -o ./build/CAP_2/listing_2.1/listing_2.1 ./build/CAP_2/listing_2.1/listing_2.1.o

listing_2.2: ./src/CAP_2/listing_2.2/listing_2.2.c
	mkdir -p build/CAP_2/listing_2.2
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.2/listing_2.2.c -o ./build/CAP_2/listing_2.2/listing_2.2.o
	g++ -o ./build/CAP_2/listing_2.2/listing_2.2 ./build/CAP_2/listing_2.2/listing_2.2.o

listing_2.3: ./src/CAP_2/listing_2.3/listing_2.3.c
	mkdir -p build/CAP_2/listing_2.3
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.3/listing_2.3.c -o ./build/CAP_2/listing_2.3/listing_2.3.o
	g++ -o ./build/CAP_2/listing_2.3/listing_2.3 ./build/CAP_2/listing_2.3/listing_2.3.o

listing_2.4: ./src/CAP_2/listing_2.4/listing_2.4.c
	mkdir -p build/CAP_2/listing_2.4
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.4/listing_2.4.c -o ./build/CAP_2/listing_2.4/listing_2.4.o
	g++ -o ./build/CAP_2/listing_2.4/listing_2.4 ./build/CAP_2/listing_2.4/listing_2.4.o

listing_2.5: ./src/CAP_2/listing_2.5/listing_2.5.c
	mkdir -p build/CAP_2/listing_2.5
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.5/listing_2.5.c -o ./build/CAP_2/listing_2.5/listing_2.5.o
	g++ -o ./build/CAP_2/listing_2.5/listing_2.5 ./build/CAP_2/listing_2.5/listing_2.5.o

listing_2.6: ./src/CAP_2/listing_2.6/listing_2.6.c
	mkdir -p build/CAP_2/listing_2.6
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.6/listing_2.6.c -o ./build/CAP_2/listing_2.6/listing_2.6.o
	g++ -o ./build/CAP_2/listing_2.6/listing_2.6 ./build/CAP_2/listing_2.6/listing_2.6.o

listing_2.7: ./src/CAP_2/listing_2.7/listing_2.7.c ./src/CAP_2/listing_2.7/listing_2.8.c
	mkdir -p build/CAP_2/listing_2.7
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.7/listing_2.7.c -o ./build/CAP_2/listing_2.7/listing_2.7.o 
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.7/listing_2.8.c -o ./build/CAP_2/listing_2.7/listing_2.8.o 
	ar cr ./build/CAP_2/lib_listing_2.8.a ./build/CAP_2/listing_2.7/listing_2.8.o
	g++ -o ./build/CAP_2/listing_2.7/listing_2.7 ./build/CAP_2/listing_2.7/listing_2.7.o ./build/CAP_2/lib_listing_2.8.a

listing_2.8: listing_2.7

listing_2.9: ./src/CAP_2/listing_2.9/listing_2.9.c
	mkdir -p build/CAP_2/listing_2.9
	gcc $(CFLAGS) -c ./src/CAP_2/listing_2.9/listing_2.9.c -o ./build/CAP_2/listing_2.9/listing_2.9.o
	g++ -o ./build/CAP_2/listing_2.9/listing_2.9 ./build/CAP_2/listing_2.9/listing_2.9.o
	
listing_3.1: ./src/CAP_3/listing_3.1/listing_3.1.c
	mkdir -p build/CAP_3/listing_3.1
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.1/listing_3.1.c -o ./build/CAP_3/listing_3.1/listing_3.1.o
	g++ -o ./build/CAP_3/listing_3.1/listing_3.1 ./build/CAP_3/listing_3.1/listing_3.1.o

listing_3.2: ./src/CAP_3/listing_3.2/listing_3.2.c
	mkdir -p build/CAP_3/listing_3.2
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.2/listing_3.2.c -o ./build/CAP_3/listing_3.2/listing_3.2.o
	g++ -o ./build/CAP_3/listing_3.2/listing_3.2 ./build/CAP_3/listing_3.2/listing_3.2.o

listing_3.3: ./src/CAP_3/listing_3.3/listing_3.3.c
	mkdir -p build/CAP_3/listing_3.3
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.3/listing_3.3.c -o ./build/CAP_3/listing_3.3/listing_3.3.o
	g++ -o ./build/CAP_3/listing_3.3/listing_3.3 ./build/CAP_3/listing_3.3/listing_3.3.o

listing_3.4: ./src/CAP_3/listing_3.4/listing_3.4.c
	mkdir -p build/CAP_3/listing_3.4
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.4/listing_3.4.c -o ./build/CAP_3/listing_3.4/listing_3.4.o
	g++ -o ./build/CAP_3/listing_3.4/listing_3.4 ./build/CAP_3/listing_3.4/listing_3.4.o

listing_3.5: ./src/CAP_3/listing_3.5/listing_3.5.c
	mkdir -p build/CAP_3/listing_3.5
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.5/listing_3.5.c -o ./build/CAP_3/listing_3.5/listing_3.5.o
	g++ -o ./build/CAP_3/listing_3.5/listing_3.5 ./build/CAP_3/listing_3.5/listing_3.5.o

listing_3.6: ./src/CAP_3/listing_3.6/listing_3.6.c
	mkdir -p build/CAP_3/listing_3.6
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.6/listing_3.6.c -o ./build/CAP_3/listing_3.6/listing_3.6.o
	g++ -o ./build/CAP_3/listing_3.6/listing_3.6 ./build/CAP_3/listing_3.6/listing_3.6.o

listing_3.7: ./src/CAP_3/listing_3.7/listing_3.7.c
	mkdir -p build/CAP_3/listing_3.7
	gcc $(CFLAGS) -c ./src/CAP_3/listing_3.7/listing_3.7.c -o ./build/CAP_3/listing_3.7/listing_3.7.o 
	g++ -o ./build/CAP_3/listing_3.7/listing_3.7 ./build/CAP_3/listing_3.7/listing_3.7.o

listing_4.1: ./src/CAP_4/listing_4.1/listing_4.1.c
	mkdir -p build/CAP_4/listing_4.1
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.1/listing_4.1.c -o ./build/CAP_4/listing_4.1/listing_4.1.o
	g++ -o ./build/CAP_4/listing_4.1/listing_4.1 ./build/CAP_4/listing_4.1/listing_4.1.o

listing_4.2: ./src/CAP_4/listing_4.2/listing_4.2.c
	mkdir -p build/CAP_4/listing_4.2
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.2/listing_4.2.c -o ./build/CAP_4/listing_4.2/listing_4.2.o
	g++ -o ./build/CAP_4/listing_4.2/listing_4.2 ./build/CAP_4/listing_4.2/listing_4.2.o

listing_4.3: ./src/CAP_4/listing_4.3/listing_4.3.c
	mkdir -p build/CAP_4/listing_4.3
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.3/listing_4.3.c -o ./build/CAP_4/listing_4.3/listing_4.3.o
	g++ -o ./build/CAP_4/listing_4.3/listing_4.3 ./build/CAP_4/listing_4.3/listing_4.3.o

listing_4.4: ./src/CAP_4/listing_4.4/listing_4.4.c
	mkdir -p build/CAP_4/listing_4.4
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.4/listing_4.4.c -o ./build/CAP_4/listing_4.4/listing_4.4.o
	g++ -o ./build/CAP_4/listing_4.4/listing_4.4 ./build/CAP_4/listing_4.4/listing_4.4.o

listing_4.5: ./src/CAP_4/listing_4.5/listing_4.5.c
	mkdir -p build/CAP_4/listing_4.5
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.5/listing_4.5.c -o ./build/CAP_4/listing_4.5/listing_4.5.o
	g++ -o ./build/CAP_4/listing_4.5/listing_4.5 ./build/CAP_4/listing_4.5/listing_4.5.o

listing_4.6: ./src/CAP_4/listing_4.6/listing_4.6.c
	mkdir -p build/CAP_4/listing_4.6
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.6/listing_4.6.c -o ./build/CAP_4/listing_4.6/listing_4.6.o
	g++ -o ./build/CAP_4/listing_4.6/listing_4.6 ./build/CAP_4/listing_4.6/listing_4.6.o

listing_4.7: ./src/CAP_4/listing_4.7/listing_4.7.c
	mkdir -p build/CAP_4/listing_4.7
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.7/listing_4.7.c -o ./build/CAP_4/listing_4.7/listing_4.7.o
	g++ -o ./build/CAP_4/listing_4.7/listing_4.7 ./build/CAP_4/listing_4.7/listing_4.7.o

listing_4.8: ./src/CAP_4/listing_4.8/listing_4.8.c
	mkdir -p build/CAP_4/listing_4.8
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.8/listing_4.8.c -o ./build/CAP_4/listing_4.8/listing_4.8.o
	g++ -o ./build/CAP_4/listing_4.8/listing_4.8 ./build/CAP_4/listing_4.8/listing_4.8.o

listing_4.9: ./src/CAP_4/listing_4.9/listing_4.9.cpp
	mkdir -p build/CAP_4/listing_4.9
	g++ -o ./build/CAP_4/listing_4.9/listing_4.9 ./src/CAP_4/listing_4.9/listing_4.9.cpp

listing_4.10: ./src/CAP_4/listing_4.10/listing_4.10.c
	mkdir -p build/CAP_4/listing_4.10
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.10/listing_4.10.c -o ./build/CAP_4/listing_4.10/listing_4.10.o
	g++ -o ./build/CAP_4/listing_4.10/listing_4.10 ./build/CAP_4/listing_4.10/listing_4.10.o

listing_4.11: ./src/CAP_4/listing_4.11/listing_4.11.c
	mkdir -p build/CAP_4/listing_4.11
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.11/listing_4.11.c -o ./build/CAP_4/listing_4.11/listing_4.11.o
	g++ -o ./build/CAP_4/listing_4.11/listing_4.11 ./build/CAP_4/listing_4.11/listing_4.11.o

listing_4.12: ./src/CAP_4/listing_4.12/listing_4.12.c
	mkdir -p build/CAP_4/listing_4.12
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.12/listing_4.12.c -o ./build/CAP_4/listing_4.12/listing_4.12.o
	g++ -o ./build/CAP_4/listing_4.12/listing_4.12 ./build/CAP_4/listing_4.12/listing_4.12.o

listing_4.13: ./src/CAP_4/listing_4.13/listing_4.13.c
	mkdir -p build/CAP_4/listing_4.13
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.13/listing_4.13.c -o ./build/CAP_4/listing_4.13/listing_4.13.o
	g++ -o ./build/CAP_4/listing_4.13/listing_4.13 ./build/CAP_4/listing_4.13/listing_4.13.o

listing_4.14: ./src/CAP_4/listing_4.14/listing_4.14.c
	mkdir -p build/CAP_4/listing_4.14
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.14/listing_4.14.c -o ./build/CAP_4/listing_4.14/listing_4.14.o
	g++ -o ./build/CAP_4/listing_4.14/listing_4.14 ./build/CAP_4/listing_4.14/listing_4.14.o

listing_4.15: ./src/CAP_4/listing_4.15/listing_4.15.c
	mkdir -p build/CAP_4/listing_4.15
	gcc $(CFLAGS) -c ./src/CAP_4/listing_4.15/listing_4.15.c -o ./build/CAP_4/listing_4.15/listing_4.15.o
	g++ -o ./build/CAP_4/listing_4.15/listing_4.15 ./build/CAP_4/listing_4.15/listing_4.15.o


$(eval DIRS := $(shell basename -a $(shell find $('src') -type d -name "listing*")))

all: $(DIRS)
	@for file in $^; do \
		$(MAKE) "$$file"; \
	done

clean:
	rm -f -r ./build/*

.PHONY : clean
