#include <stdlib.h>

int	*ft_range(int s, int e)
{
	int	i;
	int	*res;
	int	len;
	
	i = 0;
	if (s > e)
	{
		len = s - e + 2;
		res = malloc(sizeof(int) * (len));
		while (s >= e)
		{
			res[i] = s;
			i++;
			s--;
		}
	}
	else
	{
		len = e - s + 2;
		res = malloc(sizeof(int) * (len));
		while (e >= s)
		{
			res[i] = s;
			s++;
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int main(void)
{
	int *cur = ft_range(1, 3);
	
	int i = 0;
	while(i < 9)
	{
		printf("%d ,", cur[i]);
		i++;
	}
	return(0);
}*/
