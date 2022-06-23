/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:22:13 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/23 16:55:38 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_prep(t_window *window, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("File oppening failed.");
		return (0);
	}
	window->mapa = ft_mapstr(NULL, fd, 0);
	close(fd);
	if (!ft_checkmaprec(window, window->mapa))
		return (0);
	if (!ft_checkmapclosed(window->mapa))
	{
		ft_printf("Map is not closed.");
		return (0);
	}
	if (!ft_checkmapcomplete(window, window->mapa))
	{
		ft_printf("Map do not have the requirements to start.");
		return (0);
	}
	if (!ft_validchar(window, window->mapa))
		return (0);
	return (1);
}

char	**ft_mapstr(char **mapa, int fd, int counter)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		mapa = ft_mapstr(mapa, fd, 1 + counter);
	if (!mapa && counter != 0)
		mapa = malloc((counter + 1) * (sizeof(char *)));
	if (!mapa)
		ft_end(NULL);
	mapa[counter] = str;
	return (mapa);
}

int	ft_checkmaprec(t_window *window, char **mapa)
{
	int	iline;
	int	jcol;

	iline = -1;
	jcol = 0;
	while (mapa[++iline] && mapa[iline][jcol] != '\n')
	{
		if (strlen(mapa[0]) != strlen(mapa[iline]))
		{
			ft_printf("Map is not rectangular.");
			return (0);
		}
	}
	return (1);
}

int	ft_checkmapclosed(char **mapa)
{
	int	iline;
	int	jcol;

	iline = -1;
	while (mapa[++iline])
	{
		jcol = -1;
		while (mapa[iline][++jcol])
		{
			if (mapa[0][jcol] != '1' && mapa[0][jcol] != '\n')
				return (0);
			if (mapa[iline][0] != '1')
				return (0);
		}
		if (mapa[iline][jcol - 2] != '1')
			return (0);
	}
	iline -= 1;
	jcol = -1;
	while (mapa[iline - 1][++jcol])
		if (mapa[iline][jcol] != '1' && mapa[iline][jcol] != '\n')
			return (0);
	return (1);
}

int	ft_checkmapcomplete(t_window *window, char **mapa)
{
	int	iline;
	int	jcol;
	int	e;
	int	p;

	e = 0;
	p = 0;
	iline = -1;
	window->collect_img.n = 0;
	while (mapa[++iline])
	{
		jcol = -1;
		while (mapa[iline][++jcol])
		{
			if (mapa[iline][jcol] == 'C')
				window->collect_img.n++;
			if (mapa[iline][jcol] == 'E')
				e++;
			if (mapa[iline][jcol] == 'P')
				p++;
		}
	}
	if (window->collect_img.n < 1 || e < 1 || p != 1)
		return (0);
	return (1);
}
