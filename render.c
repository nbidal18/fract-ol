/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:09:37 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 17:25:02 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*//TODO
I don't understand what does this offset do,
I guess it's to locate the correct pixel?
How does it use the offset in said case?
Can't we just use x and y to locate it?
8 is the size of a byte
[ ] study this render.c file*/
static void	color_pixel(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->pixel_ptr + offset) = color;
}

static void	mandel_or_julia(t_complex_n *z, t_complex_n *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_n		z;
	t_complex_n		c;
	int				i;
	int				color;

	i = 0;
	z.x = (scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_or_julia(&z, &c, fractal);
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->max_hypotenuse)
		{
			color = scale(i, BLACK, WHITE, fractal->definition);
			color_pixel(x, y, &fractal->image, color);
			return ;
		}
		i++;
	}
	color_pixel(x, y, &fractal->image, WHITE);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->image.image_ptr, 0, 0);
}
