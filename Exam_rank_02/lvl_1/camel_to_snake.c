#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
		
void	cts(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
			ft_putchar('_');
		}
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		cts(av[1]);
	ft_putchar('\n');
	return (0);
}
