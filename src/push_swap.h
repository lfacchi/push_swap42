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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "../42_libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct t_node
{
	int				num;
	struct t_node	*next;
}	t_node;

typedef struct push_swap
{
	struct t_node	**stacka;
	struct t_node	**stackb;
}	t_pswap;

char	*dec2bin(int d, int digits);

//validation.c
void	check_num(char **arr);
void	transform_array(int *arr);
void	check_duplicate(int *arr);

//push_swap.c
t_pswap	start_program(int argc, char **argv);
t_node	**create_list(int *num_list);
int		pop(t_node **node_list);
int		get_mid_position(t_node **stack);
void	select_rotate(int num, t_pswap push);

//moves.c
void	move_r(t_node *node);
void	move_rr(t_node *node);
void	move_s(t_node *node);
void	pa(t_pswap push_swap);
void	pb(t_pswap push_swap);

//moves2.c
void	rra(t_pswap *push_swap);
void	rrb(t_pswap *push_swap);
void	rb(t_pswap *push_swap);
void	ra(t_pswap *push_swap);
void	sa(t_pswap push_swap);
void	sb(t_pswap push_swap);
void	multi_rra(t_pswap push_swap, int n);
void	multi_rrb(t_pswap push_swap, int n);
void	multi_ra(t_pswap push_swap, int n);
void	multi_rb(t_pswap push_swap, int n);

//utils.c
t_node	*init_num(int v_node);
void	insert_front(t_node **head, t_node *node);
int		listlen(t_node **node_list);
int		top_value(t_node node);

//helper
void	print_list(t_node *node, char mode);
int		is_sorted(t_node **stack);
void	map_rotate(t_pswap push_swap);
t_node	*search_num(int num, t_node **stack);
int		count_moves(int num, t_node **stack);
int		top_value(t_node node);

//five_args.c
void	five_args(t_pswap push_swap);
int		get_low(t_node **stacka);
int		get_high(t_node **stacka);

//three_args.c
int		three_args_factor(t_node *node);
void	select_moves_3(t_pswap push_swap);
void	three_args(t_pswap push_swap);

//radix
void	radix_sort(t_pswap push);
int		digit_lenght(int i);

void	free_pswap(t_pswap *pswap);
void	free_list(t_node *head);
void	final_five_args(t_pswap push_swap);

#endif