#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
# PLATFORM = MSP432

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
TARGET = FinalC1_Leonov

ifeq ($(PLATFORM),MSP432)
# Architectures Specific Flags
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CPPFLAGS = -D$(PLATFORM) -DVERBOSE -DCOURSE1
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall $(INCLUDES) $(CPPFLAGS)
	SOURCES = $(SOURCES_MSP432)
else
	CC = gcc
	CPPFLAGS = -D$(PLATFORM) -DVERBOSE -DCOURSE1
	CFLAGS = $(CPPFLAGS) -Wall $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SOURCES = $(SOURCES_HOST)
endif

OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.asm)
COMP = $(SOURCES:.c=.i)
DEPE = $(SOURCES:.c=.d)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@
%.i : %.c
	$(CC) -E $< $(CFLAGS) -o $@
%.asm: %.c
	$(CC) -S $< $(CFLAGS) -o $@
%.d: %.c
	$(CC) -MM $< $(CFLAGS) -o $@

# .PHONY: compile-all
# build: compile-all

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPE) $(ASMS) $(COMP)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
ifeq ($(PLATFORM),MSP432)
	arm-none-eabi-size $(TARGET).out 
endif

.PHONY: compile-all
compile-all:
	$(CC) -c $(CFLAGS) $(SOURCES)

.PHONY: clean
clean:
	rm -f $(TARGET).out $(TARGET).map *.asm *.i *.d *.o
	rm -f src/$(TARGET).out src/$(TARGET).map src/*.asm src/*.i src/*.d src/*.o



	