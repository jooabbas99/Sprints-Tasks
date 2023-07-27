MAKEFLAGS = --no-print-directory
SHELL = /bin/bash
RM = rm -rf

GREEN = \033[1;32m
NORMAL = \033[0m
CLANGDIR = .clang
COMPILEDB = $(CLANGDIR)/compile_commands.json

CC = gcc
CFLAGS = -O1 -Wall -Werror -gdwarf-2
LDFLAGS = -lm
CPPFLAGS = $(foreach directory,$(INCDIRS),-I$(directory))

INCDIRS = $(sort $(dir $(HDRS)))

BINDIR = .bin
BUILDDIR = .build

SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
OBJS = $(patsubst %.c,.build/%.o,$(notdir $(SRCS)))

TARGET = .bin/debug
CMD = ./$(TARGET)
	
define Echo
	@echo -e "$(GREEN)$(1)$(NORMAL) $(2)"
endef

.PHONY: all

all: message .bin .build $(TARGET)

.PHONY: message

message:
	$(call Echo,    Building, $(TARGET))

.bin .build:
	mkdir -p $@

.build/%.o: */%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
	@make compiledb

$(COMPILEDB):
	# Install `pipx`: `sudo apt install pipx`
	# Install `compiledb`: `pipx install compiledb`
	compiledb -n -o $@ make

compiledb:
	@mkdir -p $(CLANGDIR)
	@make -B $(COMPILEDB)

.PHONY: lint

lint:
	$(call Echo,    Linting, $(SRCS) $(HDRS))
	@clang-tidy -p $(CLANGDIR) $(SRCS) $(HDRS)

.PHONY: run

run: all
	$(call Echo,    Running, $(TARGET))
	@$(SHELL) -c ./$(TARGET)

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

.PHONY: cleanall

cleanall:
	$(RM) $(BUILDDIR)
	$(RM) $(BINDIR)
