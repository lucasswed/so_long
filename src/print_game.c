/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:24:38 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/11 11:46:41 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

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