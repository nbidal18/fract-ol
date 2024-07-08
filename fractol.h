/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:19 by nbidal            #+#    #+#             */
/*   Updated: 2024/07/08 09:41:52 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Use either \"./fractol Mandelbrot\"\\\
 or \"./fractol Julia value1 value2\"\n"

# define WIDTH	1000
# define HEIGHT	1000

# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define WHITE	0xFFFFFF
# define BLACK	0x000000

typedef struct s_complex_n
{
	double	x;
	double	y;
}				t_complex_n;

typedef struct s_image
{
	void	*image_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	double	max_hypotenuse;
	int		definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	int		julia_dynamic;
	double	julia_x;
	double	julia_y;
}				t_fractal;

int				ft_strncmp(char *str1, char *str2, int len);
void			ft_putstr_fd(char *str, int fd);
double			atod(char *s);
void			init_fractal(t_fractal *fractal);
void			render_fractal(t_fractal *fractal);
double			scale(double og_num, double new_min,
					double new_max, double old_max);
t_complex_n		sum_complex(t_complex_n z1, t_complex_n z2);
t_complex_n		square_complex(t_complex_n z);
int				keyboard_handler(int keysym, t_fractal *fractal);
int				mouse_handler_press(int button, int x,
					int y, t_fractal *fractal);
int				mouse_handler_release(int button, int x,
					int y, t_fractal *fractal);
int				julia_mouse_handler(int x, int y, t_fractal *fractal);
int				quit_handler(t_fractal *fractal);

#endif
