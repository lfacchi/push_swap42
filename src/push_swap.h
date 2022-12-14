/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s <lukas.facchi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:18:22 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/11/29 16:18:22 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct t_node
{
	int				num;
	struct t_node	*next;
}	t_node;


// t_clist create_list(int *list, int size);
t_node	*init_num(int v_node);
void insert_front(t_node *head, t_node *node);
void insert_back(t_node *tail, t_node *node);
void print_list(t_node *node);
void rotate_stack(t_node *node);