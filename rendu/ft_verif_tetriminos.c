/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:13:49 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/16 16:10:32 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int	ft_verif_tetriminos(char *str1)
{
	int		i;

	i = 0;
	if (ft_check_char_tetriminos(str1, i, 20, 0) != 1)
		return (1);
	if (ft_check_sharps_tetriminos(str1, i) != 1)
		return (2);
	if (ft_check_links(str1, i) != 1)
		return (3);
	if (ft_check_newline(str1) != 1)
		return (4);
	return (0);
}
