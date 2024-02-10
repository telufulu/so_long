/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:29:53 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 17:59:41 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*new_win(void *mlx_ptr, int height, int width, char *name)
{
	ft_putnbr_fd(height * RES, 1);
	write(1, " ", 1);
	ft_putnbr_fd(width * RES, 1);
	if (height * RES > MAC_HEIGHT || width * RES > MAC_WIDTH)
		ft_error("map error: map is too large");
	return (mlx_new_window(mlx_ptr, width * RES, height * RES, name));
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
	if (!mlx->win_ptr)
		ft_error("mlx failed");
	return (mlx);
}
