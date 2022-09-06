/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:01:47 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:42 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	is_in_range(int value, int range_min, int range_max)
{
	if (range_min <= value && value <= range_max)
		return(1);
	else
		return(0);
}

int	look_up(t_player *player, int range_min, int range_max)
{
	int	i;
	int	distance;

	i = (*player).slot;
	distance = 0;
	while (1)
	{
		i--;
		distance--;
		if (i < 0)
			i = (*player).charge - 1;
		if (is_in_range((*player).inventory[i], range_min, range_max) || i == (*player).slot)
			break ;
	}
	return (distance);
}

int	look_down(t_player *player, int range_min, int range_max)
{
	int	i;
	int	distance;

	i = (*player).slot;
	distance = 0;
	while (1)
	{
		i++;
		distance++;
		if ((*player).charge - 1 < i)
			i = 0;
		if (is_in_range((*player).inventory[i], range_min, range_max) || i == (*player).slot)
			break ;
	}
	return (distance);
}

int	look_for(t_player *player, int range_min, int range_max)
{
	int	distance_down;
	int	distance_up;

	if (range_min <= (*player).inventory[(*player).slot] && (*player).inventory[(*player).slot] <= range_max)
		return (0);
	distance_down = look_down(player, range_min, range_max);
	distance_up = look_up(player, range_min, range_max);
	printf("\ndistance down: %d\n", distance_down);
	printf("\ndistance up: %d\n", distance_up);
	if (-distance_up < distance_down)
		distance_down = distance_up;
	return (distance_down);
}