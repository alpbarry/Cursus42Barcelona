#include "../includes/fdf.h"

int	get_height(char *filename)
{
	int		fd;
	int	height;
	char	*line;
	
	fd = open(filename, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
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
}

void	read_file(char *filename, t_fdf *data)
{
	int	fd;
	char	*line;
	int	i;

	data->height = get_height(filename);
	data->width = get_width(filename);

	data->z_matrix = (int **)malloc(sizeof(int *) * data->height + 1);
	i = 0;
	while(i < data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * data->width + 1);
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
