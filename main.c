/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:58 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 15:51:26 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atod(argv[2]);
			fractal.julia_y = atod(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
