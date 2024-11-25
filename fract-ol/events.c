/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:13 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/04 17:53:14 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
		close_window(fractol);
	else if (keycode == 61)
		fractol->iter_value += 10;
	else if (keycode == 45)
		fractol->iter_value -= 10;
	else if (keycode == 65361)
		fractol->offset_x += 0.1 * fractol->zoom;
	else if (keycode == 65363)
		fractol->offset_x -= 0.1 * fractol->zoom;
	else if (keycode == 65364)
		fractol->offset_y -= 0.1 * fractol->zoom;
	else if (keycode == 65362)
		fractol->offset_y += 0.1 * fractol->zoom;
	fractol_render(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void) x;
	(void) y;
	if (button == 4)
		fractol->zoom *= 1.1;
	else if (button == 5)
		fractol->zoom /= 1.1;
	else if (button == 6)
		fractol->offset_x -= 0.1 * fractol->zoom;
	else if (button == 7)
		fractol->offset_x += 0.1 * fractol->zoom;
	fractol_render(fractol);
	return (0);
}
