#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	repeat_alpha(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{

		if (s[i] >= 'a' && s[i] <= 'z')
		{
			j = 0;
			j = s[i] + 1 - 97;
			while (j--)
				ft_putchar(s[i]);
		}
		else if (s[i] >= 'A' && s[i] <= 'z')
		{
			j = 0;
			j = s[i] + 1 - 65;
			while (j--)
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
		repeat_alpha(av[1]);
	ft_putchar('\n');
	return (0);
}
