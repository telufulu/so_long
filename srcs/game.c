/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:16:57 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/12 17:08:37 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves(int key, t_mlx *mlx)
{
	if (key == KEY_UP || key == KEY_W)
		move_up(mlx, mlx->map);
	else if (key == KEY_DOWN || key == KEY_S)
		move_down(mlx, mlx->map);
	else if (key == KEY_LEFT || key == KEY_A)
		move_left(mlx, mlx->map);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_right(mlx, mlx->map);
	if (key == KEY_ESCAPE)
		exit_game();
	return (0);
}

void	print_sprites(t_mlx *mlx, t_map *map, t_spr *spr)
{
	int	exit_y;

	exit_y = (map->e_y * RES - RES) / RES;
	put_ground(map->map, mlx, spr);
	put_obst(map->map, mlx, spr);
	put_hero_and_coins(map->map, mlx, spr);
	print_img(mlx, spr->exit->ptr, map->e_x, exit_y);
}

int	game_close(void)
{
	exit_game();
	return (0);
}

void	start_game(t_map *map, t_mlx *mlx, t_spr *spr)
{
	print_sprites(mlx, map, spr);
	mlx_hook(mlx->win_ptr, 2, (1L << 0), moves, mlx);
	mlx_hook(mlx->win_ptr, 17, (1L << 2), game_close, mlx);
	mlx_loop(mlx);
}
