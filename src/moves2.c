/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:28:34 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/02/03 23:34:58 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(p_swap push_swap)
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

void pb(p_swap push_swap)
{
	t_node *a;

	int num;
	if (listlen(push_swap.stackb) > 0)
	{
		printf("pb\n");
		num = pop(push_swap.stackb);
		a = init_num(num);
		if (listlen(push_swap.stacka) == 0)
			*(push_swap.stackb) = a;
		else
		{
			insert_front(*(push_swap.stacka), a);
			move_s(*push_swap.stacka);
		}
	}
}

void ra(p_swap *push_swap)
{
	move_r(*(push_swap->stacka));
	printf("ra\n");
}

void rb(p_swap *push_swap)
{
	move_r(*(push_swap->stackb));
	printf("rb\n");
}

void rrb(p_swap *push_swap)
{
	move_rr(*(push_swap->stackb));
	printf("rrb\n");
}

void rra(p_swap *push_swap)
{
	move_rr(*(push_swap->stacka));
	printf("rra\n");
}

void sa(p_swap push_swap)
{
	printf("sa\n");
	move_s(*(push_swap.stacka));
}
void sb(p_swap push_swap)
{
	printf("sb\n");
	move_s(*(push_swap.stackb));
}