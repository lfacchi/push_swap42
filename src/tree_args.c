/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:07:02 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/01/23 21:25:12 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		tree_args_factor(t_node *node)
{
	int top;
	int mid;
	int bottom;
	int sum;

	sum = 0;
	node = node->next;
	top = node->num; 
	mid = node->next->num; 
	bottom = node->next->next->num;
	if(top > mid)
		sum++;
	if(top > bottom)
		sum++;
	if(mid > bottom)
		sum = sum + 3;	
	return (sum);
}

void	select_moves_3(p_swap push_swap, int factor)
{
	if(factor == 1)
		sa(push_swap);
	if(factor == 2)
		ra(&push_swap);
	if(factor == 3)
	{
		sa(push_swap);	
		ra(&push_swap);	
	}
	if(factor == 4)
		rra(&push_swap);
	if(factor == 5)
	{
		sa(push_swap);
		rra(&push_swap);
	}
}

void sort_3(p_swap push_swap)
{
	t_node	*temp;
	int		factor;
	temp = push_swap.stacka[0];
	factor = tree_args_factor(temp);
	select_moves_3(push_swap, factor);
}