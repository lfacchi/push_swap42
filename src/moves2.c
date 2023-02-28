/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:28:34 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/02/27 20:16:07 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_pswap push_swap)
{
	t_node *a;

	int num;
	if(listlen(push_swap.stacka) > 0)
	{
		printf("pa\n");
		num = pop(push_swap.stacka);
		a = init_num(num);
		if (listlen(push_swap.stackb) == 0)
			*(push_swap.stackb) = a;
		else
		{
			insert_front(*(push_swap.stackb), a);
			move_s(*(push_swap.stackb));
		}
	}
}

void pb(t_pswap push_swap)
{
	t_node *a;

	int num;
	if (listlen(push_swap.stackb) > 0)
	{
		printf("pb\n");
		num = pop(push_swap.stackb);
		a = init_num(num);
		if (listlen(push_swap.stacka) == 0)
			*(push_swap.stacka) = a;
		else
		{
			insert_front(*(push_swap.stacka), a);
			move_s(*push_swap.stacka);
		}
	}
}

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