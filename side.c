/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:24:33 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/23 15:36:04 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_left(t_window *window)
{
	if (window->keys.a && !window->keys.d && !window->keys.w && !window->keys.s)
	{
		window->player_img.img = window->player_2_img.img;
		window->player_img.x -= window->player_img.speed;
		if (window->mapa[(window->player_img.y / 64)] \
		[(window->player_img.x / 64)] == '1')
		{
			window->player_img.x += window->player_img.speed;
			window->mvcount -= 1;
		}
		window->mvcount += 1;
		ft_printf("Steps: %i\n", window->mvcount);
	}
}

void	ft_update_right(t_window *window)
{
	if (window->keys.d && !window->keys.a && !window->keys.w && !window->keys.s)
	{
		window->player_img.img = window->player_1_img.img;
		window->player_img.x += window->player_img.speed;
		if (window->mapa[window->player_img.y / 64] \
		[(window->player_img.x / 64)] == '1')
		{
			window->player_img.x -= window->player_img.speed;
			window->mvcount -= 1;
		}
		window->mvcount += 1;
		ft_printf("Steps: %i\n", window->mvcount);
	}
}

void	ft_update_up(t_window *window)
{
	if (window->keys.w && !window->keys.d && !window->keys.a && !window->keys.s)
	{
		window->player_img.y -= window->player_img.speed;
		if (window->mapa[window->player_img.y / 64] \
		[window->player_img.x / 64] == '1')
		{
			window->player_img.y += window->player_img.speed;
			window->mvcount -= 1;
		}
		window->mvcount += 1;
		ft_printf("Steps: %i\n", window->mvcount);
	}
}

void	ft_update_down(t_window *window)
{
	if (window->keys.s && !window->keys.d && !window->keys.w && !window->keys.a)
	{
		window->player_img.y += window->player_img.speed;
		if (window->mapa[(window->player_img.y / 64)] \
		[(window->player_img.x / 64)] == '1')
		{
			window->player_img.y -= window->player_img.speed;
			window->mvcount -= 1;
		}
		window->mvcount += 1;
		ft_printf("Steps: %i\n", window->mvcount);
	}
}

void	ft_wichside(t_window *window)
{
	static int	speed;

	if (speed++ < 8)
		return ;
	speed = 0;
	ft_update_up(window);
	ft_update_down(window);
	ft_update_left(window);
	ft_update_right(window);
}
