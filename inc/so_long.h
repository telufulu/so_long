/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:50:23 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 00:56:03 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <fcntl.h>

/*
 * Structs
 */

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		h_y;
	int		h_x;
	int		e_y;
	int		e_x;
	int		coins;
}				t_map;

// init_map.c
t_map	*init_map(int fd, char *path);
void	get_map(t_map *map, int fd);
void	check_line(char *line, t_map *map, int h, int w);
void	check_map(t_map *map);

// check_exit.c
int		check_exit(t_map *map);
int		find_exit(char **map, int h_x, int h_y, int *coins);
void	clear_check_coins(char **map);
#endif
