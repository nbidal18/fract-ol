/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:43:58 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/07 15:11:52 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) || argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		//start the program...
		printf("good\n");
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}	
}
