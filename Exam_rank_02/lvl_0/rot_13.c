#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	rot_13(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
		{
			s[i] = s[i] + 13;
			ft_putchar(s[i]);
		}
		else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
		{
			s[i] = s[i] - 13;
			ft_putchar(s[i]);
		}
		else
			ft_putchar (s[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
