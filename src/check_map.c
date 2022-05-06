/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:57:43 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/06 16:06:41 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

static int	map_walls(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_h)
	{
		if (map.mat[i][0] != '1' || map.mat[i][map.map_w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	map_up_down(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_w - 1)
	{
		if (map.mat[0][i] != '1' || map.mat[map.map_h - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	map_rect(t_map map)
{
	int	i;

	i = 0;
	while (i < map.map_h)
	{
		if ((int)ft_strlen(map.mat[i]) != map.map_w + 1)
			return (0);
		i++;
	}
	return (1);
}

int	exist_thing(t_map map, char c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < map.map_h)
	{
		j = 0;
		while (j < map.map_w)
		{
			if (map.mat[i][j] == c)
				counter++;
			if (map.mat[i][j] != '1' && map.mat[i][j] != '0' && \
			map.mat[i][j] != 'C' && map.mat[i][j] != 'P' && \
			map.mat[i][j] != 'E' && map.mat[i][j] != '\n' && \
			map.mat[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (counter);
}

int	map_verification(t_map map)
{
	if (!map_rect(map))
	{
		ft_putstr_fd("Map is not rectangular!\n", 2);
		return (0);
	}
	else if (!map_up_down(map) || !map_walls(map))
	{
		ft_putstr_fd("Map is not closed!\n", 2);
		return (0);
	}
	else if (!exist_thing(map, 'C'))
	{
		ft_putstr_fd("Theres no Collectables in the map\
 or there are invalid elements!\n", 2);
		return (0);
	}
	else if (!exist_thing(map, 'E') || !exist_thing(map, 'P'))
	{
		ft_putstr_fd("Theres no Exit or Player in the map!\n", 2);
		return (0);
	}
	return (1);
}
