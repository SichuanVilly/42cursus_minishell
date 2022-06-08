/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:05:29 by pvillena          #+#    #+#             */
/*   Updated: 2022/01/24 19:21:45 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

static size_t	ft_lenchar(int n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = -1;
	else if (n == 0)
		return (ft_strdup("0"));
	size = ft_lenchar(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	while (n)
	{
		str[size--] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
