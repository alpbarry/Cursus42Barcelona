#include <stdio.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char bits;

	bits = 0;
	i = 0;
	while (i < 8)
	{
		bits = (bits << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (bits);
}

int	main(int n, char **str)
{
	unsigned char ori = (unsigned char)atoi(str[1]);
//	unsigned char ori = 32;
	printf("ori: %u\n", ori);
	printf("rev: %u\n", reverse_bits(ori));
}
