SHELL = /bin/bash
RM := rm -rf

# Compiler config
CC = avr-gcc
CFLAGS = -O1 -Wall -Werror
LDFLAGS = 
CPPFLAGS = $(foreach directory, $(INDIRS), -I$(directory))

# List of source directories
INDIRS = $(sort $(dir $(HDRS)))

# Find all source files and header files
SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
OBJS = $(SRCS:.c=.o)

# Microcontroller settings
MCU = atmega32a
COMPILE = $(CC) $(CFLAGS) -mmcu=$(MCU)
LINK = $(CC)
PROGRAMMER = usbasp
PORT = 
BAUD = 115200

# Target name
TARGET = main

# Default target
.PHONY: all
all: $(TARGET).hex

%.o: %.c
	$(COMPILE) $(CPPFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(LINK) $(OBJS) -o $(TARGET).elf

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

$(TARGET): $(TARGET).hex

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET).elf $(TARGET).hex

.PHONY: compile
compile: $(TARGET)

.PHONY: upload
upload: $(TARGET).hex
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex:i
