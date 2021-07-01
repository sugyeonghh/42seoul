/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:32:45 by shong             #+#    #+#             */
/*   Updated: 2021/07/02 03:36:04 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_node
{
	int				value;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

// stack
void			init_idx(t_node *stack);
t_node			*new_node(int value);
t_node			*last_node(t_node *stack);
void			add_stack(t_node **stack, t_node *new_node);
int				stack_size(t_node *stack);

// sort
t_node			*find_pivot(t_node *stack);

// atcions/swap
void			swap(t_node **stack);
void			sa(t_node **stack);
void			sb(t_node **stack);
void			ss(t_node **a, t_node **b);

// atcionts/push
void			push(t_node **a, t_node **b);
void			push2(t_node **a, t_node **b);
void			push3(t_node **a, t_node **b);
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);

// push_swap
void			view_stack(t_node *stack);
#endif
