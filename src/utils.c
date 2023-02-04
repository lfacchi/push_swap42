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
	if (head == NULL)
	{
		head = node;
		return ;
	}
	if (!head->num)
		return;
	if (head->next)
		node->next = head->next;
	head->next = node;
	return ;
}




void print_list(t_node *node)
{
	// node = node->next;
	while (node)
	{
		printf("%d\n", node->num);
		node = node->next;
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

int	listlen(t_node **node_list)
{
	t_node *temp;
	int top;

	if(node_list == NULL)
		return(0);
	top = 0;
	temp = *node_list;
	while(temp)
	{
		top++;
		temp = temp->next;
	}
	return (top); 
}

/* 
@brief Allocate a and create a linkd list
@param num_list a list of intgers
 */
t_node	**create_list(int *num_list, int n)
{
	int i;
	t_node	**node_list;
	t_node	*temp;

	node_list = ft_calloc(1, sizeof(t_node *));
	*node_list = malloc(sizeof(t_node));
	*node_list = init_num(*num_list);
	i = 1;
	while(i < n)
	{	
		temp = init_num(num_list[i]);
		insert_front(*node_list, temp);
		i++;
	}
	// printf("%d\n", node_list[0]->num);
	return(node_list);
}

int pop(t_node **node_list)
{
    t_node	*head = *node_list;
    int		result;

    // head = head->next;
    result = head->num;
    if (*node_list == NULL)
        return -1;
    (*node_list) = (*node_list)->next;
 
    return result;
}

int get_mid_position(t_node **stack)
{
	t_node *temp;
	int len;

	len = listlen(stack);
	temp = *stack;
	temp = temp->next;
	len /= 2;
	return (len);
}
