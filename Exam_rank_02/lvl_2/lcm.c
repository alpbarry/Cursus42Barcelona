unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b = 0)
		return (0);
	if (a > b)
		n = 1;
	else
		n = b;
	while (1)
	{
		if (a % n == 0 && b % n == 0)
			return (n);
		++n;
	}
}
