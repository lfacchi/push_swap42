/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:05:23 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/12/13 22:05:23 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node	**stacka;
	t_node	**stackb;
	int		*list;
	int		*listb;
	int		i; 
	
	if (argc > 2)
	{
		listb = ft_calloc(1, sizeof(int));
		list = ft_calloc(argc, sizeof(int));
		i = -1;
		*listb = 777;
		stackb = create_list(listb, 1);
		while(++i < argc - 1)
			list[i] = ft_atoi(argv[i + 1]);
		listlen(list);
		stacka = create_list(list, argc - 1);
		move_p(stacka, *stackb);
		move_p(stacka, *stackb);
		move_p(stacka, *stackb);
		move_p(stackb, *stacka);
		print_list(*stackb);
		printf("\n");
		print_list(*stacka);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}
