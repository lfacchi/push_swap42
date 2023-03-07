/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:06:52 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/05 20:05:05 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pswap push_swap)
{
	t_node	*a;
	int		num;

	a = NULL;
	if (listlen(push_swap.stacka) > 0)
	{
		write(1, "pb\n", 3);
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
		write(1, "pa\n", 3);
		num = pop(push_swap.stackb);
		a = init_num(num);
		if (listlen(push_swap.stacka) == 0)
			*(push_swap.stacka) = a;
		else
			insert_front(push_swap.stacka, a);
	}
}
