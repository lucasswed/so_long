/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:57:15 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/06 15:44:49 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

static int	count_lines(char *path)
{
	int		c;
	int		fd;
	char	buf;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error opening the map!", 2);
		exit(EXIT_FAILURE);
	}
	c = 0;
	while (read(fd, &buf, 1))
		if (buf == '\n')
			c++;
	close(fd);
	return (c);
}

static t_map	get_map_util(char *path)
{
	int		i;
	int		fd;
	t_map	map;

	map.map_h = count_lines(path);
	map.mat = malloc((map.map_h + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (!map.mat || fd == -1 || map.map_h < 2)
	{
		ft_putstr_fd("Error creating map!\n", 1);
		free_map(&map);
		if (fd != -1)
			close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map.map_h)
	{
		map.mat[i] = get_next_line(fd);
		i++;
	}
	map.mat[i] = NULL;
	map.map_w = ft_strlen(map.mat[0]) - 1;
	close(fd);
	return (map);
}

void	free_map(t_map *map)
{
	free(map->mat);
}

t_map	create_map(char *path)
{
	t_map	map;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error! Invalid file type.", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map_util(path);
	if (!map_verification(map))
	{
		ft_putstr_fd("BAD MAP!\n", 2);
		free_map(&map);
		exit(EXIT_FAILURE);
	}
	else
		ft_putstr_fd("GOOD MAP!\n", 1);
	return (map);
}
