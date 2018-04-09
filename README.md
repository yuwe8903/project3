Project3
Yue Wei

The following table shows profiling value in clock cycles (ticks) on FRDM board
FRDM Board		10bytes		100bytes	1000bytes	5000bytes
Lib memmove		149		959		9059		45049
my_memmove		430		3488		34088		170221
my_memmove(-O3)		180		1213		11563		57605
memmove_dma		382		562		2362		10362

Lib memset		111		741		7041		3504
my_memset		391		3181		31081		155213
my_memset(-O3)		153		1053		10053		57605
memset_dma		562		725		725		543	

The above table shows that the Library memmove and memset take the least amount of time. my memmove and memset functions take the most amount of time, but with level three (-O3) optimization, it's much faster. dma is slower at 10 bytes, but it is much faster as the number of bytes increases. For 5000 bytes, dma is the fastest one.

This project also creates interface between spi and nordic, and the two drivers are included in the src file.

Command "make build PLATFORM=KL25Z" will create project3.elf file for KL25Z

