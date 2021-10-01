/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:32:45 by shong             #+#    #+#             */
/*   Updated: 2021/09/10 22:06:53 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_pivot
{
	t_node	*small;
	t_node	*big;
}				t_pivot;

// preprocessing
t_node			*pre(int argc, char *argv[]);
int				ascii_to_integer(char *s);
void			allnum_check(char *s);
void			duplicate_check(t_node *stack);

// stack
void			add_stack(t_node **stack, int value);
int				stack_size(t_node *stack);
t_node			*last_node(t_node *stack);
int				find_mid_pos(t_node *stack, int size);
int				find_min_pos(t_node *stack, int size);

// pivot 
void			init_idx(t_node *stack);
void			set_idx(t_node *stack, int size);
void			init_pivot(t_pivot *pivot);
t_pivot			find_pivot(t_node *stack, int size);

// sorting/sort
int				is_sorted(t_node *a);
void			sort(t_node **a, t_node **b, int size);

// sorting/sort_under_four
void			sort_case_3(t_node **a);
void			sort_case_4(t_node **a, t_node **b);

// sorting/sort_over_four
void			sort_over_4(t_node **a, t_node **b);
void			a_to_b(t_node **a, t_node **b, t_pivot pivot);
void			b_to_a(t_node **a, t_node **b, t_pivot pivot);
void			b_to_a_pa(t_node **a, t_node **b, int *ra_cnt, int *pa_cnt);

// actions/swap
void			swap(t_node **stack);
void			sa(t_node **stack);
void			sb(t_node **stack);
void			ss(t_node **a, t_node **b);

// actionts/push
void			push(t_node **a, t_node **b);
void			push2(t_node **a, t_node **b);
void			push3(t_node **a, t_node **b);
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);

// actions/rotate
void			rotate(t_node **stack);
void			ra(t_node **stack);
void			rb(t_node **stack);
void			rr(t_node **a, t_node **b);

// actions/reverse_rotate
void			reverse_rotate(t_node **stack);
void			rra(t_node **stack);
void			rrb(t_node **stack);
void			rrr(t_node **a, t_node **b);

// free_stack
void			free_stack(t_node **stack);

#endif
