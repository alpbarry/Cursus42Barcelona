int	max(int	*t, unsigned int len)
{
	unsigned int	i;
	int	r;

	i = 0;
	if (len == 0)
		return (0);
	r = t[i];
	while (i < len)
	{
		if (r < t[i])
			r = t[i];
		i++;
	}
	return (r);
}
