/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:06 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/04 17:53:07 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	rescale(double old_value, double old_max,
	double new_min, double new_max)
{
	return ((old_value - 0) / (old_max - 0) * (new_max - new_min) + new_min);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.re = z.re * z.re - z.im * z.im;
	res.im = 2 * z.re * z.im;
	return (res);
}
