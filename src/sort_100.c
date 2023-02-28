/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:12:04 by lucdos-s          #+#    #+#             */
/*   Updated: 2023/02/27 21:51:56 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void map_rotate(t_pswap push_swap)
// {
// 	t_node *numa;
// 	t_node *numb;
// 	int sa;
// 	int s;
// 	numa = *(push_swap.stacka);
// 	numb = *(push_swap.stackb);
// 	int num = count_moves(numa, numa->num);

// 	// sa = search_num(numa, numa->next + 1);
// 	// sb = search_num(numb, numa->next + 1);
// 	printf("N° de moves: |%d|\n", num);
// 	while(numa->next)
// 	{
// 		if (num < abs(count_moves(numa->num, numa->num)))
// 		{
// 			num  = count_moves(numa->num, numa->num);
// 			sa = search_num(numa,numa->next);
// 			s = numa->num;
// 		}
// 		numa = numa->next;
// 	}
// 	printf("Numero mais proximo: |%d|\n", s);
// 	printf("Posição: |%d|\n", sa);
// 	if(num > 0)
// 		multi_ra(push_swap, num);
// 	else
// 		multi_rra(push_swap, num);
// 	pa(push_swap);
// }

// int search_num(t_node *stack, int num)
// {
// 	t_node *temp;
// 	int i;
// 	int check = 0;

// 	temp = stack;
// 	i = 0;
// 	while (temp)
// 	{
// 		if (i == num)
// 		{
// 			check = 1;
// 			break;
// 		}
// 		else
// 		{
// 			i++;
// 			temp = temp->next;
// 		}
// 	}
// 	if (check == 0)
// 		return (i);
// 	else
// 		return(-1);
// }

// // conta a quantidade de movimentos ncessarios para deixar um numero no topo da
// // stack e o anterior
// int count_moves(t_node *stack, int num)
// {
// 	int pos;
// 	int moves;
// 	int prev;

// 	if (num == 1)
// 		prev = 10;
// 	else
// 		prev = num - 1;
// 	pos = search_num(stack,prev);
// 	if (pos == -1)
// 		return;
// 	else
// 		moves = pos - (get_mid_position(&stack) * -1);
// 	return (moves);
// }

// t_node* find_closest_antecessor(t_node* head) {
//     t_node* closest_node = NULL;
//     int closest_distance = listlen(&head);
//     int current_distance = 0;
//     t_node* current_node = head;
//     t_node* previous_node = NULL;

//     while (current_node != NULL) {
//         if (previous_node != NULL && current_node->num == previous_node->num - 1) {
//             current_distance++;
//             if (current_distance < closest_distance) {
//                 closest_node = previous_node;
//                 closest_distance = current_distance;
//             }
//         } else {
//             current_distance = 0;
//         }
//         previous_node = current_node;
//         current_node = current_node->next;
//     }

//     return closest_node;
// }

void radix_sort(t_pswap push)
{
	t_node *a = *(push.stacka);
	int l;
	int s;
	int d;

	l = 0;
	d = digit_lenght(listlen(&a)); 
	while (l < d)
	{
		s = listlen(&*(push.stacka));
		// printf("|Len A -> %d <- |\n", listlen(&*(push.stacka)));
		while (s > 0)
		{
			
			// printf("|A -> %d <- |\n", a->num);
			if ((push.stacka[0]->num >> l) & 1)
			{
				ra(&push);
			}
			else
				pa(push);
			s--;
		}
		while (listlen(&*(push.stackb)) > 0)
		{
			pb(push);
		}
		
		l++;
	}
}

int digit_lenght(int i)
{
	int r = 0;
	while (i >> r != 0)
	{
		r++;
	}
	return r;
}