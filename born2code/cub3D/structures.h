/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:44:19 by shong             #+#    #+#             */
/*   Updated: 2021/03/13 21:44:12 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdio.h>
# include <math.h>

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;


typedef struct	s_img
{
	void			*ptr;
	void			*addr;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	unsigned int	endian;
}				t_img;

typedef struct	s_screen
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_pixel		**pixel;
	t_vec		origin;
	t_vec		dir;
	t_vec		plane;
	double		sin_unit;
	double		cos_unit;
	double		distance;
	t_ray		*ray;
	int			width;
	int			height;
}				t_screen;

#endif
