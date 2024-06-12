/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:14 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/12 17:34:48 by nbidal           ###   ########.fr       */
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

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return ;
	if (*str != '\0')
	{
		write(fd, str, 1);
		ft_putstr_fd(str + 1, fd);
	}
}

/*STEPS
1. skip spaces and various non printable characters
2. if "-" is found, then set sign to negative
3. for the integer part, as long as it doesn't reach a "." and the value exists,
turn it into a double and add it to the integer
4. once it goes past the "." we are dealing with the fractional,
with the index becoming 0.1, 0.01, 0.001, ecc...
makes the numbers add up in the proper way*/
double	atod(char *s)
{
	long	integer;
	double	fractional;
	double	index;
	int		sign;

	integer = 0;
	fractional = 0;
	sign = +1;
	index = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integer = (integer * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s)
	{
		index /= 10;
		fractional = fractional + (*s++ - 48) * index;
	}
	return ((integer + fractional) * sign);
}
