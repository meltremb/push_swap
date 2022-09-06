/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:24:23 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:47 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	find_range(int charge)
{
	int	i;

	i = -1;
	if (charge > 5)
		while (++i <= (charge / 2))
		{
			if ((i) * (i) <= charge && charge <= (i) * (i + 1))
				return (i + 1);
			if ((i) * (i + 1) < charge && charge < (i + 1) * (i + 1))
				return (i + 2);
		}
	return (1);
}

void	low_sort(t_player *steve, t_player *alex)
{
	rotate_to_in_range(steve, alex, 10);


	//while (!is_sorted(steve))
		//push_wrong_ones(steve, alex);
}

int	is_sorted(t_player *steve)
{
	int	i;

	i = 0;
	while ((*steve).inventory[(*steve).slot + i] <= (*steve).charge)
	{
		if ((*steve).inventory[(*steve).slot + i]
			> (*steve).inventory[(*steve).slot + i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	rotate_to_in_range(t_player *steve, t_player *alex, int range)
{
	int	direction;
	int	middle;

	middle = ((*steve).inventory_size / 2) + 1;
	direction = look_for(steve, middle - range, middle + range);
	while (1)
	{
		if (direction == 0)
			break;
		else if (direction < 0)
		{
			rrr(steve, alex, 0);
			direction++;
		}
		else if (direction > 0)
		{
			rr(steve, alex, 0);
			direction--;
		}
	}
	pp(steve, alex, 0);
	if (((*alex).inventory_size + 1 )/ 2 < (*alex).inventory[(*alex).slot]
	&& (*steve).inventory[0] && (*alex).inventory[1])
		rr(steve, alex, 1);
}
