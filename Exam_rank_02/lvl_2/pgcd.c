#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a, int b)
{
	int	res;

	if (a > b)
		res = a;
	else
		res = b;
	while (1)
	{
		if (a % res == 0 && b % res == 0)
		{
			printf("%d", res);
			break;
		}
		res--;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	int	a = atoi(av[1]);
	int	b = atoi(av[2]);
	if (ac == 3)
		pgcd(a, b);
	else
		printf("\n");
	return (0);
}
