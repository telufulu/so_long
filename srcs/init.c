/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:41:22 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/28 18:08:03 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*init_mlx(char *title)
{
	t_mlx	*res;

	res = ft_calloc(sizeof(t_mlx), 1);
	if (!res)
		ft_error("Malloc failed\n");
	res->mlx_ptr = mlx_init();
	if (!res->mlx_ptr)
		ft_error("minilibx error\n");
	printf("%p\n", res->mlx_ptr);
	res->win_ptr = mlx_new_window(res->mlx_ptr, WIDTH, HEIGHT, title);
	if (!res->win_ptr)
		ft_error("minilibx error\n");
	returnn (res);
}
