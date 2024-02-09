/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:00:42 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/27 20:09:28 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *err)
{
	ft_putstr_fd("\x1b[31mError\x1b[0m: ", 2);
	if (err && *err)
		ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}
