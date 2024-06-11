/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:35:03 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/11 15:20:53 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Malloc related ERROR.");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4; //2^2, my hypotenuse
	fractal->iterations_definition = 42;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal); //TODO key_handler()
	//mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractal); //TODO mouse_handler()
	//mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal); //TODO close_handler()
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.pixel_ptr = mlx_get_data_addr(fractal->image.image_ptr, &fractal->image.bits_per_pixel, &fractal->image.line_len, &fractal->image.endian);
	events_init(fractal);//TODO
	data_init(fractal);
}
