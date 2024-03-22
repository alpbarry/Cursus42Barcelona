/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:01:01 by alphbarr          #+#    #+#             */
/*   Updated: 2024/03/20 20:15:52 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* Despues de extraer la linea leida, ya no necesitaremos esos caracteres.
 * Esta funcion limpia de stash solo los caracteres que
 * no han sido devueltos al final de get_next_line
 * que permanece en nuestro stash estatico. */

t_list	*create_node(t_list **stash, size_t size)
{
	t_list	*clean_node;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
	{
		free_stash(*stash);
		free(clean_node);
		*stash = NULL;
		stash = NULL;
		return (NULL);
	}
	clean_node->content = malloc(size);
    if (clean_node->content == NULL)
    {
        free(clean_node);
        free_stash(*stash);
        *stash = NULL;
        stash = NULL;
        return (NULL);
    }
	clean_node->next = NULL;
	return (clean_node);
}

void	clean_stash(t_list **stash, int i, int j)
{
	t_list	*last;
	t_list	*clean_node;
	size_t	size;

	last = ft_lst_get_last(*stash);
	last = ft_lst_get_last(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	size = sizeof(char) * (ft_strlen(last->content) - i + 1);
	clean_node = create_node(stash, size);
	if (clean_node == NULL)
		return ;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	int i;
	t_list *last;
	t_list *new_node;
	size_t size;

	size = sizeof(char) * (readed + 1);
	new_node = create_node(stash, size);
	if (new_node == NULL)
	{
		free(buf);
		return ;
	}
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
		*stash = new_node;
	else
	{
		last = ft_lst_get_last(*stash);
		last->next = new_node;
	}
}