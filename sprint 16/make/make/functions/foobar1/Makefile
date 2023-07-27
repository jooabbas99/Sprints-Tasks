SHELL = /bin/bash
RM = rm -rf

CC = gcc
CFLAGS = -O1 -Wall -Werror -gdwarf-2
LDFLAGS =
CPPFLAGS =

SRCS = $(wildcard *.c)
HDRS = $(wildcard *.h)
OBJS = $(SRCS:.c=.o)

TARGET = foobar1

.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	
.PHONY: run clean

run: $(TARGET)
	@$(SHELL) -c ./$(TARGET)

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
