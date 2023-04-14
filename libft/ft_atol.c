/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lucdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:16:26 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/04/13 04:22:33 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	num;
	long int	sign;

	i = 0;
	sign = 0;
	if (nptr == NULL)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	num = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = (num * 10) + nptr[i] - 48;
		i++;
	}
	if (sign == 1)
		num = -num;
	return (num);
}
