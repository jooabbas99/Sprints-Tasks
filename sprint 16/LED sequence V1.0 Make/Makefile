# command configurations
SHELL = /bin/bash
RM = rm -rf

# Compiler config
CC = avr-gcc
CFLAGS = -O1 -Wall -Werror -gdwarf-2
LDFLAGS = 
CPPFLAGS = $(foreach directory, $(INDIRS), -I$(directory))

# List of source directories
INDIRS = $(sort $(dir $(HDRS)))

# folders configurations
BINDIR = bin
BUILDDIR = build

# Find all source files and header files
SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(SRCS))

# Microcontroller settings
MCU = atmega32a
COMPILE = $(CC) $(CFLAGS) -mmcu=$(MCU)
LINK = $(CC)
PROGRAMMER = usbasp
PORT = 
BAUD = 115200

# Target name
TARGET = $(BINDIR)/main

# Default target
.PHONY: all

all:$(BINDIR) $(BUILDDIR) $(TARGET).hex

$(BINDIR) $(BUILDDIR):
	mkdir -p $@

# This rule ensures that the build directory structure is created for each .o file.
$(BUILDDIR)/%.o: %.c
	@mkdir -p "$(dir $@)"
	$(COMPILE) $(CPPFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(LINK) $(OBJS) -o $(TARGET).elf

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

$(TARGET): $(TARGET).hex

.PHONY: clean
clean:
	$(RM) $(BUILDDIR)/*.o
	$(RM) $(OBJS) $(TARGET).elf $(TARGET).hex
cleanall:
	$(RM) $(BUILDDIR)
	$(RM) $(BINDIR)
	$(RM) $(OBJS) 
	$(RM) $(TARGET)


.PHONY: upload
upload: $(TARGET).hex
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex:i
