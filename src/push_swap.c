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

p_swap start_program(int argc, char **argv)
{
	int		*list;
	// int		listb;
	int		i; 
	p_swap	program;

	// listb = 1;
	list = ft_calloc(argc, sizeof(int));
	i = -1;
	// program.stackb = create_list(&listb, 1);
	while(++i < argc - 1)
		list[i] = ft_atoi(argv[i + 1]);
	program.stacka = create_list(list, argc - 1);
	program.stackb = ft_calloc(1, sizeof(struct t_node*));
	return (program);
}
