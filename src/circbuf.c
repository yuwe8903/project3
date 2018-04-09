
/************************************************************
*  @file circbuf.c
*  @description This is the function defination for the
*       function declaraion in circbuf.h file
*  @author Yue Wei
*  @date Feb 25 2018
*************************************************************/
#include <circbuf.h>
#include <stdint.h>

CB_e CB_init(CB_t * cbuf, size_t length)
{
	cbuf->base = (int8_t *) malloc(length*sizeof(cbuf));
	if(! cbuf->base)
	{
		return CB_ERROR;
	}
	cbuf->length = length;
	cbuf->head = cbuf->base;
	cbuf->tail = cbuf->base;
	cbuf->count = 0;
	return CB_SUCCESS;
}
CB_e CB_buffer_add_item(CB_t * cbuf, uint8_t data)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return CB_NULL_POINTER;
	}
	/*check if CB is full*/
	if(CB_is_full(cbuf) == CB_FULL)
	{
		return CB_FULL;
	}
	*cbuf->head = data;
	if(cbuf->head == (cbuf->base + (cbuf->length -1) ))
	{
		cbuf->head = cbuf->base;
		cbuf->count ++;
		return CB_SUCCESS;
	}
	else
	{
		cbuf->head ++;
		cbuf->count ++;
		return CB_SUCCESS;
	}

}
CB_e CB_buffer_remove_item(CB_t * cbuf, uint8_t *data)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return CB_NULL_POINTER;
	}
	/*check if CB is empty*/
	if(CB_is_empty(cbuf) == CB_EMPTY)
	{
		return CB_EMPTY;
	}
	*data = *cbuf->tail;
	if(cbuf->tail == (cbuf->base + (cbuf->length -1) ))
	{
		cbuf->tail = cbuf->base;
		cbuf->count --;
		return CB_SUCCESS;
	}
	else
	{
		cbuf->tail ++;
		cbuf->count --;
		return CB_SUCCESS;
	}
}
CB_e CB_is_full(CB_t * cbuf)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return CB_NULL_POINTER;
	}
	if((cbuf->tail == cbuf->head +1) || (cbuf->head == cbuf->tail + (cbuf->length - 1)))
	{
		return CB_FULL;
	}
	else
	{
		return CB_NOT_FULL;
	}
}
CB_e CB_is_empty(CB_t * cbuf)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return CB_NULL_POINTER;
	}
	if(CB_is_full(cbuf) == CB_FULL)
	{
		return CB_NOT_EMPTY;
	}
	if(cbuf->tail == cbuf->head)
	{
		return CB_EMPTY;
	}
	else
	{
		return CB_NOT_EMPTY;
	}
}
CB_e CB_peek(CB_t * cbuf, uint8_t num, uint8_t * peek)
{
	if(! cbuf || ! cbuf->head || ! cbuf->tail || ! cbuf->base)
	{
		return CB_NULL_POINTER;
	}
	if((cbuf->head - cbuf->base) >= num)
	{
	*peek = *cbuf->head-num;
	}
	else
	{
	num = num - (cbuf->head - cbuf->base);
	*peek = * cbuf->base + (cbuf->length - num);
	}
	return CB_SUCCESS;

}
