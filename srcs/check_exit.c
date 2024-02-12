/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:33:47 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/12 16:19:55 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_check_coins(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (ft_strchr(map[x], 'C'))
			ft_error("map error: can't be solved");
		while (ft_strchr(map[x], 'X'))
			*(ft_strchr(map[x], 'X')) = '0';
		while (ft_strchr(map[x], 'c'))
			*(ft_strchr(map[x], 'c')) = 'C';
		x++;
	}
}

int	find_exit(char **map, int h_y, int h_x, int *coins)
{
	int		flag;
	char	c;

	flag = 0;
	c = map[h_y][h_x];
	if ((!map[h_y][h_x + 1] || !map[h_y + 1]) && c != '1' && c != 'E')
		ft_error("map error: map is not closed");
	if (c != 'X' && c != '1')
	{
		if (c == 'E')
			return (1);
		if (c == 'C')
		{
			map[h_y][h_x] = 'c';
			(*coins)++;
		}
		else if (c == '0')
			map[h_y][h_x] = 'X';
		flag += find_exit(map, h_y + 1, h_x, coins);
		flag += find_exit(map, h_y - 1, h_x, coins);
		flag += find_exit(map, h_y, h_x + 1, coins);
		flag += find_exit(map, h_y, h_x - 1, coins);
	}
	return (flag);
}

int	check_exit(t_map *map)
{
	if (!find_exit(map->map, map->h_y, map->h_x, &map->coins) || !map->coins)
		return (0);
	clear_check_coins(map->map);
	return (1);
}
