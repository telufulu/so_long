/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:16:57 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 20:14:19 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map *map, t_mlx *mlx, t_spr *spr)
{
	put_ground(map->map, mlx->mlx_ptr, mlx->win_ptr, spr);
	put_obst(map->map, mlx->mlx_ptr, mlx->win_ptr, spr);
	put_hero_and_coins(map->map, mlx->mlx_ptr, mlx->win_ptr, spr);
	//mlx_hook(mlx->win_ptr, 2, (1L<<0), moves, mlx);
	mlx_loop(mlx);
}
