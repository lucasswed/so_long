/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:27:02 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/06 17:39:45 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

t_things	*all(void)
{
	static t_things	deus;

	return (&deus);
}

void	init_sprites(t_things *init)
{
	int	s;

	init->pl_up = mlx_xpm_file_to_image(init->mlx, "spts/pac4.xpm", &s, &s);
	init->pl_r = mlx_xpm_file_to_image(init->mlx, "spts/pac1.xpm", &s, &s);
	init->pl_l = mlx_xpm_file_to_image(init->mlx, "spts/pac3.xpm", &s, &s);
	init->pl_d = mlx_xpm_file_to_image(init->mlx, "spts/pac2.xpm", &s, &s);
	init->en_c = mlx_xpm_file_to_image(init->mlx, "spts/gho1.xpm", &s, &s);
	init->col = mlx_xpm_file_to_image(init->mlx, "spts/che.xpm", &s, &s);
	init->exi_c = mlx_xpm_file_to_image(init->mlx, "spts/exc.xpm", &s, &s);
	init->ex_op = mlx_xpm_file_to_image(init->mlx, "spts/exo.xpm", &s, &s);
	init->bor = mlx_xpm_file_to_image(init->mlx, "spts/bor.xpm", &s, &s);
	init->pl_c = init->pl_r;
	init->nb_c = exist_thing(init->map, 'C');
}

void	choose_image(char c, int x, int y, t_things img)
{
	if (c == '1')
		mlx_put_image_to_window(img.mlx, img.win, \
		img.bor, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(img.mlx, img.win, \
		img.pl_c, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(img.mlx, img.win, \
		img.col, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(img.mlx, img.win, \
		img.exi_c, x * 64, y * 64);
	if (c == 'X')
		mlx_put_image_to_window(img.mlx, img.win, \
		img.en_c, x * 64, y * 64);
}

void	print_steps(void)
{
	char	*steps;

	steps = ft_itoa((*all()).steps);
	mlx_string_put((*all()).mlx, (*all()).win, 10, 10, 0xFFFFFFFF, steps);
	free(steps);
}

void	print_image(char **map, t_things img)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			choose_image(map[y][x], x, y, img);
			x++;
		}
		y++;
	}
	print_steps();
}

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

void	exit_game(char *str)
{
	mlx_destroy_image((*all()).mlx, (*all()).pl_up);
	mlx_destroy_image((*all()).mlx, (*all()).pl_d);
	mlx_destroy_image((*all()).mlx, (*all()).pl_l);
	mlx_destroy_image((*all()).mlx, (*all()).pl_r);
	mlx_destroy_image((*all()).mlx, (*all()).en_c);
	mlx_destroy_image((*all()).mlx, (*all()).exi_c);
	mlx_destroy_image((*all()).mlx, (*all()).bor);
	mlx_destroy_image((*all()).mlx, (*all()).col);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	(*all()).win = NULL;
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
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
		exit_game("YOU LOSE!");
	if (check_colision(*map, x, y, 'E') && (*all()).nb_c == 0)
		exit_game("YOU WIN!");
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

int	close_game(void)
{
	mlx_destroy_image((*all()).mlx, (*all()).pl_up);
	mlx_destroy_image((*all()).mlx, (*all()).pl_d);
	mlx_destroy_image((*all()).mlx, (*all()).pl_l);
	mlx_destroy_image((*all()).mlx, (*all()).pl_r);
	mlx_destroy_image((*all()).mlx, (*all()).en_c);
	mlx_destroy_image((*all()).mlx, (*all()).exi_c);
	mlx_destroy_image((*all()).mlx, (*all()).ex_op);
	mlx_destroy_image((*all()).mlx, (*all()).bor);
	mlx_destroy_image((*all()).mlx, (*all()).col);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	(*all()).win = NULL;
	ft_putstr_fd("DID YOU GIVE UP!? LOSER!!\n", 1);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Invalid Arguments\n", 2);
		ft_putstr_fd("Correct usage: ./so_long [CHOSEN_MAP].ber\n", 2);
		exit(EXIT_FAILURE);
	}
	(*all()).map = create_map(av[1]);
	(*all()).mlx = mlx_init();
	init_sprites(all());
	(*all()).win = mlx_new_window((*all()).mlx, (*all()).map.map_w * 64, \
	(*all()).map.map_h * 64, "So long");
	mlx_key_hook((*all()).win, key, NULL);
	mlx_hook((*all()).win, 17, 1, close_game, NULL);
	print_image((*all()).map.mat, (*all()));
	mlx_loop((*all()).mlx);
	system("leaks so_long");
}
