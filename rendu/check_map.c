/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:13:49 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/19 10:46:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int				ft_check_char_bis(char *str1)
{
	int nb_tetriminos;

	nb_tetriminos = (int)ft_strlen(str1) / 21 + 1;
	if ((str1[ft_strlen(str1) - 1] != '\n') ||\
		((int)ft_strlen(str1) / 21 + 1 > 27))
		return (0);
	if ((str1[ft_strlen(str1) - 1] == '\n') &&\
		(str1[ft_strlen(str1) - 2] == '\n'))
		return (0);
	if ((int)ft_strlen(str1) != nb_tetriminos * 20 + (nb_tetriminos - 1))
		return (0);
	return (1);
}

int				ft_check_char_ter(char *str1, int *i, int *cpt,\
	int *multiplicateur)
{
	if (str1[*i] == '\n' && (str1[*i + 1] != '\n' ||\
		str1[*i + 1] == '\0') && str1[*i - 1] != '\n')
	{
		if (*i != (4 * *cpt) + *multiplicateur)
			return (0);
		*multiplicateur += 1;
		*cpt += 1;
	}
	return (1);
}

int				ft_check_char_tetriminos(char *str1, int i, int i_mult,\
	int multiplicateur)
{
	int cpt;

	cpt = 1;
	if (ft_check_char_bis(str1) == 0)
		return (0);
	while (str1[i] != '\0')
	{
		if (str1[i] != '.' && str1[i] != '#' && str1[i] != '\n')
			return (0);
		if (ft_check_char_ter(str1, &i, &cpt, &multiplicateur) == 0)
			return (0);
		if (str1[i - 1] == '\n' && str1[i] == '\n')
		{
			if (i != i_mult)
				return (0);
			i_mult = i_mult + 21;
			cpt++;
			multiplicateur += 2;
		}
		i++;
	}
	return (1);
}

int				ft_check_sharps_tetriminos(char *str1, int i)
{
	int count_sharp;

	count_sharp = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == '#')
			count_sharp++;
		if ((str1[i] == '\n' && str1[i + 1] == '\n') ||\
			(str1[i] == '\n' && str1[i + 1] == '\0'))
		{
			if (count_sharp != 4)
				return (0);
			count_sharp = 0;
		}
		i++;
	}
	return (1);
}

int				ft_check_links(char *str1, int i)
{
	int	count_links;
	int	count;

	count_links = 0;
	count = 20;
	while (i < (int)ft_strlen(str1))
	{
		count_links = 0;
		while ((i != count + 1) && (i < (int)ft_strlen(str1)))
		{
			if (str1[i] == '#' && str1[i + 1] == '#' && (i + 1 < count + 1))
				count_links++;
			if (str1[i] == '#' && str1[i + 5] == '#' && (i + 5 < count + 1))
				count_links++;
			if (str1[i] == '#' && str1[i - 1] == '#' && (i - 1 > count - 21))
				count_links++;
			if (str1[i] == '#' && str1[i - 5] == '#' && (i - 5 > count - 21))
				count_links++;
			i++;
		}
		if (count_links != 6 && count_links != 8)
			return (0);
		count = count + 21;
	}
	return (1);
}
