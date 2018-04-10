/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:36:14 by mtrudel           #+#    #+#             */
/*   Updated: 2016/12/16 11:21:24 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int		ft_is_possible(char **tableau, t_position tetriminos, \
	int pos, int taille)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = pos / taille;
	j = pos % taille;
	while (c < 4)
	{
		if ((i + tetriminos.y[c] > taille - 1 ||\
			j + tetriminos.x[c] > taille - 1))
			return (0);
		if ((i + tetriminos.y[c]) < 0 || (j + tetriminos.x[c]) < 0)
			return (0);
		if ((tableau[i + tetriminos.y[c]][j + tetriminos.x[c]] != '.'))
			return (0);
		c++;
	}
	return (1);
}

int		ft_check_nb_tetri(char **tableau, int taille)
{
	int j;
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < taille)
	{
		j = 0;
		while (j < taille)
		{
			if (tableau[i][j] == 'A' + k)
			{
				k++;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
	return (k);
}

void	ft_place_tetri(char **tableau, t_position tetriminos, int pos, int k)
{
	int i;
	int j;
	int p;
	int taille;

	p = 0;
	taille = ft_strlen(tableau[0]);
	i = pos / taille;
	j = pos % taille;
	while (p < 4)
	{
		tableau[i + tetriminos.y[p]][j + tetriminos.x[p]] = 'A' + k;
		p++;
	}
}

int		ft_print_tetri(char **tableau, t_position *tetriminos, \
	int nb_tetriminos, int k)
{
	int i;
	int j;
	int pos;
	int taille;

	taille = ft_strlen(tableau[0]);
	pos = 0;
	i = pos / taille;
	j = pos % taille;
	if (ft_check_nb_tetri(tableau, taille) == nb_tetriminos)
		return (1);
	while (pos <= taille * taille)
	{
		if (ft_is_possible(tableau, tetriminos[k], pos, taille))
		{
			ft_place_tetri(tableau, tetriminos[k], pos, k);
			if (ft_print_tetri(tableau, tetriminos, nb_tetriminos, k + 1))
				return (1);
			ft_remove_tetri(tableau, k, taille);
		}
		pos++;
	}
	return (0);
}

void	ft_solve(char *str2)
{
	int			taille;
	char		**tableau;
	int			nb_tetriminos;
	int			i;
	t_position	*tetriminos;

	i = 1;
	tetriminos = ft_map(str2, 0, 0, 0);
	nb_tetriminos = ft_nb_tetriminos(str2);
	tetriminos = ft_mise_a_zero(tetriminos, nb_tetriminos);
	taille = ft_sqrt(nb_tetriminos) * 2 - 1;
	tableau = ft_remplissage_final_tableau(taille);
	while (ft_print_tetri(tableau, tetriminos, nb_tetriminos, 0) == 0)
	{
		ft_free_map(tableau, taille + i);
		tableau = ft_remplissage_final_tableau(taille + i);
		ft_print_tetri(tableau, tetriminos, nb_tetriminos, 0);
		i++;
	}
	ft_affiche_tab(tableau, taille + i - 1);
}
