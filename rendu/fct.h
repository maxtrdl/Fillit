/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:58:32 by rqueverd          #+#    #+#             */
/*   Updated: 2016/12/16 16:11:53 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
# define FCT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUFFER 4096

typedef struct	s_position
{
	int	x[4];
	int	y[4];
}				t_position;

void			ft_putchar(int c);
void			ft_putstr(char *src);
size_t			ft_strlen(const char *str);
int				ft_check_char_tetriminos(char *str1, int i, int i_mult,\
	int multiplicateur);
int				ft_check_sharps_tetriminos (char *str1, int i);
int				ft_check_links(char *str1, int i);
int				ft_count_links(char *str1, int i, int count_links);
char			***ft_init_matrice (char *str1);
int				ft_verif_tetriminos(char *str1);
void			ft_solve(char *str2);
int				**ft_stockindice(char ***tetriminos, char *str1);
t_position		*ft_map(char *str, int i, int j, int k);
void			ft_affiche_struct(t_position *tetriminos, char *str);
void			ft_affiche_tab(char **tableau, int taille);
int				ft_nb_tetriminos(char *str2);
char			**ft_remplissage_final_tableau(int taille);
t_position		*ft_mise_a_zero(t_position *tetriminos, int nb_tetriminos);
void			ft_free_map(char **tableau, int taille);
void			ft_place_tetri(char **tableau, t_position tetriminos, \
	int pos, int k);
int				ft_is_possible (char **tableau, t_position tetriminos,\
	int pos, int taille);
int				ft_sqrt(int nb);
char			*ft_read(int argc, char **argv, int fd);
int				ft_check_nb_tetri(char **tableau, int taille);
void			ft_remove_tetri(char **tableau, int k, int taille);
int				ft_print_tetri(char **tableau, t_position *tetriminos,\
	int nb_tetriminos, int k);
int				ft_check_newline(char *str1);
#endif
