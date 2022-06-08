/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:24:09 by pvillena          #+#    #+#             */
/*   Updated: 2022/01/24 15:49:30 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*p;

	p = malloc(ft_strlen(s1) + sizeof(char));
	if (p == NULL)
		return (NULL);
	dst = p;
	while (*s1)
		*dst++ = *s1++;
	*dst = 0;
	return (p);
}
