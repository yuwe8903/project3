/************************************************************
*  @file memory.h
*  @authour Yue Wei
*  @date Jan 31 2018
*************************************************************/
#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>
#include <stdlib.h>
/************************************************************
*  my_memmove() - Takes two byte pointer (one source and
*  	one destination) and a length of bytes to copy from
*  	the source location to the destination. The behavior
*  	should handle overlap of src and dst.
*  Inputs:
*  	unit8_t * src: Pointer starting byte
*  	unit8_t * dst: Pointer ending byte
*  	size_t length : Number of bytes to move
*  Return: Return a pointer to the destination(dst)
*************************************************************/
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/************************************************************
*  my_memcpy() - Takes two byte pointer (one source and
*       one destination) and a length of bytes to copy from
*       the source location to the destination. The behavior
*  	is undefined if there is overlap of src and dst.
*  Inputs:
*       unit8_t * src: Pointer starting byte
*       unit8_t * dst: Pointer ending byte
*       size_t length : Number of bytes to copy
*  Return: Return a pointer to the destination(dst)
*************************************************************/
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length);

/************************************************************
*  my_memset() - Takes a pointer to a source memory location,
*  	a length in bytes and set all locations of that
*       memory to give a value.
*  Inputs:
*       unit8_t * src: Pointer starting byte
*       size_t length: Number of locations
*  	uint8_t value: A value to be written to all location
*  Return: Return a pointer to the source(src)
*************************************************************/
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/************************************************************
*  my_memzero() - Takes a pointer to a source memory location,
*       a length in bytes and zero out all of the memory.
*  Inputs:
*       unit8_t * src: Pointer starting byte
*       size_t length: Number of locations
*  Return: Return a pointer to the source(src)
*************************************************************/
uint8_t * my_memzero(uint8_t * src, size_t length);

/************************************************************
*  my_reverse() - Takes a pointer to a source memory location,
*       a length in bytes and reverse the order of all of the
*  	bytes.
*  Inputs:
*       unit8_t * src: Pointer starting byte
*       size_t length: Number of locations
*  Return: Return a pointer to the source(src)
*************************************************************/
uint8_t * my_reverse(uint8_t * src, size_t length);

/************************************************************
*  reserve_words() - Takes number of words to allocate in
*       dynamic memory.
*  Inputs:
*       size_t length: Number of words to be reserved
*  Return: Return a pointer pointing to the top of the
*  	reserved heap
*************************************************************/
void * reserve_words(size_t length);

/************************************************************
*  free_words() - Free a dynamic memory allocation by
*       providing the pointer src to the function.
*  Inputs:
*       uint32_t * src: Pointing to the reverved dynamic
*       memory
*  Return: Return a 0 if free is successful or a 1 free is
*       if not successful
*************************************************************/
uint8_t free_words(void * src);

#endif /*_MEMORY_H_*/
