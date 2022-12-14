/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:18:19 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/11/29 16:18:19 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_num(int v_node)
{
	t_node *node;

	node = malloc(sizeof(t_node*));
	node->next = NULL;
	node->num = v_node;
	return(node);
}



void insert_node(t_node *node_list, t_node *node)
{
	if (!node_list)
		return ;
	if (node_list == NULL)
	{
		node_list = node;
		return ;
	}
	node_list->next = node;
	return ;
}

// void create_list(int *n_list, t_node *head_node)
// {
// 	t_node node;
// 	int i;

// 	i = 0;
// 	while(n_list[i])
// 	{
// 		node = init_num(n_list[i]);  
// 	}
// }