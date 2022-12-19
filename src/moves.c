/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:21 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/12/14 21:58:21 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stack(t_node *node)
{
	int num;

	num  = node->num;
	while(node->next)
	{
		node->num = node->next->num;
		node = node->next;
	}
	// insert_front(node, init_num(num));
	node->num = num;
}

// void r_rotate_stack(t_node *node)
// {
	
// }