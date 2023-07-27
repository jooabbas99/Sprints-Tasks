RM := rm -rf

CC := gcc
CFLAGS := -O1 -Wall -Werror

SRC := hello.c
TARGET := hello_world

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean

clean:
	$(RM) $(TARGET)
