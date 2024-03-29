#include <unistd.h>
char	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'z' || s[i] == 'Z')
			ft_putchar(s[i] - 25);
		else if ((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && 			s[i] <= 'Y'))
			ft_putchar(s[i] + 1);
		else
			ft_putchar(s[i]);
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return (0);
}
