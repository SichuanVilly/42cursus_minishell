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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;

	length = ft_strlen(src) + ft_strlen(dst);
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	dstsize -= ft_strlen(dst);
	while (*dst)
		dst++;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	if (length != 0)
		*dst = '\0';
	return (length);
}
