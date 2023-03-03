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
	t_node	*node;

	node = NULL;
	if (v_node)
	{
		node = malloc(sizeof(t_node));
		node->next = NULL;
		node->num = v_node;
	}
	return (node);
}

/*
	@brief insert a node after the last node the head node
	@param head pointer to head node of linked list
	@param node pointer to node be added
 */
void	insert_front(t_node **head, t_node *node)
{
	if (head == NULL || node == NULL)
		return ;
	node->next = *head;
	*head = node;
}

/*
@brief Returns the last number of a node list
@param node t_node node
 */
int	top_value(t_node node)
{
	int	top;

	while (node.next)
	{
		node.num = node.next->num;
		node = *node.next;
	}
	top = node.num;
	return (top);
}

/*
@brief Returns the lenght of a  node list
@param node t_node node
 */
int	listlen(t_node **node_list)
{
	t_node	*temp;
	int		top;

	if (node_list == NULL)
		return (0);
	top = 0;
	temp = *node_list;
	while (temp)
	{
		top++;
		temp = temp->next;
	}
	return (top);
}

/*
 @brief return 1if th stack was sorted and 0 if is not
*/
int	is_sorted(t_node **stack)
{
	t_node	*current;
	int		c;

	current = *(stack);
	c = 0;
	while (current != NULL && current->next != NULL)
	{
		if (current->num > current->next->num)
		{
			c = 1;
			break ;
		}
		current = current->next;
	}
	if (c == 1)
		return (0);
	else
		return (1);
}