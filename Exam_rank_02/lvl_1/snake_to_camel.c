#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	stc(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[0] >= 'A' && s[0] <= 'Z')
		{
			s[0] += 32;
			i++;
		}
		if (s[i] == '_')
		{
			i++;
			s[i] -= 32;
		}
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		stc(av[1]);
	ft_putchar('\n');
	return (0);
}
