RM := rm -rf

CC := gcc
CFLAGS := -O1 -Wall -Werror

SRCS := hello.c main.c
OBJS := hello.o main.o
TARGET := hello

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
