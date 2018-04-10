/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:30:22 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/16 12:28:56 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_sqrt(int nb)
{
	int x;

	x = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (x * x < nb)
		x++;
	return (x);
}

int			check_file_exist(int *fd, char **argv)
{
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

char		*ft_read(int argc, char **argv, int fd)
{
	char	*str1;
	char	buf[BUFFER + 1];
	int		ret;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (check_file_exist(&fd, argv) != 1)
		return (0);
	while ((ret = read(fd, buf, BUFFER)) != 0)
	{
		str1 = buf;
		buf[ret] = '\0';
	}
	if (buf[ret] == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	str1[BUFFER] = '\0';
	close(fd);
	return (str1);
}

int			ft_nb_tetriminos(char *str2)
{
	return (ft_strlen(str2) / 21 + 1);
}
