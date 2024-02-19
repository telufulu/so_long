/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:33:47 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/19 19:46:23 by telufulu         ###   ########.fr       */
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

/*int	find_exit(char **map, int h_y, int h_x, int *coins, int *flag)
{
	char		c;

	c = map[h_y][h_x];
	if (c == 'E')
		return (1);
	if (c == '1' || *flag >= 100)
		return (0);
	if (c && c != 'X' && c != '1')
	{
		if (c == 'C')
		{
			map[h_y][h_x] = 'c';
			(*coins)++;
		}
		else if (c == '0')
			map[h_y][h_x] = 'X';
		(*flag) += find_exit(map, h_y + 1, h_x, coins);
		(*flag) += find_exit(map, h_y - 1, h_x, coins);
		(*flag) += find_exit(map, h_y, h_x + 1, coins);
		(*flag) += find_exit(map, h_y, h_x - 1, coins);
	}
	return (*flag);
}*/

int	find_exit(char **map, int x, int y, int *coins)
{
	if (map[y][x] == 'E')
		return (1);
	else if (map[y][x] == 'C')
	{
		map[y][x] = 'c';
		(*coins)++;
	}
	else if (map[y][x] != 'X' && map[y][x] != '1')
			map[y][x] = 'X';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'X')
		find_exit(map, y + 1, x, coins);
	else if (map[y][x + 1] != '1' && map[y][x + 1] != 'X')
		find_exit(map, y, x + 1, coins);
	else if (map[y - 1][x] != '1' && map[y - 1][x] != 'X')
		find_exit(map, y - 1, x, coins);
	else if (map[y][x - 1] != '1' && map[y][x - 1] != 'X')
		find_exit(map, y, x - 1, coins);
	return (0);
}

#include <stdio.h>

int	check_exit(t_map *map)
{
	int	flag;

	flag = 0;
	if (!map->coins)
		return (0);
	find_exit(map->map, map->h_y, map->h_x, &map->coins);
	char	**aux = map->map;
	while (*aux)
		printf("%s\n", (*aux)++);
	//if (!find_exit(map->map, map->h_y, map->h_x, &map->coins) || !map->coins)
	//	return (0);
	clear_check_coins(map->map);
	return (1);
}
