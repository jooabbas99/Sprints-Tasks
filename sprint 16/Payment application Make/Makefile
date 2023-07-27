SHELL = /bin/bash
RM = rm -rf

CC = gcc
CFLAGS = -O1 -Wall -Werror -gdwarf-2
LDFLAGS = -lm
CPPFLAGS = $(foreach directory, $(INDIRS), -I$(directory))

BINDIR = bin
BUILDDIR = build

# Find all source files and header files
SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(SRCS))

TARGET = $(BINDIR)/main

.PHONY: all

all: $(BINDIR) $(BUILDDIR) $(TARGET)

$(BINDIR) $(BUILDDIR):
	mkdir -p $@

# This rule ensures that the build directory structure is created for each .o file.
$(BUILDDIR)/%.o: %.c
	@mkdir -p "$(dir $@)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean cleanall run
run: $(TARGET)
	@$(SHELL) -c ./$(TARGET)

clean:
	$(RM) $(BUILDDIR)/*.o
	$(RM) $(OBJS) 
	$(RM) $(TARGET)


cleanall:
	$(RM) $(BUILDDIR)
	$(RM) $(BINDIR)
	$(RM) $(OBJS) 
	$(RM) $(TARGET)
