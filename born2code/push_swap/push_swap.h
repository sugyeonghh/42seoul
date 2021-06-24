/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:11:48 by shong             #+#    #+#             */
/*   Updated: 2021/06/24 18:16:47 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_node
{
	int				value;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;


t_node	*new_node(int value);
t_node	*last_node(t_node *stack);
void	add_stack(t_node **stack, t_node *new_node);


#endif
