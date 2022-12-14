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
	t_node *head;
	t_node *node1;
	t_node *node2;
	t_node *node3;
	t_node *node4;
	
	int n1 = 10;
	int n2 = 20;
	int n3 = 30;
	int n4 = 40;

	if (argc > 2)
	{
		printf("START\n");
		
		head = init_num(256);
		node1 = init_num(n1);
		node2 = init_num(n2);
		node3 = init_num(n3);
		node4 = init_num(n4);

		printf("\nASSIGN NODES\n\n");

		printf("%d\n", head->num);
		printf("%d\n", node1->num);
		printf("%d\n", node2->num);
		printf("%d\n", node3->num);
		printf("%d\n", node4->num);

		printf("\nLINKIN NODES\n");
		insert_node(head, node4);
		printf("%d\n", head->next->num);

	}
	else
	{
		write(2, "Error\n", 6);
		exit(2);
	}
}