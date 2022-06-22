/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:35:55 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/22 15:28:49 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end(t_window *window)
{
	int	i;

	i = -1;
	if (window->mapa)
	{
		while (window->mapa[++i])
			free(window->mapa[i]);
		free(window->mapa);
	}
	if (window->floor_img.img)
		mlx_destroy_image(window->mlx, window->floor_img.img);
	if (window->wall_img.img)
		mlx_destroy_image(window->mlx, window->wall_img.img);
	if (window->player_img.img)
		mlx_destroy_image(window->mlx, window->player_img.img);
	if (window->collect_img.img)
		mlx_destroy_image(window->mlx, window->collect_img.img);
	if (window->exit_img.img)
		mlx_destroy_image(window->mlx, window->exit_img.img);
	mlx_destroy_window(window->mlx, window->win);
	free(window);
	exit(0);
}
