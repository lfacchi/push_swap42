/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:34:47 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/02/01 21:28:35 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void five_args(p_swap push_swap)
{
	t_node *temp;
	temp = *(push_swap.stacka);
	while(temp->num != get_low(push_swap.stacka))
	{
		ra(&push_swap);
		temp = *(push_swap.stacka);
	}
	pa(push_swap);
	// printf("head: %d\n", temp->num);
	while((temp->num != get_high(push_swap.stacka)))
	{
		ra(&push_swap);
		temp = *(push_swap.stacka);
	}
	pa(push_swap);
	// sort_3(push_swap);
	// pb(push_swap);
	// pb(push_swap);
}

int get_high(t_node **stacka)
{
	int top;
	t_node *temp;
	
	temp = *stacka;
	temp = temp->next;
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
	temp = temp->next;
	low = temp->num;
	while(temp)
	{
		if(low > temp->num)
			low = temp->num;
		temp = temp->next;
	}
	return(low);
}

