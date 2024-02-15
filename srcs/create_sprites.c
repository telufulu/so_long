/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:49:43 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/15 20:37:47 by telufulu         ###   ########.fr       */
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

void	check_assets(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 3)
		ft_error("invalid image asset");
	close(fd);
}

void	test_assets(void)
{
	check_assets(HERO);
	check_assets(COIN);
	check_assets(OBST);
	check_assets(GROUND);
	check_assets(EXIT);
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
