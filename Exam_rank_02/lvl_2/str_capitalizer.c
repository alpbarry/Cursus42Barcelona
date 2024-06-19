#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	low(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
}

void	str_cap(char *s)
{
	int	i;

	i = 0;
	low(s);
	while (s[i])
	{
		if (s[0] >= 'a' && s[0] <= 'z')
		{
			s[i] -= 32;
			ft_putchar(s[i]);
		}
		else if	((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] == ' ' || s[i +1] == '\t') && (s[i - 1] == ' ' || s[i - 1] == '\t'))
		{
			s[i] -= 32;
			ft_putchar(s[i]);
		}
		else if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] == ' ' || s[i - 1] == '\t'))
		{
			s[i] -= 32;
			ft_putchar(s[i]);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	int	i = 1;
	
	if (ac >= 2)
	{
		while (av[i])
		{
			str_cap(av[i]);
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
