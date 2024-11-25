/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:25 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/08 14:41:46 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>

# define WIDTH	700
# define HEIGHT	700
# define MAX_ITER	100
# define ESCAPE_DIAMETER 4

# define BLACK			0x000000
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define WHITE			0xFFFFFF
# define MAGENTA_BURST	0xFF00FF
# define CYAN_BURST		0x00FFFF
# define YELLOW_BURST	0xFFFF00
# define ERROR_MESSAGE1	"Usage: <./fractol mandelbrot>\n"
# define ERROR_MESSAGE2	"or <./fractol julia value_1 value_2>\n"

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pxls_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	char	*name;
	double	julia_re;
	double	julia_im;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		iter_value;
	double	escape_radius;
	int		inner_colour;
	int		outer_colour;
	int		undefined_colour;
}				t_fractol;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_connection;
	void	*mlx_window;
	int		colour;
}				t_mlx_data;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atofl(const char *str);

void		fractol_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);

double		rescale(double old_value, double old_max,
				double new_min, double new_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex z);

int			key_hook(int keycode, t_fractol *fractol);
int			close_window(t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);

int			grey_scale(int iteration, t_fractol *fractol);
int			vibrant_colours(int iteration);
int			encode_rgb(int t, int r, int g, int b);
int			colour(int iteration, t_fractol *fractol);
int			grey_scale2(int iteration, t_fractol *fractol);
int			custom_color(int iteration, int max_iterations);

int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

#endif