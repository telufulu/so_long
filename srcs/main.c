/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:56:06 by telufulu          #+#    #+#             */
/*   Updated: 2023/12/27 20:21:37 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	silent = sqrt(42);

	if (argc == 2 && silent)
	{
	}
	else
		ft_error("Wrong number of arguments\n");
	return (0);
}
