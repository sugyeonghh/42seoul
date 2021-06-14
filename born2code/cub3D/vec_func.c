/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shong <shong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:01:53 by shong             #+#    #+#             */
/*   Updated: 2021/03/17 20:15:19 by shong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"

t_vec	vec_new(double x, double y)
{
	t_vec	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

t_vec	vec_mul(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	return (a);
}

// 연립방정식 계산 코드
t_vec	equation_solver(t_vec *coeff0, t_vec *coeff1, t_vec *constant)
{
	t_vec	result;
	double	det;

	det = coeff1->x * coeff1->y - coeff1->x * coeff0->y;
	result.x = (coeff1->y * constant->x - coeff1->x * constant->y) / det;
	result.y = (coeff0->x * constant->y - coeff0->y * constant->x) / det;
	return (result);
}

t_vec	vec_rotate(t_vec a, double angle)
{
	double	sin_angle;
	double	cos_angle;
	t_vec	result;

	sin_angle = sin(angle);
	cos_angle = cos(angle);
	result.x = cos_angle * a.x - sin_angle * a.y;
	result.y = sin_angle * a.x + cos_angle * a.y;
	return (result);
}

t_vec	vec_rotate_min(t_vec a)
{
	double	sin_unit;
	double	cos_unit;
	t_vec	result;

	if (sin_unit)
		sin_unit = sin_unit;
	else
		sin_unit = sin(M_PI * ANGLE_MIN / 180);
	if (cos_unit)
		cos_unit = cos_unit;
	else
		cos_unit = cos(M_PI * ANGLE_MIN / 180);
	result.x = cos_unit * a.x - sin_unit * a.y;
	result.y = sin_unit * a.x - cos_unit * a.y;
	return (result);
}
