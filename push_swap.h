/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:30:14 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:46 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"./libft/libft.h"
# include<stdlib.h>
# include<unistd.h>

typedef struct s_player
{
	int	*inventory;
	int	slot;
	int	charge;
	int	inventory_size;
}		t_player;

void		p_swap(t_player *player);
void		p_push(t_player *steve, t_player*alex);
void		p_rotate(t_player *player);
void		p_reverse_rotate(t_player *player);
void		p_double_swap(t_player *steve, t_player *alex);
void		p_double_rotate(t_player *steve, t_player *alex);
void		p_double_reverse_rotate(t_player *steve, t_player *alex);
int			*list_maker(int argc, char **argv, int *items);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
t_player	spawner(int *items);
t_player	respawner(int size);
int			*indexer(int *items, int size);
int			is_name_legit(int argc, char **argv);
int			is_item_legit(int *items, int size);
void		shuffle_down(t_player *player);
void		shuffle_up(t_player *player);
void		ss(t_player *steve, t_player *alex, int type);
void		pp(t_player *steve, t_player *alex, int type);
void		rr(t_player *steve, t_player *alex, int type);
void		rrr(t_player *steve, t_player *alex, int type);
int			look_for(t_player *player, int range_min, int range_max);
void		low_sort(t_player *steve, t_player *alex);
int			is_sorted(t_player *steve);
void		rotate_to_in_range(t_player *rotated, t_player *other, int range);
void		debug_print(t_player *steve, t_player *alex);
int			look_up(t_player *player, int range_min, int range_max);
int			look_down(t_player *player, int range_min, int range_max);

#endif
