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
	if (argc > 2)
	{
		node_list = ft_calloc(argc - 1, sizeof(t_node*));
		int i = 0;
		int *list;
		list = ft_calloc(argc - 1, sizeof(int));
		while (argv[i])
		{
			list[i] = ft_atoi(argv[i + 1]);
			node_list[i] = init_num(list[i]);
			i++;
		}
		i = -1;
		while (++i < argc - 1)
			insert_front(node_list[i],node_list[i + 1]);
		// teste = init_num(256);
		// insert_back(node_list[0], teste);
		print_list(*node_list);
		// rotate_stack(*node_list);
		// print_list(*node_list);
		// rotate_stack(*node_list);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}
