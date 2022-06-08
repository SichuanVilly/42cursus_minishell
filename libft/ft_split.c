/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:13:16 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/05 20:50:15 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_words(char const *s1, char c)
{
	size_t	nbr_wrds;

	nbr_wrds = 0;
	while (*s1)
	{
		while (*s1 != c && *s1)
			s1++;
		nbr_wrds++;
		while (*s1 == c && c != 0)
			s1++;
	}
	return (nbr_wrds);
}

static int	ft_lenchar(char *s1, char c)
{
	int	j;

	j = 0;
	while (*s1 != c && *s1++)
		j++;
	return (j);
}

static char	**ft_aux_split(size_t nbr_wrds, char const *s1, char c, char **wrds)
{
	int	i;
	int	j;

	i = 0;
	while (nbr_wrds--)
	{
		j = ft_lenchar((char *)s1, c);
		wrds[i] = malloc(sizeof(char) * (j + 1));
		if (!wrds[i])
		{
			ft_free(wrds);
			return (NULL);
		}
		j = 0;
		while (*s1 != c && *s1)
			wrds[i][j++] = *s1++;
		wrds[i][j] = '\0';
		while (*s1 == c && *s1)
			s1++;
		i++;
	}
	wrds[i] = NULL;
	return (wrds);
}

char	**ft_split(char const *s1, char c)
{
	size_t	nbr_wrds;
	char	**words;

	if (!s1)
		return (NULL);
	while (*s1 == c && *s1)
		s1++;
	nbr_wrds = ft_nbr_words(s1, c);
	words = malloc(sizeof(char *) * (nbr_wrds + 1));
	if (!words)
		return (NULL);
	words = ft_aux_split(nbr_wrds, s1, c, words);
	return (words);
}
