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
/* 
	@brief insert a node after the last node the head node
	@param head pointer to head node of linked list
	@param node pointer to node be added 
 */
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

int	top_value(t_node node)
{
	int top;
	while(node.next)
	{
		node.num = node.next->num;
		node = *node.next;
	}
	top = node.num;
	return (top); 
}

t_node	**create_list(int *num_list)
{
	int i = 0;
	int j;
	t_node	**node_list;
	t_node	*temp;

	node_list = ft_calloc(1, sizeof(t_node *));
	while(num_list[i])
	{
		if(i == 0)
		{
			*node_list = init_num(num_list[i]);
		}
		else
		{
			temp = init_num(num_list[i]);
			insert_front(*node_list, temp);
		}
		i++;
	}
	return(node_list);
}
