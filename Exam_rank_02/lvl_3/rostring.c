#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*epur(char *s)
{
	int	i;
	int	j;
	int	flg;
	int	len;
	char	*res;
	
	len = 0;
	i = 0;
	flg = 0;
	j = 0;
	while (s[len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			flg = 1;
		else
		{
			if (flg)
				res[j++] = ' ';
			flg = 0;
			res[j++] = s[i];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	rost(char *s)
{
	int	i;
	int	j;
	char *res;
	int	len;
	int start;
	int	end;
	char *t;
	int	k;
	char	*clean;

	clean = epur(s);
	if (!clean)
		return ;
	i = 0;
	len = 0;
	epur(s);
	while (clean[len])
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
	{
		free(clean);
		return ;
	}
	while (clean[i] == ' ' || clean[i] == '\t')
		i++;
	start = i;
	while (!(clean[i] == ' ' || clean[i] == '\t') && clean[i])
		i++;
	end = i;
	t = malloc(sizeof(char) * (end - start + 1));
	if (!t)
	{
		free(clean);
		free(res);
		return ;
	}
	j = 0;
	while (start < end)
	{
		t[j] = clean[start];
		j++;
		start++;
	}
	t[j] = '\0'; 
	k = 0;
	while (clean[i] && (clean[i] == ' ' || clean[i] == '\t'))
		i++;
	while (clean[i])
	{
		res[k] = clean[i];
		k++;
		i++;
	}
	if (k > 0 && res[k - 1] == ' ')
		k--;
	res[k] = '\0';
	if (k > 0)
		res[k++] = ' ';
	j = 0;
	while (t[j])
	{
		res[k] = t[j];
		j++;
		k++;
	}
	res[k] = '\0';
	i = 0;
	while (res[i])
	{
		ft_putchar(res[i]);
		i++;
	}
	free(res);
	free(t);
	free(clean);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rost(av[1]);
	ft_putchar('\n');
	return (0);
}
