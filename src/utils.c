/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:05:19 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/12/14 22:05:19 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_num(int v_node)
{
	t_node *node;
	if (v_node)
	{
		node = malloc(sizeof(t_node*));
		node->next = NULL;
		node->num = v_node;
		return(node);
	}
	else
		return NULL;
}

void insert_front(t_node *head, t_node *node)
{
	if (!head)
		return ;
	if (head == NULL)
	{
		head = node;
		return ;
	}
	if (head->next != NULL)
		node->next = head->next;
	head->next = node;
	return ;
}

void insert_back(t_node *tail, t_node *new)
{
	int temp;
	if (!tail)
		return ;
	if (tail == NULL)
		tail = new;
	temp = tail->num;
	tail->num = new->num;
	insert_front(tail, new);
	tail->next->num = temp;
}

void print_list(t_node *node)
{
	int i;
	i = 0;
	while (node)
	{
			printf("%d | %d\n", i, node->num);
			node = node->next;
			i++; 	
	}
}

// void free_list(t_node *node)
// {
// 	t_node *temp;
// 	while(node)
// 	{
// 		temp = node->next;
// 		free(node);
// 		node = *temp;
		
// 	}
// }