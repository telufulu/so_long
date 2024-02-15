/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:30 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/15 21:02:41 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y - 1][map->h_x];
	if (c == 'E' && !map->coins)
		exit_game();
	else if (c != '1' && c != 'E')
	{
		mlx->moves++;
		map->map[map->h_y][map->h_x] = '0';
		map->h_y -= 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
		print_moves("Up", mlx);
	}
}

void	move_down(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y + 1][map->h_x];
	if (c == 'E' && !map->coins)
		exit_game();
	else if (c != '1' && c != 'E')
	{
		mlx->moves++;
		map->map[map->h_y][map->h_x] = '0';
		map->h_y += 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
		print_moves("Down", mlx);
	}
}

void	move_left(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y][map->h_x - 1];
	if (c == 'E' && !map->coins)
		exit_game();
	else if (c != '1' && c != 'E')
	{
		mlx->moves++;
		map->map[map->h_y][map->h_x] = '0';
		map->h_x -= 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
		print_moves("Left", mlx);
	}
}

void	move_right(t_mlx *mlx, t_map *map)
{
	char	c;

	c = map->map[map->h_y][map->h_x + 1];
	if (c == 'E' && !map->coins)
		exit_game();
	else if (c != '1' && c != 'E')
	{
		mlx->moves++;
		map->map[map->h_y][map->h_x] = '0';
		map->h_x += 1;
		if (map->map[map->h_y][map->h_x] == 'C')
			map->coins -= 1;
		map->map[map->h_y][map->h_x] = 'P';
		print_sprites(mlx, map, mlx->spr);
		print_moves("Right", mlx);
	}
}

void	exit_game(void)
{
	ft_putstr_fd("\nExit...\n", 1);
	exit(EXIT_SUCCESS);
}
