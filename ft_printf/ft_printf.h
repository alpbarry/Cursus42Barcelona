/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <alphbarr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:24:00 by alphbarr          #+#    #+#             */
/*   Updated: 2024/02/28 09:21:01 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int ft_printf(const char *f, ...);
int ft_print_char(int c);
int ft_print_str(char *str);
int ft_print_nbr(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hexadecimal(unsigned int num, char word);
int ft_len_hexadecimal(unsigned int num);
void ft_is_hexadecimal(unsigned int num, char word);
int ft_print_pointer(unsigned long long ptr);
int ft_len_pointer(unsigned long long ptr);
void ft_is_pointer(unsigned long long ptr);

#endif
