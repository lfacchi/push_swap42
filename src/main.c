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
	p_swap	program;

	if (argc > 2)
	{
		printf("\n");
		program = start_program(argc, argv);
		pa(program);
		pa(program);
		// pb(program);
		// pb(program);
		rra(&program);
		ra(&program);
		sa(program);
		sa(program);
		sb(program);
		sb(program);
		print_list(*(program.stacka));
		printf("\n");
		print_list(*(program.stackb));
	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}
