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

void move_r(t_node *node)
{
	int num;

	num = node->num;
	while (node->next)
	{
		node->num = node->next->num;
		node = node->next;
	}
	node->num = num;
}

void move_rr(t_node *node)
{
	int top;
	int temp;

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

void move_s(t_node *node)
{
	int temp;

	temp = node->num;
	node->num = node->next->num;
	node->next->num = temp;
}

void move_p(t_node **node1, t_node *node2)
{
	t_node *temp;
	int num;

	num = pop(node1);
	insert_front(node2, init_num(num));
}
