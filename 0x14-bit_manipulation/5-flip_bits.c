#include "main.h"
/**
 * flip_bits - returns the no. of bits needed
 * to flip to get from one no. to another
 * @n: first no.
 * @m: second no.
 * Return: no. of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int nbits;
for (nbits = 0; n || m; n >>= 1, m >>= 1)
{
if ((n & 1) != (m & 1))
nbits++;
}
return (nbits);
}
