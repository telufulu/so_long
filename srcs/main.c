/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:55:19 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/09 23:52:08 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		map = init_map(open(argv[1], O_RDONLY), argv[1]);
		if (map)
			ft_putstr_fd("OK\n", 1);
	}
	else
		ft_error("wrong number of arguments. Expected 1");
	return (0);
}
