RM = rm -rf

COMPILE = $(CC) $(CFLAGS) $(CPPFLAGS) -c
LINK = $(CC) $(LDFLAGS)

CC := gcc
DISASSEMBLE := objdump -d
CFLAGS := -O1 -Wall -Werror
CPPFLAGS :=
LDFLAGS := -lm

TARGET := target
SRCS := foo.c bar.c foobar.c
ASMS := foo.s bar.s foobar.s
OBJS := foo.o bar.o foobar.o

all: $(TARGET) $(ASMS) $(TARGET).s

$(TARGET): $(OBJS)
	$(LINK) $^ -o $@

foobar.o: foobar.c foobar.h
	$(COMPILE) $<

foo.o: foo.c foo.h
	$(COMPILE) $<

bar.o: bar.c bar.h
	$(COMPILE) $<

foo.s: foo.o
	$(DISASSEMBLE) $< > $@

bar.s: bar.o
	$(DISASSEMBLE) $< > $@

foobar.s: foobar.o
	$(DISASSEMBLE) $< > $@

$(TARGET).s: $(TARGET)
	$(DISASSEMBLE) $< > $@

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
	$(RM) $(TARGET).s
	$(RM) $(ASMS)
