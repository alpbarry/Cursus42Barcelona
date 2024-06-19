#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int s, int e)
{
	int	i;
	int	len;
	int	*res;

	i = 0;
	if (e > s)
	{
		len = e - s + 1;
		res = malloc(sizeof(int) * len);
		while (e >= s)
		{
			res[i] = e;
			e--;
			i++;
		}
	}
	else
	{
		len = s - e + 1;
		res = malloc(sizeof(int) * len);
		while (s >= e)
		{
			res[i] = e;
			e++;
			i++;
		}
	}
	return (res);
}
/*
int main(void)
{

	int	*arr = ft_rrange(1, 3);
	int i = 0;
	while(i < 4)
	{
		printf("%i\n", arr[i]);
		i++;
	}
	return(0);
}*/
