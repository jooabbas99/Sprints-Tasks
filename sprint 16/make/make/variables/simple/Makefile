RM := rm -rf

CC := gcc
CFLAGS := -O1 -Wall -Werror

TARGET := foobar
SRCS := foo.c bar.c foobar.c
HDRS := foo.h bar.h foobar.h
OBJS := foo.o bar.o foobar.o

all: $(TARGET)

$(TARGET): $(OBJS) $(HDRS)
	$(CC) -o $(TARGET) $(OBJS)

foobar.o: foobar.c foobar.h
	$(CC) $(CFLAGS) -c foobar.c

foo.o: foo.c foo.h
	$(CC) $(CFLAGS) -c foo.c

bar.o: bar.c bar.h
	$(CC) $(CFLAGS) -c bar.c

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
