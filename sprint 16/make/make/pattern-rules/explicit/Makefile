RM = rm -rf

CC = gcc
CFLAGS = -O1 -Wall -Werror

TARGET = foobar
SRCS = foobar.c foo.c bar.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

.PHONY: clean

clean:
	$(RM) $(OBJS) $(TARGET)
