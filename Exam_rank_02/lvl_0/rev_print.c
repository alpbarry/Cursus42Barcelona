#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rev_print(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i)
	{
		ft_putchar(s[i - 1]);
		i--;
	}
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_print(av[1]);
	else
		ft_putchar ('\n');
	return (0);
}
