/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:55:02 by telufulu          #+#    #+#             */
/*   Updated: 2024/01/09 20:20:47 by telufulu         ###   ########.fr       */
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
