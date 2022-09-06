/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:30:31 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:45 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*list_maker(int argc, char **argv, int *items)
{
	int	i;
	int	item;

	items = ft_calloc(argc, sizeof(int));
	i = -1;
	while (argv[++i + 1])
	{
		item = ft_atoi(argv[i + 1]);
		items[i] = item;
	}
	return (items);
}

struct s_player	spawner(int *items)
{
	struct s_player	steve;
	int				i;

	i = 0;
	while (items[i])
		i++;
	steve.inventory = items;
	steve.slot = 0;
	steve.charge = i;
	steve.inventory_size = i;
	return (steve);
}

struct s_player	respawner(int size)
{
	struct s_player	alex;
	int				*empty_inventory;

	empty_inventory = ft_calloc(size + 1, sizeof(int));
	alex.inventory = empty_inventory;
	alex.slot = 0;
	alex.charge = 0;
	alex.inventory_size = size;
	return (alex);
}

static int	mine_straight_down(int *items, int quantity, int size)
{
	int	i;
	int	mined_blocks;

	i = -1;
	mined_blocks = 1;
	while (++i < size)
		if (items[i] < quantity)
			mined_blocks += 1;
	return (mined_blocks);
}

int	*indexer(int *items, int size)
{
	int	i;
	int	*indexed_items;

	indexed_items = ft_calloc(size, sizeof(int));
	i = -1;
	while (++i < size)
		indexed_items[i] = mine_straight_down(items, items[i], size);
	free(items);
	return (indexed_items);
}
