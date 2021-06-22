/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 02:26:13 by shong             #+#    #+#             */
/*   Updated: 2021/06/22 17:45:28 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>


typedef struct	s_node
{
	int				value;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	char	name;
	int		size;
	t_node	*first;
	t_node	*last;
}				t_stack;

void	swap_stack(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);

void	push_stack(t_stack *stack1, t_stack *stack2);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	rotate_stack(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate_stack(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

t_node	*find_pivot(t_stack *stack);


#endif
