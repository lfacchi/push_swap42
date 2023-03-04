/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:12:04 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/03/04 00:14:56 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_pswap push)
{
	t_node	*a;
	int		l;
	int		s;
	int		d;

	a = *(push.stacka);
	l = 0;
	d = digit_lenght(listlen(&a));
	while (l < d)
	{
		s = listlen(&*(push.stacka));
		while (s > 0)
		{
			if ((push.stacka[0]->num >> l) & 1)
			{
				ra(&push);
			}
			else
				pa(push);
			s--;
		}
		while (listlen(&*(push.stackb)) > 0)
			pb(push);
		l++;
	}
}

int	digit_lenght(int i)
{
	int	r;

	r = 0;
	while (i >> r != 0)
		r++;
	return (r);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_pswap(t_pswap *pswap)
{
	free_list(*(pswap)->stacka);
	free_list(*(pswap)->stackb);
	free(pswap->stacka);
	free(pswap->stackb);
}
