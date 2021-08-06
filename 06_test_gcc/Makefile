#
#
#meaning of specific strings
# $@ all of FileNameWithExtension produced
# $* all of FileNameWithoutExtension produced
# $< the FileName of first dependance item
# $^ the dependance items with space islated and remove the repeated item
# $+ the dependance items with space islated, but do not remove the repeated item
# $? the dependance items with space islated, but just have the new item
# define a variable, Var=xx , and the methods of using variable is $(Var)
#
#
CC=gcc
CFLAGS = -I ./include
DEPS = say_hello_06.h

TARGET=test06

#all: test06
all: clean $(TARGET)

#test06 : ./src/say_hello_06.c ./src/test06.c
$(TARGET): ./src/say_hello_06.c ./src/test06.c
	$(CC) -o $@ $+  $(CFLAGS)
#	$(CC) -o test06 ./src/say_hello_06.c ./src/test06.c  $(CFLAGS)
#	gcc -o test06 ./src/say_hello_06.c ./src/test06.c -I ./include

clean:
#	rm test06
	rm $(TARGET)
