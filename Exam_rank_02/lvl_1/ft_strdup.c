#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int	i;
	int	len;
	char	*r;

	len = 0;
	while (s[len])
		len++;
	r = malloc(sizeof(*r) * (len + 1));
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}
