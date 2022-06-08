/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argvsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:27:12 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/09 18:47:03 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_countspecial(char const *str, int i)
{
	if (str[i] == '\'' )
	{
		i++;
		while (str[i] != '\'' && str[i] != '\0')
			i++;
		i++;
	}
	else if (str[i] == '\"' )
	{
		i++;
		while (str[i] != '\"' && str[i] != '\0')
			i++;
		i++;
	}
	return (i);
}

static int	ft_count(char const *str)
{
	int	cpal;
	int	i;

	cpal = 1;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] != ' ' && !ft_strchr(SPSIGN, str[i]))
		{
			if (str[i] == '\"' || str[i] == '\'')
				i = ft_countspecial(str, i);
			else
				i++;
		}
		if (!str[i])
			break ;
		ft_countpalspchar(str, &cpal, &i);
		while (str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
			cpal++;
	}
	return (cpal);
}

static int	ft_countlet(const char *str, int i)
{
	int	com;

	com = 0;
	if (ft_strchr(SPSIGN, str[i]) && str[i] != ' ' && str[i] != '\0')
	{
		i++;
		if ((str[i] == '<' && str[i - 1] == '<') \
		|| (str[i] == '>' && str[i - 1] == '>'))
			i++;
		return (i);
	}
	while (!ft_strchr(SPSIGN, str[i]) && str[i] != ' ' && str[i] != '\0')
		ft_countletcom(str, &com, &i);
	return (i - com);
}

static char	**ft_split2(const char *str, char **result, int l)
{
	int		*i;
	int		count;

	i = malloc(sizeof(int) * 3);
	i[0] = 0;
	count = ft_count(str);
	while (str[i[0]] != '\0' && l < count)
	{
		i[2] = 0;
		while (str[i[0]] == ' ')
			i[0]++;
		i[1] = ft_countlet(str, i[0]);
		result[l] = malloc((i[1] - i[0] + 1) * sizeof(char));
		if (!result)
			return (ft_free(result));
		i = ft_splitcopyspecial(str, result, i, l);
		result[l][i[2]] = '\0';
		l++;
	}
	result[l] = NULL;
	free(i);
	return (result);
}

char	**ft_argvsplit(char const *str)
{
	int		l;
	char	**result;

	l = 0;
	if (!str)
		return (NULL);
	while (*str == ' ')
		str++;
	result = malloc((ft_count(str) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_split2(str, result, l);
	return (result);
}
