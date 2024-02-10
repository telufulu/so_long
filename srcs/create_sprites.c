/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:49:43 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/10 19:19:11 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*get_img(void *win, char *path)
{
	t_img	*img;

	img = ft_calloc(sizeof(t_img), 1);
	if (!img)
		ft_error("malloc failed");
	img->ptr = mlx_xpm_file_to_image(win, path, &img->width, &img->height);
	return (img);
}

t_spr	*create_sprites(void *win)
{
	t_spr	*spr;

	spr = ft_calloc(sizeof(t_spr), 1);
	if (!spr)
		ft_error("malloc failed");
	spr->hero = get_img(win, HERO);
	spr->coin = get_img(win, COIN);
	spr->obst = get_img(win, OBST);
	spr->ground = get_img(win, GROUND);
	spr->exit = get_img(win, EXIT);
	return (spr);
}
