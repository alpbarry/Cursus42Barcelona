#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ulstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		 if (s[i] >= 'a' && s[i] <= 'z')
		 {
			 s[i] -= 32;
			 ft_putchar(s[i]);
		 }
		 else if (s[i] >= 'A' && s[i] <= 'Z')
		 {
			 s[i] += 32;
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
	if (ac == 2)
		ulstr(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
