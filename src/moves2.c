/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:28:34 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/01/17 16:49:00 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(p_swap *push_swap)
{
	move_p(push_swap->stackb, push_swap->stacka);
	print_list("pa\n");
}

void pb(p_swap *push_swap)
{
	move_p(push_swap->stacka, push_swap->stackb);
	print_list("pb\n");
}

void ra(p_swap *push_swap)
{
	move_r(push_swap->stacka);
	printf("ra\n");
}

void rb(p_swap *push_swap)
{
	move_r(push_swap->stackb);
	printf("rb\n");
}

void rrb(p_swap *push_swap)
{
	move_rr(push_swap->stackb);
	printf("rrb\n");
}

void rra(p_swap *push_swap)
{
	move_rra(push_swap->stackb);
	printf("rra\n");
}

