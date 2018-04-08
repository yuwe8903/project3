
/***************************************************************
*  @file circbuf.h
*  @description declare macros and functions for  circbuf.c
*  @author Yue Wei
*  @date Feb 25 2018
****************************************************************/
#ifndef _CIRCBUF_H_
#define _CIRCBUF_H_
#include <stdint.h>
#include <stdlib.h>


typedef struct{
	uint8_t * base;
	uint8_t * head;
	uint8_t * tail;
	size_t length;
	size_t count;
}CB_t;

typedef enum{
	CB_SUCCESS = 0,
	CB_ERROR = -1,
	CB_NULL_POINTER = -2,
	CB_ZERO_LENGTH = -3,
	CB_FULL = 1,
	CB_NOT_FULL = 2,
	CB_EMPTY = 3,
	CB_NOT_EMPTY = 4,
}CB_e;

/************************************************************
*  CB_init() - Initialize the position of head, tail,
*  		length, count.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*       size_t length: Size of the CB
*  Return: The status of the CB.
*************************************************************/
CB_e CB_init(CB_t * cbuf, size_t length);

/************************************************************
*  CB_destroy() - free the CB memory.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*  Return: Status of the CB.
*************************************************************/
__attribute__((always_inline)) inline CB_e CB_destroy( CB_t * cbuf )
{
	free(cbuf->base);
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
		{
			return CB_NULL_POINTER;
		}
	return CB_SUCCESS;
}

/************************************************************
*  CB_buffer_add_item() - Add data to the buffer.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*       uint8_t data: The data that is being added to the CB
*  Return: The status of the CB.
*************************************************************/
CB_e CB_buffer_add_item(CB_t * cbuf, uint8_t data);

/************************************************************
*  CB_buffer_remove_item() - Remove data from the buffer.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*       uint8_t * data: The data that is being removed from CB
*  Return: The status of the CB.
*************************************************************/
CB_e CB_buffer_remove_item(CB_t * cbuf, uint8_t *data);

/************************************************************
*  CB_is_full() - Check if the CB is full.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*  Return: The status of the CB.
*************************************************************/
CB_e CB_is_full(CB_t * cbuf);

/************************************************************
*  CB_is_empty() - Check if the CB is empty.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*  Return: The status of the CB.
*************************************************************/
CB_e CB_is_empty(CB_t * cbuf);

/************************************************************
*  CB_peek() - Peek into the CB in accordance to the Head.
*  Inputs:
*       CB_t * cbuf: Pointer to the CB
*       uint8_t num: In accordance to the Head,
*       			 num = 0 means peek at the head
*       			 num = 1 means peek at the head-1
*       			 		(the one before head)
*       			 num = 2 means peek at the head-2
*       uint8_t * peek: Store the peeked value into peek
*  Return: The status of the CB.
*************************************************************/
CB_e CB_peek(CB_t * cbuf, uint8_t num, uint8_t * peek);

#endif /* _CIRCBUF_H_ */
