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
	t_pswap	program;
	if (argc > 2)
	{

		program = start_program(argc, argv);

		// five_args(program);
		radix_sort(program);
		is_sorted(program.stacka);
		free_pswap(&program);
	}
	else
	{
		write(2, "Input Error\n", 6);
		exit(2);
	}
}
