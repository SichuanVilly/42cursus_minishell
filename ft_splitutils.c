/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:39:43 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/09 18:47:33 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*ft_copychar(const char *str, char **result, int *i, int l)
{
	result[l][i[2]] = str[i[0]];
	i[0]++;
	i[2]++;
	return (i);
}

static void	ft_splitcopy(const char *str, char **result, int *i, int l)
{
	if (str[i[0]] == '\'' )
	{
		i[0]++;
		while (str[i[0]] != '\'' && str[i[0]] != '\0')
			i = ft_copychar(str, result, i, l);
		i[0]++;
	}
	else if (str[i[0]] == '\"' )
	{
		i[0]++;
		while (str[i[0]] != '\"' && str[i[0]] != '\0')
			i = ft_copychar(str, result, i, l);
		i[0]++;
	}
	else
		i = ft_copychar(str, result, i, l);
}

int	*ft_splitcopyspecial(const char *str, char **result, int *i, int l)
{
	if (ft_strchr(SPSIGN, str[*i]) && str[*i] != ' ' && str[*i] != '\0')
	{
		i = ft_copychar(str, result, i, l);
		if ((str[*i] == '<' && str[*i - 1] == '<') \
		|| (str[*i] == '>' && str[*i - 1] == '>'))
			i = ft_copychar(str, result, i, l);
		return (i);
	}		
	while (!ft_strchr(SPSIGN, str[*i]) && str[*i] != ' ' && str[*i] != '\0')
		ft_splitcopy(str, result, i, l);
	return (i);
}

void	ft_countpalspchar(const char *str, int *cpal, int *i)
{
	if (ft_strchr(SPSIGN, str[*i]))
	{
		if (*i && !ft_strchr(SPSIGN, str[*i - 1]) && str[*i - 1] != ' ')
			(*cpal)++;
		(*i)++;
		if ((str[*i] == '<' && str[*i - 1] == '<') \
		|| (str[*i] == '>' && str[*i - 1] == '>'))
			(*i)++;
	}
}

void	ft_countletcom(const char *str, int *com, int *i)
{
	if (str[*i] == '\'' )
	{
		*com = 2;
		(*i)++;
		while (str[*i] != '\'' && str[*i] != '\0')
			(*i)++;
	}
	else if (str[*i] == '\"' )
	{
		*com = 2;
		(*i)++;
		while (str[*i] != '\"' && str[*i] != '\0')
			(*i)++;
	}
	else
		(*i)++;
}
