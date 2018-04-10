/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_left_indic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:36:14 by mtrudel           #+#    #+#             */
/*   Updated: 2016/12/09 17:08:38 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

t_position	*ft_mise_a_zero(t_position *tetriminos, int nb_tetriminos)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (k < nb_tetriminos)
	{
		tetriminos[k].x[i] = tetriminos[k].x[i] - tetriminos[k].x[0];
		tetriminos[k].y[i] = tetriminos[k].y[i] - tetriminos[k].y[0];
		i++;
		if (i > 3)
		{
			tetriminos[k].x[0] = 0;
			tetriminos[k].y[0] = 0;
			i = 1;
			k++;
		}
	}
	return (tetriminos);
}
