/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:55:19 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 21:19:23 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		*mlx;

	if (argc == 2)
	{
		mlx = ft_calloc(sizeof(t_mlx), 1);
		if (!mlx)
			ft_error("malloc failed");
		mlx->map = init_map(open(argv[1], O_RDONLY), argv[1]);
		init_mlx(mlx);
		mlx->spr = create_sprites(mlx->win_ptr);
		start_game(mlx->map, mlx, mlx->spr);
	}
	else
		ft_error("wrong number of arguments. Expected 1");
	return (0);
}
