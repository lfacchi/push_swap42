/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:28:34 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/02 14:56:30 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_pswap *push_swap)
{
	move_r(*(push_swap->stacka));
	printf("ra\n");
}

void rb(t_pswap *push_swap)
{
	move_r(*(push_swap->stackb));
	printf("rb\n");
}

void rrb(t_pswap *push_swap)
{
	move_rr(*(push_swap->stackb));
	printf("rrb\n");
}

void rra(t_pswap *push_swap)
{
	move_rr(*(push_swap->stacka));
	printf("rra\n");
}

void sa(t_pswap push_swap)
{
	printf("sa\n");
	move_s(*(push_swap.stacka));
}
void sb(t_pswap push_swap)
{
	printf("sb\n");
	move_s(*(push_swap.stackb));
}