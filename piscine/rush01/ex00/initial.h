/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjikim <eunjikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:47:47 by eunjikim          #+#    #+#             */
/*   Updated: 2020/11/29 05:51:37 by eunjikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIAL_H
# define INITIAL_H

void	ft_initial(char **argv, char *line_1, char *line_2);
int		ft_check_sight(char *line_1, char *line_2);
int		ft_valid_number(char *line);
void	ft_inital_map(char full_map[4][4][4], char result_map[4][4]);

#endif
