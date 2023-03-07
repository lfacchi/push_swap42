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

/* 
@brief Start the program, using the terminal arguments as input
*/
t_pswap	start_program(int argc, char **argv)
{
	int		*list;
	int		i;
	t_pswap	program;

	check_num(argv);
	list = ft_calloc(argc, sizeof(int));
	i = -1;
	while (++i < argc - 1)
		list[i] = ft_atoi(argv[i + 1]);
	check_duplicate(list);
	transform_array(list, argc - 1);
	program.stacka = create_list(list);
	program.stackb = ft_calloc(1, sizeof(struct t_node *));
	free(list);
	return (program);
}

/*
@brief Allocate a and create a linkd list
@param num_list a list of intgers
 */
t_node	**create_list(int *num_list)
{
	int		i;
	t_node	**node_list;
	t_node	*temp;

	temp = NULL;
	i = 0;
	while (num_list[i])
		i++;
	node_list = ft_calloc(1, sizeof(t_node));
	while (--i >= 0)
	{
		temp = init_num(num_list[i]);
		insert_front(node_list, temp);
	}
	return (node_list);
}

/*
@brief verify the prosition of the node and rotate the corret way
 */
void	select_rotate(int num, t_pswap push)
{
	int		count;
	int		i;

	i = -1;
	count = count_moves(num, push.stacka);
	if (count > 0)
	{
		while (++i < count)
			ra(&push);
	}
	else
	{
		count = count * (-1);
		while (++i < count)
			rra(&push);
	}
}
