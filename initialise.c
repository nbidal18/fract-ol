/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:35:03 by nbidal            #+#    #+#             */
/*   Updated: 2024/07/08 09:41:53 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress,
		KeyPressMask, keyboard_handler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_handler_press, fractal);
	mlx_hook(fractal->mlx_window, ButtonRelease,
		ButtonReleaseMask, mouse_handler_release, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, quit_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify,
		PointerMotionMask, julia_mouse_handler, fractal);
}

static void	init_data(t_fractal *fractal)
{
	fractal->max_hypotenuse = 4;
	fractal->definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1;
	fractal->julia_dynamic = 0;
}

static void	malloc_error(void)
{
	perror("Malloc related ERROR.");
	exit(EXIT_FAILURE);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH,
			HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.pixel_ptr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bits_per_pixel,
			&fractal->image.line_len, &fractal->image.endian);
	init_events(fractal);
	init_data(fractal);
}
