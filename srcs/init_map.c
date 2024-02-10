/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:41:25 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 17:53:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *map)
{
	if (!map->map)
		ft_error("map error: map couldn't be read");
	else if (map->height == map->width)
		ft_error("map error: map is a square");
	else if (!map->h_y || !map->h_x || map->h_y == map->height - 1 || 
		map->h_x == map->width - 1)
		ft_error("map error: map is not closed");
}

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
			ft_error("map error: forbidden simbol in map");
		w++;
	}
}

void	get_map(t_map *map, int fd)
{
	char	*aux;
	char	*to_split;

	to_split = 0;
	aux = get_next_line(fd);
	while (aux)
	{
		check_line(aux, map, map->height, 0);
		map->height++;
		map->width = ft_strlen(aux) - 1;
		to_split = concatenate(to_split, aux);
		free(aux);
		if (!to_split)
			ft_error("malloc failed");
		aux = get_next_line(fd);
	}
	map->map = ft_split(to_split, '\n');
	free(to_split);
	check_map(map);
}

t_map	*init_map(int fd, char *path)
{
	t_map	*map;

	if (!path || fd < 2 || ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4))
		ft_error("map error: not a valid file");
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		ft_error("malloc failed");
	get_map(map, fd);
	if (!check_exit(map))
		ft_error("map error: map can't be solved");
	return (map);
}
