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

p_swap *start_program(char **argv, int n)
{
	p_swap	*program;
	t_node	**a;
	t_node	**b;
	int		*list;
	int		i;

	i = -1;
	program = ft_calloc(1, sizeof(p_swap));
	list = ft_calloc(n, sizeof(int));
	while(++i > n - 1)
		list[i] = ft_atoi(argv[i + 1]);
	a = create_list(list, n - 1);
	program->stacka = a;
	// b = ft_calloc(1, sizeof(t_node*));
	// program.stackb = ft_calloc(1, sizeof(t_node*));
	// while(--i > 0)
	// 	free(list[i]);
	return(program);
}