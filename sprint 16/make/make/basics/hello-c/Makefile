all: hello

hello.o: hello.c
	gcc -O1 -Wall -Werror -c hello.c

hello: hello.o
	gcc -o hello hello.o

.PHONY: clean

clean:
	rm -rf hello hello.o
