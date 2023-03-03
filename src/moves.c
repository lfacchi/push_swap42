/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:21 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/12/14 21:58:21 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_r(t_node *node)
{
	int	num;

	num = node->num;
	while (node->next)
	{
		node->num = node->next->num;
		node = node->next;
	}
	node->num = num;
}

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

void	move_s(t_node *node)
{
	int	temp;

	temp = node->num;
	node->num = node->next->num;
	node->next->num = temp;
}

void	pa(t_pswap push_swap)
{
	t_node	*a;
	int		num;

	a = NULL;
	if (listlen(push_swap.stacka) > 0)
	{
		printf("pb\n");
		num = pop(push_swap.stacka);
		a = init_num(num);
		if (listlen(push_swap.stackb) == 0)
			*(push_swap.stackb) = a;
		else
			insert_front(push_swap.stackb, a);
	}
}

void	pb(t_pswap push_swap)
{
	t_node	*a;
	int		num;

	a = NULL;
	if (listlen(push_swap.stackb) > 0)
	{
		printf("pa\n");
		num = pop(push_swap.stackb);
		a = init_num(num);
		if (listlen(push_swap.stacka) == 0)
			*(push_swap.stacka) = a;
		else
			insert_front(push_swap.stacka, a);
	}
}
