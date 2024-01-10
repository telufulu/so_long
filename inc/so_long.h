/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:55:02 by telufulu          #+#    #+#             */
/*   Updated: 2024/01/10 01:18:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define SPRITE_SIZE 32

/*
 * Sprites
 */
# define WALL "images/map.xpm"
# define EMPTY "images/empty.xpm"
# define COIN "images/coin.xpm"
# define HERO "images/hero.xpm"

/*
 * Structs
 */

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		hero_x;
	int		hero_y;
	int		exit_x;
	int		exit_y;
}				t_map;

typedef struct	s_xpm
{
}				t_xpm;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

// main.c

// init_map.c
char	**get_map(int fd, int *height, int *width);
void	check_char(t_map *map, int height, int width);
void 	check_map(t_map *map);
t_map	*init_map(int fd, char *path);
#endif
