/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:07:43 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/04 00:14:56 by lucdos-s         ###   ########.fr       */
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

void	ra(t_pswap *push_swap)
{
	move_r(*(push_swap->stacka));
	printf("ra\n");
}

void	rb(t_pswap *push_swap)
{
	move_r(*(push_swap->stackb));
	printf("rb\n");
}

void	multi_rb(t_pswap push_swap, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rb(&push_swap);
		i++;
	}
}

void	multi_rra(t_pswap push_swap, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rra(&push_swap);
		i++;
	}
}
