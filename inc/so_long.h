/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:55:02 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/28 18:08:01 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

/*
 * Defines
 */
# ifndef WIDTH
#  define WIDTH 500
# endif
# ifndef HEIGHT
#  define HEIGHT 500
# endif
# define FONDO "../images/walk.xpm"

/*
 * Structs
 */

typedef struct	s_mlx
{
	void	*hero;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;


// main.c

// init.c
void	init_mlx(t_mlx *res, char *title);
#endif
