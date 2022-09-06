/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:08:12 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:43 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	debug_print(t_player *steve, t_player *alex)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	printf("\n   steve         alex\n");
	printf("  size:%d        size:%d\n", (*steve).inventory_size, (*alex).inventory_size);
	printf(" charge:%d      charge:%d\n", (*steve).charge, (*alex).charge);
	while (i < (*steve).inventory_size)
	{
		c1 = ' ';
		c2 = ' ';
		if ((*steve).slot == i)
			c1 = '>';
		if ((*alex).slot == i)
			c2 = '>';
		if ((*steve).inventory[i] || (*alex).inventory[i])
			printf(" | %c %-4d|     | %c %-4d|\n", c1, (*steve).inventory[i], c2, (*alex).inventory[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_player	steve;
	t_player	alex;
	int				*items;

	if (!is_name_legit(argc, argv))
		return (1);
	items = NULL;
	items = list_maker(argc, argv, items);
	items = indexer(items, argc - 1);
	if (!is_item_legit(items, argc - 1))
		return (2);
	steve = spawner(items);
	alex = respawner(steve.inventory_size);
	debug_print(&steve, &alex);
	low_sort(&steve, &alex);
	debug_print(&steve, &alex);
	return (0);
}
