/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:19 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 14:51:43 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //for debugging (printf)
# include <stdlib.h> //for malloc and free
# include <unistd.h> //for write
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH	800
# define HEIGHT	800

#define BLACK				0x000000 //RGB(0, 0, 0)
#define WHITE				0xFFFFFF //RGB(255, 255, 255)
#define RED					0xFF0000 //RGB(255, 0, 0)
#define GREEN				0x00FF00 //RGB(0, 255, 0)
#define BLUE				0x0000FF //RGB(0, 0, 255)
#define PSYCHEDELIC_PURPLE	0x660066 //deep purple

typedef	struct	s_complex
{
	double	x; //real
	double	y; //imaginary
}				t_complex;

typedef struct	s_image
{
	void	*image_ptr; //pointer to image struct
	char	*pixel_ptr; //pointer to the actual pixels
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_image;

typedef struct	s_fractal
{
	char	*name;
	//mlx
	void	*mlx_connection; //mlx_init()
	void	*mlx_window; //mlx_new_window()
	//image
	t_image	image;
	//hooks
	double	escape_value; //hypoyenuse
	int		iterations_definition; //affects image quality and speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

//string utils
int			ft_strncmp(char *str1, char *str2, int len);
void		putstr_fd(char *str, int fd);
double		atod(char *s);
//init
void		fractal_init(t_fractal *fractal);
//render
void		fractal_render(t_fractal *fractal);
//math utils
double 		map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
//hooks events
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
//clean up
int			close_handler(t_fractal *fractal);

#endif
