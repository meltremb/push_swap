/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:32:07 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:43 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	is_valid(char *item_name)
{
	int	validity;
	int	i;

	i = -1;
	validity = 1;
	if (item_name[0] == '-' || item_name[0] == '+')
		if (!('0' <= item_name[1] && item_name[1] >= '9'))
			validity = 0;
		i++;
	while (item_name[++i])
		if (!('0' <= item_name[i] && item_name[i] <= '9'))
			validity = 0;
	return (validity);
}

int	is_name_legit(int argc, char **argv)
{
	int	validity;
	int	i;

	i = 0;
	validity = 1;
	while (++i < argc)
	{
		if (!is_valid(argv[i]))
			validity = 0;
	}
	if (!validity)
		write (1, "ERROR\n", 6);
	return (validity);
}

int	is_item_legit(int *items, int size)
{
	int	validity;
	int	i;
	int	j;

	i = -1;
	validity = 1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (items[i] == items[j] && i != j)
				validity = 0;
	}
	if (!validity)
		write(1, "ERROR\n", 6);
	return (validity);
}

void	shuffle_up(t_player *player)
{
	int	i;

	i = (*player).slot;
	while (++i < (*player).inventory_size)
		(*player).inventory[i - 1] = (*player).inventory[i];
	(*player).inventory[i - 1] = 0;
	(*player).charge--;
}

void	shuffle_down(t_player *player)
{
	int	i;

	i = (*player).inventory_size;
	while ((*player).slot < i--)
		(*player).inventory[i + 1] = (*player).inventory[i];
	(*player).inventory[(*player).slot] = 0;
	(*player).charge++;
}
