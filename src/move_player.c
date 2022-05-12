/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:27:36 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/07 12:57:13 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

t_coords	find_player(char **map)
{
	t_coords	c;

	c.y = 0;
	while (map[c.y])
	{
		c.x = 0;
		while (map[c.y][c.x])
		{
			if (map[c.y][c.x] == 'P')
				return (c);
			c.x++;
		}
		c.y++;
	}
	return (c);
}

int	check_colision(char **map, int x, int y, char c)
{
	t_coords	p;

	p = find_player(map);
	if (map[p.y + y][p.x + x] == c)
		return (1);
	return (0);
}

void	move_player(char ***map, int x, int y)
{
	t_coords	c;

	c = find_player(*map);
	if (x > 0)
		(*all()).pl_c = (*all()).pl_r;
	if (y > 0)
		(*all()).pl_c = (*all()).pl_d;
	if (x < 0)
		(*all()).pl_c = (*all()).pl_l;
	if (y < 0)
		(*all()).pl_c = (*all()).pl_up;
	if (check_colision(*map, x, y, 'X'))
		exit_game("YOU LOSE!\n");
	if (check_colision(*map, x, y, 'E') && (*all()).nb_c == 0)
		exit_game("YOU WIN!\n");
	if (!check_colision(*map, x, y, '1') && !check_colision(*map, x, y, 'E'))
	{
		if (check_colision(*map, x, y, 'C'))
			(*all()).nb_c--;
		(*map)[c.y][c.x] = '0';
		(*map)[c.y + y][c.x + x] = 'P';
		if ((*all()).nb_c == 0)
			(*all()).exi_c = (*all()).ex_op;
		(*all()).steps++;
	}
}

int	key(int keycode)
{
	if (keycode == 53)
		exit_game("DID YOU GIVE UP!? LOSER!!\n");
	if (keycode == 13)
		move_player(&((*all()).map.mat), 0, -1);
	if (keycode == 0)
		move_player(&((*all()).map.mat), -1, 0);
	if (keycode == 1)
		move_player(&((*all()).map.mat), 0, 1);
	if (keycode == 2)
		move_player(&((*all()).map.mat), 1, 0);
	mlx_clear_window((*all()).mlx, (*all()).win);
	print_image((*all()).map.mat, (*all()));
	return (0);
}
