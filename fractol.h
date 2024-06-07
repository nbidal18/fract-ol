/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:19 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/07 15:11:18 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //for debugging (printf)
# include <stdlib.h> //for malloc and free
# include <unistd.h> //for write
# include <math.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

//string utils
int		ft_strncmp(char *str1, char *str2, int len);
void	putstr_fd(char *str, int fd);

#endif
