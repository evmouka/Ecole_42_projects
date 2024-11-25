/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:52:55 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/04 17:55:48 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *fractol)
{
	fractol->escape_radius = ESCAPE_DIAMETER;
	fractol->iter_value = MAX_ITER;
	fractol->inner_colour = MAGENTA_BURST;
	fractol->outer_colour = WHITE;
	fractol->undefined_colour = BLACK;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_hook, fractol);
	mlx_hook(fractol->mlx_window, 4, 1L << 2, mouse_hook, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify,
		StructureNotifyMask, close_window, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		write(STDERR_FILENO, "malloc error!", 13);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		write(1, "malloc error!", 13);
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		write(1, "malloc error!", 13);
	}
	fractol->img.img_pxls_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length, &fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
