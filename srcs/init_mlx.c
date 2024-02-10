/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:29:53 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 21:19:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*new_win(void *mlx_ptr, int height, int width, char *name)
{
	if (height * RES > MAC_HEIGHT || width * RES > MAC_WIDTH)
		ft_error("map error: map is too large");
	return (mlx_new_window(mlx_ptr, width * RES, height * RES, name));
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_error("mlx failed");
	mlx->win_ptr = new_win(mlx->mlx_ptr, mlx->map->height, mlx->map->width, NAME);
	if (!mlx->win_ptr)
		ft_error("mlx failed");
}
