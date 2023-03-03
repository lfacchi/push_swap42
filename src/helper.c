/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:11:17 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/02 15:20:22 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int a, int b)
{
	int	tmp;

		tmp = a;
		a = b;
		b = tmp;
}

char	*dec2bin(int d, int digits)
{
	char	*bin;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	len = digit_lenght(digits);
	bin = ft_calloc(len, sizeof(char));
	ft_bzero(bin, digits);
	while (i < len)
	{
		if (d % 2)
			bin[i] = '1';
		else
			bin[i] = '0';
		d /= 2;
		i++;
	}
	j = -1;
	while (++j < (i / 2))
	{
		swap(bin[j], bin[i - j - 1]);
	}
	return (bin);
}

void	print_list(t_node *node, char mode)
{
	while (node)
	{
		if (mode == 'b')
			printf("%s\n", dec2bin(node->num, 5));
		else
			printf("%d\n", node->num);
		node = node->next;
	}
}