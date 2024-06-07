/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbidal <nbidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:44:14 by nbidal            #+#    #+#             */
/*   Updated: 2024/06/07 15:14:25 by nbidal           ###   ########.fr       */
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
