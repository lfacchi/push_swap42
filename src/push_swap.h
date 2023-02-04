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

typedef struct push_swap
{
	struct t_node **stacka;
	struct t_node **stackb;
} p_swap;

// t_clist create_list(int *list, int size);
t_node	**create_list(int *num_list, int n);
t_node	*init_num(int v_node);
void	insert_front(t_node *head, t_node *node);
void	print_list(t_node *node);
void	move_r(t_node *node);
void	move_rr(t_node *node);
int		top_value(t_node node);
void	move_s(t_node *node);
void	move_p(t_node *node1, t_node *node2);
int		listlen(t_node **node_list);
int		pop(t_node **node_list);
p_swap	start_program(int argc, char **argv);

void	pa(p_swap push_swap);
void	pb(p_swap push_swap);
void	rra(p_swap *push_swap);
void	rrb(p_swap *push_swap);
void	rb(p_swap *push_swap);
void	ra(p_swap *push_swap);
void	sa(p_swap push_swap);
void	sb(p_swap push_swap);

//3 argumentos
int		three_args_factor(t_node *node);
void	select_moves_3(p_swap push_swap, int factor);
void	sort_3(p_swap push_swap);

//5 argumentos
void five_args(p_swap push_swap);
int	get_low(t_node **stacka);
int get_high(t_node **stacka);