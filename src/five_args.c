/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:34:47 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/04 00:22:24 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_args(t_pswap push_swap)
{
	int		low;
	int		second;

	low = 1;
	second = 2;
	if (ft_abs(count_moves(low, push_swap.stacka))
		<= ft_abs(count_moves(second, push_swap.stacka)))
	{
		select_rotate(low, push_swap);
		pa(push_swap);
		select_rotate(second, push_swap);
		pa(push_swap);
	}
	else if (ft_abs(count_moves(second, push_swap.stacka))
		< ft_abs(count_moves(low, push_swap.stacka)))
	{
		select_rotate(second, push_swap);
		pa(push_swap);
		select_rotate(low, push_swap);
		pa(push_swap);
	}
	if ((*push_swap.stackb)->num != second)
		rb(&push_swap);
	final_five_args(push_swap);
}

int	get_low(t_node **stacka)
{
	int		low;
	t_node	*temp;

	temp = *stacka;
	low = temp->num;
	while (temp)
	{
		if (low > temp->num)
			low = temp->num;
		temp = temp->next;
	}
	return (low);
}

void	final_five_args(t_pswap push_swap)
{
	three_args(push_swap);
	pb(push_swap);
	pb(push_swap);
}
