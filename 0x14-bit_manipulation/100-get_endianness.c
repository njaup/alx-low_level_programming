#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * get_endianness - checks the endianness
 * Return: ptr
 */
int get_endianness(void)
{
	uint16_t number = 0x0102;
	uint8_t *ptr = (uint8_t *)&number;

	return ((*ptr == 0x01) ? 0 : 1);
}
