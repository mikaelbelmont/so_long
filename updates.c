/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:30:33 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/23 19:26:12 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printmap(t_window *window, char **mapa)
{
	int	i;
	int	j;

	i = -1;
	while (mapa[++i])
	{
		j = -1;
		while (mapa[i][++j])
		{
			if (mapa[i][j] == '1')
				mlx_put_image_to_window(window->mlx, \
				window->win, window->wall_img.img, j * 64, i * 64);
			else
				mlx_put_image_to_window(window->mlx, \
				window->win, window->floor_img.img, j * 64, i * 64);
		}
	}
}

void	ft_delcollect(t_window *window, int i, int j)
{
	if (window->player_img.x == j * 64 && window->player_img.y == i * 64)
	{
		window->mapa[i][j] = '0';
		window->collect_img.count++;
	}
	else
	{
		mlx_put_image_to_window(window->mlx, window->win, \
		window->collect_img.img, window->collect_img.x, window->collect_img.y);
	}
}

void	ft_initexit(t_window *window, char **mapa)
{
	int	i;
	int	j;

	i = -1;
	while (mapa[++i])
	{
		j = -1;
		while (mapa[i][++j])
		{
			if (mapa[i][j] == 'E')
			{
				window->exit_img.x = j * 64;
				window->exit_img.y = i * 64;
				mlx_put_image_to_window(window->mlx, window->win, \
			window->floor_img.img, window->exit_img.x, window->exit_img.y);
				if (window->player_img.x == j * 64 \
				&& window->player_img.y == i * 64)
					if (window->collect_img.count == window->collect_img.n)
						ft_end(window);
				if (window->collect_img.count == window->collect_img.n)
					mlx_put_image_to_window(window->mlx, window->win, \
				window->exit_img.img, window->exit_img.x, window->exit_img.y);
			}
		}
	}
}

int	ft_validchar(t_window *window, char **mapa)
{
	int	i;
	int	j;

	i = -1;
	while (mapa[++i])
	{
		j = -1;
		while (mapa[i][++j])
		{
			if (mapa[i][j] != 'P' && \
			mapa[i][j] != 'E' && mapa[i][j] != 'C' && mapa[i][j] != 'T' && \
			mapa[i][j] != '1' && mapa[i][j] != '0' && mapa[i][j] != '\n')
			{
				ft_printf("Map has a invalid char.");
				return (0);
			}
		}
	}
	window->x_winparam = i * 64;
	window->y_winparam = (j * 64) - 64;
	return (1);
}

void	ft_trapinit(t_window *window, char **mapa)
{
	int	i;
	int	j;

	i = -1;
	while (mapa[++i])
	{
		j = -1;
		while (mapa[i][++j])
		{
			if (mapa[i][j] == 'T')
			{
				window->exit_img.x = j * 64;
				window->exit_img.y = i * 64;
				mlx_put_image_to_window(window->mlx, window->win, \
				window->exit_img.img, window->exit_img.x, window->exit_img.y);
				if (window->player_img.x == j * 64 \
					&& window->player_img.y == i * 64)
					ft_end(window);
			}
		}
	}
}
