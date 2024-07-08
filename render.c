/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:09:37 by nbidal            #+#    #+#             */
/*   Updated: 2024/07/08 09:42:03 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* EXPLANATION
- First of all, we do all this because the offset is calculate in bytes
	and images are stored in arrays, so the offset is not to imagine on
	a x and y graph, but rather on an array to find
	the correct slot where the pixel is.
1. y is the vertical coordinate of the pixel.
	- image->line_len represents the length of a single row of pixels in bytes.
	- (y * image->line_len) = the row in which the pixel is located.
2. x is the horizontal coordinate of the pixel.
	- (image->bits_per_pixel / 8) converts the bit depth per pixel into bytes.
		- bit depth per pixel: 8-bit: Each pixel can represent one of 256 colors.
	- (x * (image->bits_per_pixel / 8)) = the column in the row for the pixel.
3. ((y * image->line_len) + (x * (image->bits_per_pixel / 8))) = offset in bytes.
4. *(unsigned int *)(image->pixel_ptr + offset) = color
	- casted to unsigned int to not have issues with negative values
	- from the starting position of pixel_ptr we add the offset
		to find the pixel and store the color.*/
static void	color_pixel(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_len) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->pixel_ptr + offset) = color;
}

static void	mandel_or_julia(t_complex_n *z, t_complex_n *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "Julia", 5))
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
	unsigned int	color;

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
