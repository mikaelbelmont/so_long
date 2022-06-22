/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:01:43 by mbarreto          #+#    #+#             */
/*   Updated: 2022/06/21 20:29:14 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	searchn(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i++] == '\n')
			return (i++);
	}
	return (i);
}

char	*get_line(char *line, char *buff, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = line;
	line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	while (temp && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	while (buff[j])
	{
		line[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	line[i] = 0;
	if (temp)
		free(temp);
	return (line);
}

int	checkn(char *buffer)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && j < 0)
			j = 0;
		else if (j >= 0)
			buffer[j++] = buffer[i];
		buffer[i++] = 0;
	}
	return (j == -1);
}
