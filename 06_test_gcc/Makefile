CC=gcc
CFLAGS = -I ./include
DEPS = say_hello_06.h

all:test06

test06: ./src/say_hello_06.c ./src/test06.c
#	gcc -o test06 ./src/say_hello_06.c ./src/test06.c -I ./include
	$(CC) -o test06 ./src/say_hello_06.c ./src/test06.c  $(CFLAGS)

clean:
	rm test06
