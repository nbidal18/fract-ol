/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:21:45 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 17:13:57 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//z usually means we are dealing with complex math
//og_num is the unscaled number, but norminette said its too long

double	scale(double og_num, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * (og_num - 0) / (old_max - 0)) + new_min);
}

//basically a matrix sum
t_complex_n	sum_complex(t_complex_n z1, t_complex_n z2)
{
	t_complex_n	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

//in complex math i^2 equals -1
//(x + yi)^2  -->  (x + yi) * (x + yi)  -->  x^2 + 2xyi + y^2i^2
//-->  x^2 + 2xyi + y^2(-1)  -->  x^2 + 2xyi - y^2
//we get a real part "x" = (x^2 - y^2) and an imaginary part "y" = (2xy)
t_complex_n	square_complex(t_complex_n z)
{
	t_complex_n	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
