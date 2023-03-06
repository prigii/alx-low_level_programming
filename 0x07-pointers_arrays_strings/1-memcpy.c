#include "main.h"
/**
 * _memcpy - copies memory area,
 * @dest: destination memory area.
 * @src: source memory area.
 * @n: bytes filled.
 * Return: the pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
char *dest1 = dest;
char *src1 = src;

for (; n != 0; dest1++, n--, src1++)
*dest1 = *src1;
return (dest);
}
