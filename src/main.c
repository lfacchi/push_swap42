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
	t_node **node_list;
	// t_node *teste;
	int *list;
	t_node **stackb;
	if (argc > 2)
	{
		node_list = ft_calloc(1, sizeof(t_node*));
		stackb = ft_calloc(1, sizeof(t_node*));
		*stackb = init_num(7);
		insert_front(*stackb, init_num(7));
		printf("\n");

		int i = -1;
		list = ft_calloc(argc - 1, sizeof(int));
		print_list(stackb[0]);
		while(++i < argc - 1)
			list[i] = ft_atoi(argv[i + 1]);
		node_list = create_list(list);
		print_list(*node_list);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}
