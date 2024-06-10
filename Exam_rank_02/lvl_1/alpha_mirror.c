#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	alpha_mirror(char *s)
{
	int	i;
	int	n;

	i = 0;
	while (s[i])
	{

		if (s[i] >= 'a' && s[i] <= 'm')
		{
			n = s[i] - 'a';
			s[i] = 'z' - n;
			ft_putchar(s[i]);
		}
		else if (s[i] >= 'n' && s[i] <= 'z')
		{
			n = 'z' - s[i];
			s[i] = 'a' + n;
			ft_putchar(s[i]);
		}
		else if (s[i] >= 'A' && s[i] <= 'M')
		{
			n = s[i] - 'A';
			s[i] = 'Z' - n;
			ft_putchar(s[i]);
		}
		else if (s[i] >= 'N' && s[i] <= 'Z')
		{
			n = 'Z' - s[i];
			s[i] = 'A' + n;
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
		alpha_mirror(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
