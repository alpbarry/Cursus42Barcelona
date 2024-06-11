size_t	ft_strcspn(const char *s, const char *r)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (r[j])
		{
			if (s[i] == r[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
