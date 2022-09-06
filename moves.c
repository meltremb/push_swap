/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:27:57 by meltremb          #+#    #+#             */
/*   Updated: 2022/09/06 12:54:41 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ss(t_player *steve, t_player *alex, int type)
{
	if (type == 0)
	{
		write(1, "\nsa", 3);
		p_swap(steve);
	}
	else if (type == 1)
	{
		write(1, "\nsb", 3);
		p_swap(alex);
	}
	else if (type == 2)
	{
		write(1, "\nss", 3);
		p_swap(steve);
		p_swap(alex);
	}
}

void	pp(t_player *steve, t_player *alex, int type)
{
	if (type == 0)
	{
		write(1, "\npb", 3);
		p_push(steve, alex);
	}
	else if (type == 1)
	{
		write(1, "\npa", 3);
		p_push(alex, steve);
	}
}

void	rr(t_player *steve, t_player *alex, int type)
{
	if (type == 0)
	{
		write(1, "\nra", 3);
		p_rotate(steve);
	}
	else if (type == 1)
	{
		write(1, "\nrb", 3);
		p_rotate(alex);
	}
	else if (type == 2)
	{
		write(1, "\nrr", 3);
		p_rotate(steve);
		p_rotate(alex);
	}	
}

void	rrr(t_player *steve, t_player *alex, int type)
{
	if (type == 0)
	{
		write(1, "\nrra", 4);
		p_reverse_rotate(steve);
	}
	else if (type == 1)
	{
		write(1, "\nrrb", 4);
		p_reverse_rotate(alex);
	}
	else if (type == 2)
	{
		write(1, "\nrrr", 4);
		p_reverse_rotate(steve);
		p_reverse_rotate(alex);
	}
}
