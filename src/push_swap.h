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
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define swap( a, b )   do{ int tmp = a; a = b; b = tmp; }while(0)

typedef struct t_node
{
	int num;
	struct t_node *next;
} t_node;

typedef struct push_swap
{
	struct t_node **stacka;
	struct t_node **stackb;
} t_pswap;

const char * dec2bin(int d, int digits );

// t_clist create_list(int *list, int size);
t_node **create_list(int *num_list, int n);
t_node *init_num(int v_node);
void insert_front(t_node *head, t_node *node);
void print_list(t_node *node, char mode);
void move_r(t_node *node);
void move_rr(t_node *node);
int top_value(t_node node);
void move_s(t_node *node);
void move_p(t_node *node1, t_node *node2);
int listlen(t_node **node_list);
int pop(t_node **node_list);
t_pswap start_program(int argc, char **argv);
void is_sorted(t_node **stack);
int search_num(t_node *stack, int num);
int get_mid_position(t_node **stack);
void map_rotate(t_pswap push_swap);
int count_moves(t_node *stack, int num);

void pa(t_pswap push_swap);
void pb(t_pswap push_swap);
void rra(t_pswap *push_swap);
void rrb(t_pswap *push_swap);
void rb(t_pswap *push_swap);
void ra(t_pswap *push_swap);
void sa(t_pswap push_swap);
void sb(t_pswap push_swap);
void multi_rra(t_pswap push_swap, int n);
void multi_rrb(t_pswap push_swap, int n);
void multi_ra(t_pswap push_swap, int n);
void multi_rb(t_pswap push_swap, int n);

// 5 argumentos
void five_args(t_pswap push_swap);
int get_low(t_node **stacka);
int get_high(t_node **stacka);

// 3 argumentos
int three_args_factor(t_node *node);
void select_moves_3(t_pswap push_swap);
void sort_3(t_pswap push_swap);

void select_rotate(t_node *node, t_node **stack);
void map_rotate(t_pswap push_swap);

//radix 
void	radix_sort(t_pswap push);
int digit_lenght(int i);


void free_pswap(t_pswap *pswap);

void free_list(t_node *head);