/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:28:12 by lucas-ma          #+#    #+#             */
/*   Updated: 2022/05/11 12:31:47 by lucas-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSL_H
# define LIBSL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

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
	void	*en_l;
	void	*en_r;
	void	*en_up;
	void	*en_d;
	void	*exi_c;
	void	*pl_l;
	void	*pl_r;
	void	*pl_up;
	void	*pl_d;
	void	*col;
	void	*ex_op;
	void	*bor;
	int		nb_en;
	int		nb_c;
	int		steps;
	t_map	map;
}			t_things;

int			close_game(void);
int			key(int keycode);
int			enemy(t_things *all);
int			map_verification(t_map map);
int			exist_thing(t_map map, char c);
int			check_colision(char **map, int x, int y, char c);

void		print_steps(void);
void		exit_game(char *str);
void		free_map(t_map *map);
void		print_image(char **map, t_things img);
void		move_player(char ***map, int x, int y);
void		choose_image(char c, int x, int y, t_things img);

t_map		create_map(char *path);

t_things	*all(void);

t_coords	find_player(char **map);

#endif