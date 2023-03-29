/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:11:17 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/29 10:56:24 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

char	*dec2bin(int d, int digits)
{
	char	*bin;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	len = digit_lenght(digits);
	bin = ft_calloc(len, sizeof(char));
	ft_bzero(bin, digits);
	while (i < len)
	{
		if (d % 2)
			bin[i] = '1';
		else
			bin[i] = '0';
		d /= 2;
		i++;
	}
	j = -1;
	while (++j < (i / 2))
	{
		swap(bin[j], bin[i - j - 1]);
	}
	return (bin);
}

void	print_list(t_node *node, char mode)
{
	while (node)
	{
		if (mode == 'b')
			ft_putstr_fd(dec2bin(node->num, 32), 1);
		else
			ft_putnbr_fd(node->num, 1);
		node = node->next;
	}
}

int	count_moves(int num, t_node **stack)
{
	t_node	*temp;
	int		moves;
	int		len;

	moves = 0;
	len = listlen(stack);
	temp = *stack;
	while (temp)
	{
		if (temp->num == num)
			break ;
		if (temp->next)
			temp = temp->next;
		moves++;
	}
	if (moves > (len / 2))
		moves = -(len - moves);
	return (moves);
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
