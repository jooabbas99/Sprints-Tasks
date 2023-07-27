RM := rm -rf
COMPILE = $(CC) $(CFLAGS) -c
LINK = $(CC)
DISASSEMBLE = objdump -d
CC := gcc
CFLAGS := -O1 -Wall -Werror
SRCS := main.c hello.c
ASMS = $(SRCS:.c=.s)
OBJS = $(SRCS:.c=.o)
HDRS = $(SRCS:.c=.h)
TARGET := hello
all: $(TARGET) $(TARGET).s
$(TARGET): $(OBJS)
	$(LINK) $^ -o $@ 
%.o: %.c
	$(COMPILE) $<
$(TARGET).s: $(TARGET)
	$(DISASSEMBLE) $< > $@
.PHONY: clean
clean:
	$(RM) -r $(ASMS) $(TARGET) $(OBJS)