#include "../includes/fdf.h"

int	ft_wordcount(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	get_height(char *filename)
{
	int		fd;
	int	height;
	char	*line;
	
	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int	width;
	int	fd;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY, 0);
	get_next_line(fd);
	width = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char 	**nums;
	int	i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *filename, t_fdf *data)
{
	int	fd;
	char	*line;
	int	i;

	data->height = get_height(filename);
	data->width = get_width(filename);

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
	{
		ft_printf("%s", "Error: Failed to allocate memory for z_matrix\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while(i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->z_matrix[i])
		{
			ft_printf("%s", "Error: Failed to allocate memory for z_matrix[%d]\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
