/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:55:41 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/22 12:30:02 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	if (line == NULL)
	{
		free_stash(stash);
		stash = NULL;
		return NULL;
	}
	clean_stash(&stash, i, j);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/* Extraer todos los caracteres de stash y guardarlos en line.
 * parando cuando se encuentre un \n */

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open("text/1char.txt", O_RDONLY, 0777);
	line = get_next_line(fd);
	while (!line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}*/
