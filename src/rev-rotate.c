/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev-rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:08:56 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/05 20:05:40 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rr(t_node *node)
{
	int	top;
	int	temp;

	top = top_value(*node);
	temp = node->num;
	node->num = top;
	if (node->next)
		top = node->next->num;
	node = node->next;
	while (node)
	{
		node->num = temp;
		temp = top;
		if (node->next)
			top = node->next->num;
		node = node->next;
	}
}

void	rrb(t_pswap *push_swap)
{
	move_rr(*(push_swap->stackb));
	write(1, "rrb\n", 4);
}

void	rra(t_pswap *push_swap)
{
	move_rr(*(push_swap->stacka));
	write(1, "rra\n", 4);
}

void	multi_ra(t_pswap push_swap, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ra(&push_swap);
		i++;
	}
}

void	multi_rrb(t_pswap push_swap, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrb(&push_swap);
		i++;
	}
}
