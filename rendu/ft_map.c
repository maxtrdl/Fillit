/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:06:08 by mtrudel           #+#    #+#             */
/*   Updated: 2016/12/12 15:36:12 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

char			**ft_remplissage_final_tableau(int taille)
{
	int		i;
	int		j;
	char	**tableau;

	i = 0;
	j = 0;
	tableau = (char **)malloc((taille + 1) * sizeof(*tableau));
	while (i != taille + 1)
	{
		tableau[i] = (char*)malloc((taille + 1) * sizeof(tableau));
		i++;
	}
	i = 0;
	while (i < taille)
	{
		tableau[i][j] = '.';
		j++;
		if (j == taille)
		{
			tableau[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	return (tableau);
}

void			ft_check_l_and_k(int *l, int *k)
{
	if (*l > 3)
	{
		*l = 0;
		*k = *k + 1;
	}
}

void			ft_check_i_and_cmpt(int *i, int *j, int *cmpt, char *str)
{
	if (str[*i] == '\n' && str[*i + 1] == '\n')
	{
		*j = 0;
		*i = *i + 1;
		*cmpt = *cmpt + 1;
	}
}

t_position		*ft_map(char *str, int i, int j, int k)
{
	int			l;
	int			cmpt;
	t_position	*tetriminos;

	tetriminos = (t_position *)malloc((ft_strlen(str) / 21 + 1)\
		* sizeof(t_position));
	l = 0;
	cmpt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		ft_check_i_and_cmpt(&i, &j, &cmpt, str);
		if (str[i] == '#')
		{
			tetriminos[k].x[l] = i - ((21 * cmpt) + (5 * j));
			tetriminos[k].y[l] = j;
			l++;
		}
		ft_check_l_and_k(&l, &k);
		i++;
	}
	return (tetriminos);
}

void			ft_remove_tetri(char **tableau, int k, int taille)
{
	int i;
	int j;

	i = 0;
	while (i <= taille)
	{
		j = 0;
		while (j <= taille)
		{
			if (tableau[i][j] == 'A' + k)
				tableau[i][j] = '.';
			j++;
		}
		i++;
	}
}
