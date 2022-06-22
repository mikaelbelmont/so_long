/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:27:55 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/21 19:57:44 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32

# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

int		ft_strlen(const char *str);

char	*get_next_line(int fd);
int		searchn(char *buff);
char	*get_line(char *line, char *buff, int size);
int		checkn(char *buffer);

typedef unsigned long long int		t_ulli;

int		ft_printf(const char *type, ...);
int		ft_found_format(const char *format, int i, va_list *args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_conv_base(t_ulli n, char *base, t_ulli base_size);
int		ft_putnumber(int n);
int		ft_putui(unsigned int n, char *base, int base_size);
int		ft_putul(unsigned long n);

int		ft_strlin(char *str);
char	*ft_get_line(char *buff, char *line);

#endif