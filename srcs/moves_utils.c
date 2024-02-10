/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:30 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 21:34:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y - 1][map->h_x];
	if (c != '1')
	{
		map->map[map->h_y][map->h_x] = '0';
		map->h_y -= 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
	}
}

void	move_down(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y + 1][map->h_x];
	if (c != '1')
	{
		map->map[map->h_y][map->h_x] = '0';
		map->h_y += 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
	}
}

void	move_left(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y][map->h_x - 1];
	if (c != '1')
	{
		map->map[map->h_y][map->h_x] = '0';
		map->h_x -= 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
	}
}

void	move_right(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y][map->h_x + 1];
	if (c != '1')
	{
		map->map[map->h_y][map->h_x] = '0';
		map->h_x += 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
	}
}

int	is_exit(t_map *map)
{
	if (!map->coins && map->h_x == map->e_x && map->h_y == map->e_y)
		return (1);
	return (0);
}
