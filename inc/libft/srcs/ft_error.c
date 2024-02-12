/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:00:42 by telufulu          #+#    #+#             */
/*   Updated: 2024/02/12 16:32:22 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *err)
{
	ft_putstr_fd("\x1b[31mError\x1b[0m\n", 2);
	if (err && *err)
	{
		ft_putstr_fd(err, 2);
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
