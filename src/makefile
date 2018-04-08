#------------------------------------------------------------
# Use: make [targets][overrides]
# Targets :
#	.o - Builds object files from corresponding .c file
#	all - Builds and links all source file
#	clean - Remove all generated files
# Overrides:
#	CPU_KL25Z - ARM Cortex Architecture (cortex-moplus)
#	CPU_BBB - ARM Cortex Architecture (cortex-a8)
#	ARCH - ARM Architecture (arm, thumb)
#	SPECS - Specs file to give the linker (nosys.specs)
# , -MAP=$(TARGET).map,-L[DIR] -I[LIB] -T=MKL25Z128xxx4_flash.ld
#-------------------------------------------------------------
include sources.mk

#Overrides
CPU_KL25Z = cortex-m0plus
CPU_BBB = cortex-a8
ARCH = thumb
SPECS = nosys.specs
CSTD = c99
#Compilation
LD = arm-none-eabi-ld
AS = arm-none-eabi-as
TARGET = project3

ifeq ($(PLATFORM),HOST)
CC = gcc
CFLAGS = -Werror -g -o0 -std=$(CSTD)\
-DBBB_PLATFORM
INCLUDES=$(INCLUDE_COMMON)

else ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabihf-gcc
CFLAGS = -Werror -g -o0 -std=$(CSTD)\
-mcpu=$(CPU_BBB) -m$(ARCH) \
-DBBB_PLATFORM
INCLUDES = $(INCLUDE_COMMON) $(INCLUDE_CMSIS)

else ifeq ($(PLATFORM),KL25Z)
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=$(CPU_KL25Z) -m$(ARCH) \
-specs=$(SPECS) -Werror -g -o0 -std=$(CSTD) \
-DKL25Z_PLATFORM
INCLUDES = $(INCLUDE_COMMON) $(INCLUDE_CMSIS) $(INCLUDE_KL25Z)
LDFLAGS = -T ../platform/MKL25Z128xxx4_flash.ld \
-Xlinker -Map=$(TARGET).map
endif

ifeq ($(PLATFORM),HOST)
OBJS = $(SRCS:.c=.o)
else ifeq ($(PLATFORM),BBB)
OBJS = $(SRCS:.c=.o) $(KL25Z_SRCS:.c=.o)
else ifeq ($(PLATFORM),KL25Z)
OBJS = $(SRCS:.c=.o) $(KL25Z_SRCS:.c=.o) $(S_SRCS:.S=.o)
endif

%.o : %.c
	-@echo 'Creating .o file:'
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

%.i : %.c
	-@echo 'Creating .i file:'
	$(CC) -E $< $(CFLAGS) $(INCLUDES) -o $@

%.asm : %.c
	-@echo 'Creating .asm file:'
	$(CC) -S $< $(CFLAGS) $(INCLUDES) -o $@

%.o : %.S
	-@echo 'Creating .o file:'
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

%.d : %.c
	-@echo 'Creating .d file:'
	$(CC) -M $< $(CFLAGS) $(INCLUDES) -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -DPROJECT3 -o $(TARGET).elf
.PHONY: clean
clean:
	rm -f *.asm *.i *.o *.d $(TARGET) $(TARGET).map $(TARGET).elf



