RM = rm -rf

CC = gcc
CFLAGS = -O1 -Wall -Werror

TARGET = foobar
SRCS = foobar.c foo.c bar.c
HDRS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

.PHONY: clean

clean:
	$(RM) $(OBJS) $(TARGET)
