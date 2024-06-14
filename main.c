/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:58 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/14 16:36:42 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// mlx_loop() keeps the window alive listening for events
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "Julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "Julia", 5))
		{
			fractal.julia_x = atod(argv[2]);
			fractal.julia_y = atod(argv[3]);
		}
		init_fractal(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
