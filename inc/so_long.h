/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:50:23 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/09 20:04:16 by telufulu         ###   ########.fr       */
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
}				t_map;
#endif
