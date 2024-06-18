#include <stdlib.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *s)
{
	int	i;
	int	j;
	int	k;
	int	wc;
	char	**res;

	i = 0;
	j = 0;
	k = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && (s[i] >= 9 && s[i] <= 13))
			i++;
		if (s[i])
			wc++;
		while (s[i] && !(s[i] >= 9 && s[i] <= 13))
			i++;
	}
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] >= 9 && s[i] <= 13))
			i++;
		j = i;
		while (s[i] && !(s[i] >= 9 && s[i] <= 13))
			i++;
		if (i > j)
		{
			res[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(res[k], &s[j], i -j);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}
