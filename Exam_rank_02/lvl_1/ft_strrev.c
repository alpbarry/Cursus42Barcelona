char	*ft_strrev(char *s)
{
	int	i;
	int	f;
	char	t;

	f = 0;
	while (s[f])
		f++;
	i = 0;
	while (i < f)
	{
		t = s[i];
		s[i] = s[f - 1];
		s[f - 1] = t;
		i++;
		f--;
	}
	return (s);
}
