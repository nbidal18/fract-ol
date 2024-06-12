/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:21:45 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 16:47:38 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double og_num, double new_min, double new_max, double old_max)
{
	return (((new_max - new_min) * (og_num - 0) / (old_max - 0)) + new_min);
}

t_complex_n	sum_complex(t_complex_n z1, t_complex_n z2)
{
	t_complex_n	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex_n	square_complex(t_complex_n z)
{
	t_complex_n	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
