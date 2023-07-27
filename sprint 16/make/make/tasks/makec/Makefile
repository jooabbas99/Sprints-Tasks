SHELL = /bin/bash
RM = rm -rf

CC = gcc
CFLAGS = -O1 -Wall -Werror -gdwarf-2
LDFLAGS = -lm
CPPFLAGS = -I$(INCDIR)

BINDIR = bin
BUILDDIR = build

SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(notdir $(SRCS)))

TARGET = $(BINDIR)/$(lastword $(subst /, ,$(CURDIR)))

.PHONY: all

all: $(BINDIR) $(BUILDDIR) $(TARGET)

$(BINDIR) $(BUILDDIR):
	mkdir -p $@

$(BUILDDIR)/%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	
.PHONY: clean cleanall

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

cleanall:
	$(RM) $(BUILDDIR)
	$(RM) $(BINDIR)
