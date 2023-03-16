/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:20:27 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/05 20:11:28 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
@brief Transform the value of the elements of an array 
in this ranked values on the array 
 */
void	transform_array(int *arr, int len)
{
	int	i;
	int	j;
	int	*sorted;

	sorted = bubble_sort(arr, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] == sorted[j])
			{
				arr[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
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
		if (arr[i][j] == '-')
			j++;
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

int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	*sorted;
	int	temp;

	i = -1;
	sorted = (int *) malloc(size * sizeof(int));
	while (++i < size)
		sorted[i] = arr[i];
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}
	return (sorted);
}
