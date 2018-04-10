/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:06:08 by mtrudel           #+#    #+#             */
/*   Updated: 2016/12/16 12:32:08 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int	main(int argc, char **argv)
{
	char	*str2;
	int		nb_tetriminos;
	int		fd;

	fd = 0;
	if (!ft_read(argc, argv, fd))
	{
		return (0);
	}
	str2 = ft_read(argc, argv, fd);
	nb_tetriminos = ft_nb_tetriminos(str2);
	if (ft_verif_tetriminos(str2) != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_solve(str2);
	return (0);
}
