/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:10:10 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/05 20:06:08 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_s(t_node *node)
{
	int	temp;

	temp = node->num;
	node->num = node->next->num;
	node->next->num = temp;
}

void	sa(t_pswap push_swap)
{
	write(1, "sa\n", 3);
	move_s(*(push_swap.stacka));
}

void	sb(t_pswap push_swap)
{
	write(1, "sb\n", 3);
	move_s(*(push_swap.stackb));
}
