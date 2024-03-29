#include <unistd.h>
char	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	j = 0;

	if (argc == 4 && !argv[2][1] && !argv[3][1])
	{
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
			{
				argv[1][i] = argv[3][0];
				j++;
			}
			i++;
		}
		i = 0;
		while (argv[1][i])
		{
			ft_putchar(argv[1][i]);
			i++;
		}
		if (j == 0)
			ft_putchar('\n');
	}
	else	
		ft_putchar('\n');
	return (0);
}
