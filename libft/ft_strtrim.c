/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:03:02 by pvillena          #+#    #+#             */
/*   Updated: 2022/01/21 16:18:09 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_begining(char const *s1, char const *set)
{
	int			flag;
	char const	*p;

	flag = 0;
	p = set;
	while (*s1)
	{
		set = p;
		while (*set)
		{
			if (*set == *s1)
				flag = 1;
			set++;
		}
		if (flag-- == 1)
			s1++;
		else
			return ((char *)s1);
	}
	return ((char *)s1);
}

static int	trim_end(char const *s1_end, char const *set, size_t len)
{
	int			flag;
	char const	*p;
	int			last_c;

	flag = 0;
	p = set;
	last_c = 0;
	while (len--)
	{
		set = p;
		while (*set)
		{
			if (*set == *s1_end)
				flag = 1;
			set++;
		}
		if (flag-- == 1)
		{
			s1_end--;
			last_c++;
		}
		else
			return (last_c);
	}
	return (last_c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*p;
	int			last_c;
	char const	*s1_end;

	if (!s1 || !set)
		return (NULL);
	s1 = trim_begining(s1, set);
	s1_end = s1;
	while (*s1_end)
		s1_end++;
	s1_end--;
	last_c = trim_end(s1_end, set, ft_strlen(s1));
	p = ft_calloc(ft_strlen(s1) - last_c + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen(s1) - last_c + 1);
	return (p);
}
