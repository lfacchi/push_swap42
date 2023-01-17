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
		node = malloc(sizeof(t_node));
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

// void insert_back(t_node **node_list, t_node *new)
// {
// 	t_node *temp;

// 	temp = node_list[0]->next;
// 	if (!node_list)
// 		return ;
// 	if (node_list == NULL)
// 		node_list = new;
// 	insert_front(temp, new);
// }

/* @brief print all elements of an linked list */
void print_list(t_node *node)
{
	int i;
	i = 0;
	node = node->next;
	while (node)
	{
		printf("%d\n", node->num);
		node = node->next;
		i++; 	
	}
}

/* 
@brief Returns the last number of a node list
@param node t_node node
 */
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

/* @brief get the lenght of a integers list */
int	listlen(int *list)
{
	int top;
	
	while(list[top])
		top++;
	return (top); 
}

/* 
@brief Allocate a and create a linkd list
@param num_list a list of intgers
 */
t_node	**create_list(int *num_list, int n)
{
	int i = n;
	t_node	**node_list;
	t_node	*temp;

	node_list = ft_calloc(1, sizeof(t_node *));
	*node_list = malloc(sizeof(t_node));
	while(i >= 0)
	{
		temp = init_num(num_list[i]);
		insert_front(*node_list, temp);
		i--;
	}
	return(node_list);
}

/* @brief get the data and delete the first element of a linked list */
int pop(t_node **node_list)
{
    t_node	*head = *node_list;
    int		result;

    head = head->next;
    result = head->num;
    if (*node_list == NULL)
        return -1;
    (*node_list) = (*node_list)->next;
    return result;
}