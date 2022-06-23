/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:23:15 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/23 14:05:32 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_xbutton(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_window	*window;

	if (argc != 2)
	{
		ft_printf("Map is missing.");
		exit(0);
	}
	window = (t_window *)malloc(sizeof(t_window));
	window->mvcount = 0;
	window->collect_img.count = 0;
	if (!ft_map_prep(window, argv))
	{
		exit(0);
	}
	ft_gameinit(window);
	mlx_hook(window->win, X_WINBUTTON, 1L << 3, &ft_xbutton, window);
	mlx_hook(window->win, KEY_PRESS, 1, ft_startwalking, window);
	mlx_hook(window->win, KEY_RELEASE, 1, ft_stopwalking, window);
	mlx_loop_hook(window->mlx, ft_work, window);
	mlx_loop(window->mlx);
	ft_end(window);
}
