/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:56:06 by telufulu          #+#    #+#             */
/*   Updated: 2024/01/10 00:55:43 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	//t_xpm	*sprites;

	if (argc == 2)
	{
		map = init_map(open(argv[1], O_RDONLY), argv[1]);
		while (*map->map)
		{
			printf("%s\n", *map->map);
			map->map++;
		}
	}
	else
		ft_error("wrong number of arguments. Expected 1"); 
	return (0);
}
