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




void print_list(t_node *node, char mode)
{
	// node = node->next;
	while (node)
	{
		if(mode == 'b')
			printf("%s\n", dec2bin(node->num, 5));
		else
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
	*node_list = init_num(*num_list);
	i = 1;
	while(i < n)
	{	
		temp = init_num(num_list[i]);
		insert_front(*node_list, temp);
		i++;
	}
	return(node_list);
}

int pop(t_node **node_list)
{
    t_node	*head = *node_list;
    int		result;

    result = head->num;
    if (*node_list == NULL)
        return -1;
    (*node_list) = (*node_list)->next;
	free(head);
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

void select_rotate(t_node *node, t_node **stack)
{
	int len;
	int count = 0;
	t_node *temp;

	len = listlen(stack);
	temp = node;
	while(temp->next)
	{
		count++;
		temp = 	temp->next;
	}
	if (count > (len / 2))
		move_rr(*(stack));
	else
		move_r(*stack);
}

void is_sorted(t_node **stack)
{
    t_node *current = *(stack);
	int c;

	c = 0;
    while (current != NULL && current->next != NULL)
	{
		if (current->num > current->next->num)
		{
			c = 1;
			break;
			// return(0);
		}
		current = current->next;
	}
	if(c == 1)
		printf("\033[31mKO\033[0m\n");
	else
		printf("\033[32mOK\033[0m\n");
	// return(1);
}

void multi_ra(t_pswap push_swap, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		ra(&push_swap);
		i++;
	}
}

void multi_rb(t_pswap push_swap, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		rb(&push_swap);
		i++;
	}
}

void multi_rra(t_pswap push_swap, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		rra(&push_swap);
		i++;
	}
}

void multi_rrb(t_pswap push_swap, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		rrb(&push_swap);
		i++;
	}
}
const char * dec2bin(int d, int digits)
{
	char *bin;
    int i = 0;
    int j = 0;
	int len;
	len = digit_lenght(digits);
	bin = ft_calloc(len,sizeof(char));
	ft_bzero(bin,digits);
    for(i = 0; i < len; d /= 2, i++)
	{
        bin[i] = (d % 2) ? '1' : '0';
	}

    for( j = 0; j < (i / 2); j++ )
        swap( bin[j], bin[ i - j - 1] );


    return bin;
}

void free_list(t_node *head)
{
    t_node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void free_pswap(t_pswap *pswap)
{
    free_list(*(pswap)->stacka);
    free_list(*(pswap)->stackb);
    free(pswap->stacka);
    free(pswap->stackb);
}