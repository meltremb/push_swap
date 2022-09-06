/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:17:39 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:49 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	p_swap(t_player *player)
{
	int	chest;

	if ((*player).inventory_size >= 2 && (*player).slot != (*player).charge - 1)
	{
		chest = (*player).inventory[(*player).slot];
		(*player).inventory[(*player).slot]
			= (*player).inventory[(*player).slot + 1];
		(*player).inventory[(*player).slot + 1] = chest;
	}
	else if ((*player).inventory_size >= 2
		&& (*player).slot == (*player).charge - 1)
	{
		chest = (*player).inventory[(*player).slot];
		(*player).inventory[(*player).slot] = (*player).inventory[0];
		(*player).inventory[0] = chest;
	}
}

void	p_push(t_player *giver, t_player *receiver)
{
	if ((*giver).inventory[(*giver).slot] != 0)
	{
		shuffle_down(receiver);
		(*receiver).inventory[(*receiver).slot]
			= (*giver).inventory[(*giver).slot];
		shuffle_up(giver);
		if ((*giver).slot >= (*giver).charge)
			(*giver).slot = 0;
	}
}

void	p_reverse_rotate(t_player *player)
{
	if (0 < (*player).slot)
		(*player).slot--;
	else
		(*player).slot = (*player).charge - 1;
}

void	p_rotate(t_player *player)
{
	if ((*player).slot < (*player).charge - 1)
		(*player).slot++;
	else
		(*player).slot = 0;
}
