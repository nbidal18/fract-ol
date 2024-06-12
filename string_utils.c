/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:14 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 15:59:08 by nbidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *str1, char *str2, int len)
{
	if (str1 == NULL || str2 == NULL || len <= 0)
		return (0);
	while (*str1 == *str2 && len > 0 && *str1 != '\0')
	{
		str1++;
		str2++;
		len--;
	}
	return (*str1 - *str2);
}

void	putstr_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return ;
	if (*str != '\0')
	{
		write(fd, str, 1);
		putstr_fd(str + 1, fd);
	}
}

double	atod(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	power;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	power = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s)
	{
		power /= 10;
		fractional_part = fractional_part + (*s++ - 48) * power;
	}
	return ((integer_part + fractional_part) * sign);
}
