RM = rm -rf

CC = gcc
DISASSEMBLE = objdump -d
CFLAGS = -O1 -Wall -Werror
CPPFLAGS = 
LDFLAGS = -lm

TARGET = target
SRCS = foobar.c foo.c bar.c
HDRS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)
ASMS = $(SRCS:.c=.s)

all: $(TARGET) $(ASMS) $(TARGET).s

%.s: %.o
	$(DISASSEMBLE) $< > $@

$(TARGET): $(OBJS) $(HDRS)
	$(CC) $(LDFLAGS) $^ -o $@

$(TARGET).s: $(TARGET)
	$(DISASSEMBLE) $< > $@

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
	$(RM) $(TARGET).s
	$(RM) $(ASMS)
