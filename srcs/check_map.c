/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:41:25 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/15 21:41:59 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *line, t_map *map, int h, int w)
{
	while (line[w])
	{
		if (line[w] == 'P')
		{
			if (map->h_y || map->h_x)
				ft_error("map error: more than one initial position");
			map->h_y = h;
			map->h_x = w;
		}
		else if (line[w] == 'E')
		{
			if (map->e_y || map->e_x)
				ft_error("map error: more than one exit");
			map->e_y = h;
			map->e_x = w;
		}
		else if (line[0] == '\n' || !ft_strchr("PEC10\n", line[w]))
			ft_error("map error: forbidden symbol in map");
		w++;
	}
}

void	check_map(t_map *map)
{
	if (!map->map)
		ft_error("map error: map couldn't be read");
	else if (check_edges(map->map, map->height - 1, map->width - 1))
		ft_error("map error: map is not surrounded by walls");
}

int	check_edges(char **map, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[0][x] != '1' || map[y][0] != '1')
				return (1);
			else if (map[h][x] != '1' || map[y][w] != '1')
				return (1);
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}
