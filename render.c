/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:09:37 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 14:25:01 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bits_per_pixel / 8)); //8 is the size of a bit
	*(unsigned int *)(image->pixel_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	i = 0;
	//first iteration
	/*FIX to remove, but I didn't understand why (1:56:17)
	z.x = 0;
	z.y = 0;
	*/
	//pixel coordinate x && y scaled
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x; //WIDTH is 800, but shouldn't it be 799? //FIX
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y; //same here
	//how many times do we iterate z^2 + c
	while(i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		//the value escaped? if hypotenuse > 2 it has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->image, color);
			return;
		}
		i++;
	}
	//if it comes here the point belongs to mandelbrot
	my_pixel_put(x, y, &fractal->image, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}	
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.image_ptr, 0, 0);
}
