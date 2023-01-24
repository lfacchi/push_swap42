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
	p_swap	program;

	if (argc > 2)
	{
		program = start_program(argc, argv);
		// rra(&program);
		// sa(program);
		sort_3(program);
		print_list(*(program.stacka));
		printf("\n%d\n", tree_args_factor(*(program.stacka)));
		// printf("\n");
		// print_list(*(program.stackb));
	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}
