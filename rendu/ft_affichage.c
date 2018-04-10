/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:24:24 by mtrudel           #+#    #+#             */
/*   Updated: 2016/12/16 16:11:27 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		ft_putchar(src[i]);
		i++;
	}
}

void	ft_affiche_tab(char **tableau, int taille)
{
	int	i;

	i = 0;
	while (i < taille)
	{
		ft_putstr(tableau[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr(tableau[i]);
}

void	ft_free_map(char **tableau, int taille)
{
	int		i;

	i = 0;
	while (i < taille)
	{
		free(tableau[i]);
		i++;
	}
	free(tableau);
}

int		ft_check_newline(char *str1)
{
	int cmpt;

	cmpt = 20;
	while (str1[cmpt] != '\0' && cmpt < (int)ft_strlen(str1))
	{
		if (str1[cmpt] != '\n')
			return (0);
		cmpt = cmpt + 21;
	}
	if (str1[(int)ft_strlen(str1)] != '\0')
		return (0);
	return (1);
}
