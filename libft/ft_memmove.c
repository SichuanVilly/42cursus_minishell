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

static int	ft_stroverlap(char *dest, const char *src, size_t len)
{
	while (len--)
	{
		if (dest == src)
			return (1);
		src++;
	}
	return (0);
}

static char	*ft_memcpyrev(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i++ < len)
	{
		dest++;
		src++;
	}
	dest--;
	src--;
	while (len--)
		*dest-- = *src--;
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (NULL == dst && NULL == src)
		return (dst);
	if (ft_stroverlap(dst, src, len) == 1)
		ft_memcpyrev(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
