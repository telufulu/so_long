/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:41:23 by telufulu          #+#    #+#             */
/*   Updated: 2024/01/10 01:18:33 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd, int *height, int *width)
{
	char	*aux;
	char	*to_free;
	char	*map;
	char	**res;

	map = 0;
	aux = get_next_line(fd);
	while (aux)
	{
		(*height)++;
		*width = ft_strlen(aux) - 1;
		to_free = map;
		map = ft_strjoin(map, aux);
		free(to_free);
		free(aux);
		aux = get_next_line(fd);
		if (aux && *width != (int)ft_strlen(aux) - 1)
			ft_error("map error");
	}
	close(fd);
	if (!map)
		ft_error("map error");
	res = ft_split(map, '\n');
	free(map);
	return (res);
}

void	check_char(t_map *map, int height, int width)
{
	char	c;

	c = map->map[height][width];
	if (c == 'E')
	{
		if (map->exit_x)
			ft_error("map error");
		map->exit_x = width;
		map->exit_y = height;
	}
	else if (c == 'P')
	{
		if (map->hero_x)
			ft_error("map error");
		map->hero_x = width;
		map->hero_y = height;
	}
	else if (c != '1' && c != '0' && c != 'C')
		ft_error("map error");
}

void	check_map(t_map *map)
{
	int		w;
	int		h;
	char	c;

	w = 0;
	h = 0;
	while (h < map->height)
	{
		if (h >= 1 && h < map->height && w >= 1)
			check_char(map, h, w);
		c = map->map[h][w];
		if ((h == 0 && c != '1') || (h == map->height - 1 && c != '1'))
			ft_error("map error");
		if ((w == 0 && c != '1') || (w == map->width - 1 && c != '1'))
			ft_error("map error");
		w++;
		if (w == map->width)
		{
			h++;
			w = 0;
		}
	}
}

t_map	*init_map(int fd, char *path)
{
	t_map	*res;

	if (!path || fd < 2 || ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4))
		ft_error("not a valid file");
	res = ft_calloc(sizeof(t_map), 1);
	if (!res)
		ft_error("malloc failed");
	res->map = get_map(fd, &res->height, &res->width);
	if (res->height == res-> width)
		ft_error("map is not a rectangle");
	check_map(res);
	if (!res->hero_x || !res->exit_x)
		ft_error("map error");
	//check_solution(res);
	res->width *= SPRITE_SIZE;
	res->height *= SPRITE_SIZE;
	return (res);
}
