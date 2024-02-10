/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:29:53 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 01:40:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*new_win(void *mlx_ptr, int height, int width, char *name)
{
	return (mlx_new_window(mlx_ptr, height * RES, width * RES, name);
}
t_mlx	*init_mlx(t_map *map)
{
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		ft_error("malloc failed");
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_error("mlx failed");
	mlx->win_ptr = new_win(mlx->mlx_ptr, map->height, map->width, NAME);
}
