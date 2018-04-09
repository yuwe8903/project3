SRCS =  main.c \
	project3.c \
	memory.c \
	profiling.c
S_SRCS = startup_MKL25Z4.S
KL25Z_SRCS = dma.c \
	     system_MKL25Z4.c \
	     spi.c \
	     nordic.c \
	     uart.c \
	     gpio.c
INCLUDE_COMMON = -I ../include/common
INCLUDE_CMSIS = -I ../include/CMSIS
INCLUDE_KL25Z = -I ../include/kl25z

