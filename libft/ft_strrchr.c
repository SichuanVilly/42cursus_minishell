/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:54:33 by pvillena          #+#    #+#             */
/*   Updated: 2022/01/19 22:54:35 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		flag;
	char	*p;

	flag = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			flag = 1;
			p = (char *)s;
		}
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else if (flag == 1)
		return (p);
	else
		return (NULL);
}
