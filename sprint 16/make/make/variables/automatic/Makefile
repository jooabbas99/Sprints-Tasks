RM = rm -rf

COMPILE = $(CC) $(CFLAGS) -c
LINK = $(CC)

CC := gcc
CFLAGS := -O1 -Wall -Werror

TARGET := foobar
SRCS := foo.c bar.c foobar.c
OBJS := foo.o bar.o foobar.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK) $^ -o $@

foobar.o: foobar.c foobar.h
	$(COMPILE) $<

foo.o: foo.c foo.h
	$(COMPILE) $<

bar.o: bar.c bar.h
	$(COMPILE) $<

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
