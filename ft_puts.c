/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:52:43 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/15 19:41:18 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str && str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putnumber(int n)
{
	unsigned long int	sig;

	sig = 1;
	if (n < 0)
	{
		sig = -1;
		ft_putchar('-');
	}
	return (ft_conv_base(n * sig, "0123456789", 10) + (n < 0));
}

int	ft_putui(unsigned int n, char *base, int base_size)
{
	return (ft_conv_base(n, base, base_size));
}

int	ft_putul(unsigned long n)
{
	return (ft_conv_base(n, "0123456789abcdef", 16));
}
