/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:32:45 by shong             #+#    #+#             */
/*   Updated: 2021/07/04 05:53:43 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_node
{
	int				value;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

// stack
t_node			*argv_to_stack(int argc, char *argv[]);
void			add_stack(t_node **stack, int value);
int				stack_size(t_node *stack);
t_node			*last_node(t_node *stack);
int				min_node_pos(t_node *stack);

// pivot 
void			init_idx(t_node *stack);
t_node			*find_pivot(t_node *stack);

// sorting/sort
int				is_sorted(t_node *a);
void			sort(t_node **a, t_node **b);

// sorting/sort_under_five
void			sort_case_3(t_node **a);
void			sort_case_4(t_node **a, t_node **b);
void			sort_case_5(t_node **a, t_node **b);

// sorting/quick_sort
void			partition(t_node **a, t_node **b, t_node *pivot);
void			quick_sort(t_node **a, t_node **b);

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

// push_swap
void			view_stack(t_node *stack);

#endif
