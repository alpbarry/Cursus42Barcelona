#include <stdio.h>
#include <stdlib.h>

void	do_op(char *f, char *s, char *t)
{

	if(s[0] == '+')
		printf("%d", atoi(f) + atoi(t));
	if(s[0] == '-')
		printf("%d", atoi(f) - atoi(t));
	if(s[0] == '*')
		printf("%d", atoi(f) * atoi(t));
	if(s[0] == '/')
		printf("%d", atoi(f) / atoi(t));
	if(s[0] == '%')
		printf("%d", atoi(f) % atoi(t));
	printf("\n");
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(av[1], av[2], av[3]);
	else
		printf("\n");
	return (0);
}
