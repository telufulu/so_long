/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:50:23 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/12 17:12:41 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "keycodes_mac.h"

# include <unistd.h>
# include <fcntl.h>

/*
 * Defines
 */
# define RES 64
# define MAC_W 4096
# define MAC_H 2304
# define NAME "so_long"

/*
 * Sprites
 */
# define HERO "assets/images/hero.xpm"
# define COIN "assets/images/coin.xpm"
# define OBST "assets/images/obst.xpm"
# define GROUND "assets/images/ground.xpm"
# define EXIT "assets/images/exit.xpm"

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}				t_img;

typedef struct s_spr
{
	t_img	*hero;
	t_img	*coin;
	t_img	*obst;
	t_img	*ground;
	t_img	*exit;
}				t_spr;

/*
 * Structs
 */

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		h_y;
	int		h_x;
	int		e_y;
	int		e_x;
	int		coins;
}				t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_spr	*spr;
}				t_mlx;

// init_map.c
t_map	*init_map(int fd, char *path);
void	get_map(t_map *map, int fd);
void	check_line(char *line, t_map *map, int h, int w);
void	check_map(t_map *map);

// check_exit.c
int		check_exit(t_map *map);
int		find_exit(char **map, int h_x, int h_y, int *coins);
void	clear_check_coins(char **map);

// init_mlx.c
void	init_mlx(t_mlx *mlx, t_map *map);
void	*new_win(void *mlx_ptr, int height, int width, char *name);

// create_sprites.c
t_spr	*create_sprites(void *win);
t_img	*get_img(void *win, char *path);

// game.c
void	start_game(t_map *map, t_mlx *mlx, t_spr *spr);
void	print_sprites(t_mlx *mlx, t_map *map, t_spr *spr);
int		moves(int key, t_mlx *mlx);

// moves_utils.c
void	exit_game(void);
void	move_right(t_mlx *mlx, t_map *map);
void	move_left(t_mlx *mlx, t_map *map);
void	move_down(t_mlx *mlx, t_map *map);
void	move_up(t_mlx *mlx, t_map *map);

// print_images.c
void	print_img(t_mlx *mlx, void *img, int x, int y);
void 	put_ground(char **map, t_mlx *mlx, t_spr *sprites);
void 	put_obst(char **map, t_mlx *mlx, t_spr *sprites);
void 	put_hero_and_coins(char **map, t_mlx *mlx, t_spr *sprites);
#endif
