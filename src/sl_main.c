/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:27:02 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/11 12:36:10 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

t_things	*all(void)
{
	static t_things	deus;

	return (&deus);
}

static void	init_sprites(t_things *init)
{
	int	s;

	init->pl_up = mlx_xpm_file_to_image(init->mlx, "spts/pac4.xpm", &s, &s);
	init->pl_r = mlx_xpm_file_to_image(init->mlx, "spts/pac1.xpm", &s, &s);
	init->pl_l = mlx_xpm_file_to_image(init->mlx, "spts/pac3.xpm", &s, &s);
	init->pl_d = mlx_xpm_file_to_image(init->mlx, "spts/pac2.xpm", &s, &s);
	init->en_r = mlx_xpm_file_to_image(init->mlx, "spts/gho1.xpm", &s, &s);
	init->en_l = mlx_xpm_file_to_image(init->mlx, "spts/gho2.xpm", &s, &s);
	init->en_d = mlx_xpm_file_to_image(init->mlx, "spts/gho4.xpm", &s, &s);
	init->en_up = mlx_xpm_file_to_image(init->mlx, "spts/gho3.xpm", &s, &s);
	init->col = mlx_xpm_file_to_image(init->mlx, "spts/che.xpm", &s, &s);
	init->exi_c = mlx_xpm_file_to_image(init->mlx, "spts/exc.xpm", &s, &s);
	init->ex_op = mlx_xpm_file_to_image(init->mlx, "spts/exo.xpm", &s, &s);
	init->bor = mlx_xpm_file_to_image(init->mlx, "spts/bor.xpm", &s, &s);
	init->en_c = init->en_r;
	init->pl_c = init->pl_r;
	init->nb_c = exist_thing(init->map, 'C');
	init->nb_en = exist_thing(init->map, 'X');
}

static void	double_player(char ***map)
{
	int			x;
	int			y;
	t_coords	p;

	p = find_player(*map);
	y = 0;
	while ((*map)[y])
	{
		x = 0;
		while ((*map)[y][x] != '\n')
		{
			if ((*map)[y][x] == 'P' && (p.x != x || p.y != y))
				(*map)[y][x] = 'X';
			x++;
		}
		y++;
	}
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
	double_player(&((*all()).map.mat));
	(*all()).mlx = mlx_init();
	init_sprites(all());
	(*all()).win = mlx_new_window((*all()).mlx, (*all()).map.map_w * 64, \
	(*all()).map.map_h * 64, "So long");
	mlx_key_hook((*all()).win, key, NULL);
	mlx_hook((*all()).win, 17, 1, close_game, NULL);
	print_image((*all()).map.mat, (*all()));
	mlx_loop_hook((*all()).mlx, enemy, all());
	mlx_loop((*all()).mlx);
	return (0);
}
