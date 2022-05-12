/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:57:45 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/12 09:51:14 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

static t_coords	find_enemy(char **map, int n)
{
	t_coords	c;
	int			m;

	c.y = 0;
	m = 0;
	while (map[c.y])
	{
		c.x = 0;
		while (map[c.y][c.x])
		{
			if (map[c.y][c.x] == 'X' && n == m)
				return (c);
			if (map[c.y][c.x] == 'X')
				m++;
			c.x++;
		}
		c.y++;
	}
	return (c);
}

static int	check_en_colision(char **map, t_coords ah, char c, int n)
{
	t_coords	en;

	en = find_enemy(map, n);
	if (map[en.y + ah.y][en.x + ah.x] == c)
		return (1);
	return (0);
}

static void	choose_en_move(t_coords *cord)
{
	int			num;

	num = rand() % 4 + 1;
	if (num == 1)
	{
		(*all()).en_c = (*all()).en_r;
		cord->x = 1;
	}
	if (num == 2)
	{
		(*all()).en_c = (*all()).en_d;
		cord->y = 1;
	}
	if (num == 3)
	{
		(*all()).en_c = (*all()).en_l;
		cord->x = -1;
	}
	if (num == 4)
	{
		(*all()).en_c = (*all()).en_up;
		cord->y = -1;
	}
}

static void	move_enemy(char ***map, int n)
{
	t_coords	move;
	t_coords	en;

	move.x = 0;
	move.y = 0;
	choose_en_move(&move);
	en = find_enemy(*map, n);
	if (check_en_colision(*map, move, 'P', n))
		exit_game("YOU LOSE!\n");
	else if (!check_en_colision(*map, move, '1', n) && \
	!check_en_colision(*map, move, 'E', n) && \
	!check_en_colision(*map, move, 'C', n) && \
	!check_en_colision(*map, move, 'X', n))
	{
		(*map)[en.y][en.x] = '0';
		(*map)[en.y + move.y][en.x + move.x] = 'X';
	}
}

int	enemy(t_things *all)
{
	static int	delay;
	int			n;

	n = 0;
	if (delay < 3000)
	{
		delay++;
		return (0);
	}
	while (n < all->nb_en)
	{
		move_enemy(&(all->map.mat), n);
		n++;
	}
	mlx_clear_window(all->mlx, all->win);
	print_image(all->map.mat, *all);
	mlx_key_hook(all->win, key, NULL);
	delay = 0;
	return (0);
}
