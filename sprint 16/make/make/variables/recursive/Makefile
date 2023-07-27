RM = rm -rf

COMPILE = $(CC) $(CFLAGS) -c
LINK = $(CC)

CC := gcc
CFLAGS := -O1 -Wall -Werror

TARGET := foobar
SRCS := foo.c bar.c foobar.c
HDRS := foo.h bar.h foobar.h
OBJS := foo.o bar.o foobar.o

all: $(TARGET)

$(TARGET): $(OBJS) $(HDRS)
	$(LINK) $(OBJS) -o $(TARGET)

foobar.o: foobar.c foobar.h
	$(COMPILE) foobar.c

foo.o: foo.c foo.h
	$(COMPILE) foo.c

bar.o: bar.c bar.h
	$(COMPILE) bar.c

.PHONY: clean

clean:
	$(RM) $(OBJS) $(TARGET)
