/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:34:47 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/02/27 17:27:56 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void five_args(t_pswap push_swap)
{
	t_node *temp;
	int h;
	int l;
	int count;
	
	count = 0;
	h = get_high(push_swap.stacka);
	l = get_low(push_swap.stacka);
	temp = *(push_swap.stacka);
	while((temp->num != h || temp->num != l) && count != 2)
	{
		select_rotate(temp, push_swap.stacka);
		temp = *(push_swap.stacka);
		if((temp->num == h || temp->num == l))
		{
			pa(push_swap);
			count++;
		}
	}
	temp = *(push_swap.stackb);
	if (temp->num != l)
		rb(&push_swap);
	ra(&push_swap);	
	sort_3(push_swap);
	pb(push_swap);
	pb(push_swap);
	ra(&push_swap);	
}

int get_high(t_node **stacka)
{
	int top;
	t_node *temp;
	
	temp = *stacka;
	top = temp->num;
	while(temp)
	{
		if(top < temp->num)
			top = temp->num;
		temp = temp->next;
	}
	return (top);
}

int	get_low(t_node **stacka)
{
	int low;
	t_node *temp;
	
	temp = *stacka;
	low = temp->num;
	while(temp)
	{
		if(low > temp->num)
			low = temp->num;
		temp = temp->next;
	}
	return(low);
}