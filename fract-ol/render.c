/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:19 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/25 14:05:13 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int colour)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->img_pxls_ptr + offset) = colour;
}

static void	julia_variation(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "julia", 5) == 0)
	{
		c->re = fractol->julia_re;
		c->im = fractol->julia_im;
	}
	else
	{
		c->re = z->re;
		c->im = z->im;
	}
}

static void	handle_pixel(t_fractol *fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			iteration;
	int			colour;

	iteration = 0;
	z.re = (rescale(x, WIDTH, -2.0, 2.0) * fractol->zoom) + fractol->offset_x;
	z.im = (rescale(y, HEIGHT, 2.0, -2.0) * fractol->zoom) + fractol->offset_y;
	julia_variation(&z, &c, fractol);
	while (iteration < fractol->iter_value)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.re * z.re + z.im * z.im) > fractol->escape_radius)
		{
			colour = rescale(iteration, fractol->iter_value,
					fractol->undefined_colour, fractol->outer_colour);
			my_mlx_pixel_put(&fractol->img, x, y, colour);
			return ;
		}
		++iteration;
	}
	colour = fractol->inner_colour;
	my_mlx_pixel_put(&fractol->img, x, y, colour);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractol, x, y);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}
