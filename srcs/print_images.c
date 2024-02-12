/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:16:57 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/12 17:08:35 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_hero_and_coins(char **map, t_mlx *mlx, t_spr *sprites)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				print_img(mlx, sprites->hero->ptr, x, y);
			else if (map[y][x] == 'C')
				print_img(mlx, sprites->coin->ptr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_obst(char **map, t_mlx *mlx, t_spr *sprites)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
				print_img(mlx, sprites->obst->ptr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	put_ground(char **map, t_mlx *mlx, t_spr *sprites)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			print_img(mlx, sprites->ground->ptr, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_img(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img, x * RES, y * RES);
}
