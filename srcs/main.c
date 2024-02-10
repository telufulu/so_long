/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:55:19 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 19:16:47 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_mlx		*mlx;
	t_spr		*spr;

	if (argc == 2)
	{
		map = init_map(open(argv[1], O_RDONLY), argv[1]);
		mlx = init_mlx(map);
		spr = create_sprites(mlx->win_ptr);
		start_game(map, mlx, spr);
	}
	else
		ft_error("wrong number of arguments. Expected 1");
	return (0);
}
