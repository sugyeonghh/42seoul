/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:32:45 by shong             #+#    #+#             */
/*   Updated: 2021/07/03 05:32:46 by shong            ###   ########.fr       */
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

// pivot 
void			init_idx(t_node *stack);
t_node			*find_pivot(t_node *stack);

// sort
void			sort(t_node *a, t_node *b);
void			quick_sort1(t_node *a);
void			quick_sort2(t_node *a, t_node *b);

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
