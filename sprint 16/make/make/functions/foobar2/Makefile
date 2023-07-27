SHELL = /bin/bash
RM = rm -rf

CC = gcc
CFLAGS = -Wall -Werror -gdwarf-2
LDFLAGS =
CPPFLAGS = -I$(INC_DIR)

SRC_DIR = src
INC_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
HDRS = $(wildcard $(INC_DIR)/*.h)
# OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %.c,%.o,$(SRCS))

TARGET = $(lastword $(subst /, ,$(CURDIR)))

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
