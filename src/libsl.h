/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:28:12 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/06 17:31:05 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSL_H
# define LIBSL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		map_h;
	int		map_w;
	char	**mat;
}			t_map;

typedef struct s_coords
{
	int	x;
	int	y;
}			t_coords;

typedef struct s_things
{
	void	*mlx;
	void	*win;
	void	*pl_c;
	void	*en_c;
	void	*exi_c;
	void	*pl_l;
	void	*pl_r;
	void	*pl_up;
	void	*pl_d;
	void	*col;
	void	*ex_op;
	void	*bor;
	int		nb_c;
	int		steps;
	t_map	map;
}			t_things;

void	free_map(t_map *map);
t_map	create_map(char *path);
int		map_verification(t_map map);
int		exist_thing(t_map map, char c);
#endif