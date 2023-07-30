# Toolchain and options
DEVICE = cortex-m4 # The target architecture for the compiler.
CC = arm-none-eabi-gcc #The C compiler executable
CFLAGS =  -mthumb -O1 -Wall # Compiler flags used during compilation
LDFLAGS =

# Folders configurations
BINDIR = bin # The directory where the final output (main.hex) will be placed
BUILDDIR = build # The directory where object files will be placed during the build process

# Find all source files and header files
SRCS := $(shell find . -name '*.c') #locate all C source
HDRS := $(shell find . -name '*.h') #locate all H Files
OBJS := $(SRCS:%.c=$(BUILDDIR)/%.o) # the source file paths to corresponding object file paths within the build directory

# Microcontroller settings
COMPILE = $(CC) -mcpu=$(DEVICE) $(CFLAGS)
LINK = $(CC) $(LDFLAGS) -specs=nosys.specs

TARGET = $(BINDIR)/main

# Default target
.PHONY: all
all: $(BINDIR) $(BUILDDIR) $(TARGET).hex

# Create output and build directories if they don't exist
$(BINDIR) $(BUILDDIR):
	mkdir -p $@

# Build object files
$(BUILDDIR)/%.o: %.c $(HDRS)
	@mkdir -p "$(dir $@)"
	$(COMPILE) -c $< -o $@

# Link object files to create the ELF file
$(TARGET).elf: $(OBJS)
	$(LINK) $^ -o $@

# Generate the .hex file from the ELF file
$(TARGET).hex: $(TARGET).elf
	arm-none-eabi-objcopy -O ihex $< $@

# If someone runs `make $(TARGET)`, build the .hex file
$(TARGET): $(TARGET).hex

# Clean the project by removing generated files
.PHONY: clean
clean:
	$(RM) $(BUILDDIR)/*.o $(TARGET).elf $(TARGET).hex

# Completely clean the project by removing all generated files and directories
.PHONY: cleanall
cleanall:
	$(RM) -r $(BINDIR) $(BUILDDIR)
