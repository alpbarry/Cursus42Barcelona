/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:57:40 by alphbarr          #+#    #+#             */
/*   Updated: 2024/04/24 10:57:43 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"

int c_format(char *f)
{
    int i;

    i = 0;
    while (f[i])
        i++;
    if (i-- < 5)
        return (0);
    if (f[i--] != 'f')
        return (0);
    if (f[i--] != 'd')
        return (0);
    if (f[i--] != 'f')
        return (0);
    if (f[i--] != '.')
        return (0);
    return (1);
}

void free_text(t_text **t)
{
    t_text *a;
    t_text *tmp;

    if (!*t)
        return ;
    a = *t;
    while (a)
    {
        tmp = a->next;
        free(a->line);
        free(a);
        a = tmp;
    }
    *t = NULL;
}

void add_line(t_text **t, char *l)
{
    t_text *new_line;
    t_text *a;

    new_line = malloc(sizeof(t_text));
    if (!new_line)
        return (free_text(t));
    new_line->line = l;
    new_line->next = NULL;
    if (!*t)
        *t = new_line;
    else
    {
        a = *t;
        while (a->next)
            a = a->next;
        a->next = new_line;
    }
}

t_text  *get_file(int fd)
{
    char    *line;
    t_text  *text;

    text = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        add_line(&text, line);
        if (!text)
            break ;
    }
    return (text);
}

t_text *read_file(char *f)
{
    t_text *text;
    int fd;

    if (!c_format(f))
        return (0);
    fd = open(f, O_RDONLY);
    if (fd < 0)
        return (0);
    text = get_file(fd);
    close(fd);
    if (!text)
        return (0);
    return (text);
}