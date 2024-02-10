/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:55:19 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 12:49:14 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;

	if (argc == 2)
	{
		map = init_map(open(argv[1], O_RDONLY), argv[1]);
		mlx = init_mlx(map);
		mlx_loop(mlx);
	}
	else
		ft_error("wrong number of arguments. Expected 1");
	return (0);
}
