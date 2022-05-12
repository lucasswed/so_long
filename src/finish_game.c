/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:21:34 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/11 14:22:29 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl.h"

int	close_game(void)
{
	mlx_destroy_image((*all()).mlx, (*all()).pl_up);
	mlx_destroy_image((*all()).mlx, (*all()).pl_d);
	mlx_destroy_image((*all()).mlx, (*all()).pl_l);
	mlx_destroy_image((*all()).mlx, (*all()).pl_r);
	mlx_destroy_image((*all()).mlx, (*all()).en_up);
	mlx_destroy_image((*all()).mlx, (*all()).en_d);
	mlx_destroy_image((*all()).mlx, (*all()).en_l);
	mlx_destroy_image((*all()).mlx, (*all()).en_r);
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

void	exit_game(char *str)
{
	mlx_destroy_image((*all()).mlx, (*all()).pl_up);
	mlx_destroy_image((*all()).mlx, (*all()).pl_d);
	mlx_destroy_image((*all()).mlx, (*all()).pl_l);
	mlx_destroy_image((*all()).mlx, (*all()).pl_r);
	if (exist_thing((*all()).map, 'X'))
	{
		mlx_destroy_image((*all()).mlx, (*all()).en_d);
		mlx_destroy_image((*all()).mlx, (*all()).en_up);
		mlx_destroy_image((*all()).mlx, (*all()).en_l);
		mlx_destroy_image((*all()).mlx, (*all()).en_r);
	}
	mlx_destroy_image((*all()).mlx, (*all()).exi_c);
	mlx_destroy_image((*all()).mlx, (*all()).bor);
	mlx_destroy_image((*all()).mlx, (*all()).col);
	free_map(&((*all()).map));
	mlx_destroy_window((*all()).mlx, (*all()).win);
	(*all()).win = NULL;
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}