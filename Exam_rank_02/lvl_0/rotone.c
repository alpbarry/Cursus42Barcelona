#include <unistd.h>

void	ft_putchar(char  c)
{
	write (1, &c, 1);
}

void	rotone(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && s[i] <= 'Y'))
		{
			s[i] += 1;
			ft_putchar(s[i]);
		}
		else if (s[i] == 'z' || s[i] == 'Z')
		{
			s[i] -= 25;
			ft_putchar(s[i]);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	else
		ft_putchar('\n');
	ft_putchar('\n');
	return (0);
}
