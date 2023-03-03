/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:20:27 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/02 20:15:56 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
@brief Encontra o valor mínimo e o valor máximo no array
Subtrai o valor mínimo de cada elemento do array
Incrementa cada elemento do array em 1
 */
void	transform_array(int *arr)
{
	int	i = 0;
	int	min;

	min = INT_MAX;
	while (arr[i])
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	i = 0;
	while (arr[i])
	{
		arr[i] = arr[i] - min + 1;
		i++;
	}
}

void	check_duplicate(int *arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = i + 1;
		while (arr[i] && arr[j])
		{
			if (arr[i] == arr[j])
			{
				write(2, "Error\n", 6);
				free(arr);
				exit(2);
			}
			j++;
		}
	}
}


void	check_num(char **arr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_isdigit(arr[i][j]))
			{
				write(2, "Error\n", 10);
				exit(2);
			}
			j++;
		}
		i++;
	}
}
