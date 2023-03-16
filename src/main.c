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

int	main(int argc, char **argv)
{
	t_pswap	program;

	if (argc >= 2)
	{
		program = start_program(argc, argv);
        if (is_sorted(program.stacka) == 0)
        {
            if (argc == 3)
                ra(&program);
            else if (argc == 4)
                three_args(program);
            else if (argc == 6)
                five_args(program);
            else
                radix_sort(program);
        }
        free_pswap(&program);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}
