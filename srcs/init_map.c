/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:41:25 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/15 22:28:47 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_map *map, int fd)
{
	char	*aux;
	char	*to_split;

	to_split = 0;
	aux = get_next_line(fd);
	if (!aux)
		ft_error("map error: map is empty");
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
		if (aux && (size_t)map->width != ft_strlen(aux) - 1)
			ft_error("map error: map is not a rectangle");
	}
	map->map = ft_split(to_split, '\n');
	free(to_split);
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
	check_map(map);
	if (!check_exit(map))
		ft_error("map error: map can't be solved");
	return (map);
}
