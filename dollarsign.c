/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollarsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:41:33 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/30 17:45:48 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*dollarquote(char *read, char **env, int *i, int status)
{
	i[0]++;
	while (read[i[0]] && read[i[0]] != '\"')
	{
		if (read[i[0]] == '$' && read[i[0] + 1])
			read = substitute_dollar(read, env, i, status);
		else
			i[0]++;
	}
	i[0]++;
	return (read);
}

static char	*readdollar(char *read, char **env, int i[2], int status)
{
	if (read[i[0]] == '\"')
		read = dollarquote(read, env, i, status);
	else if (read[i[0]] == '\'')
	{
		i[0]++;
		while (read && read[i[0]] != '\'')
			i[0]++;
		i[0]++;
	}
	else
	{
		if (read[i[0]] == '$' && read[i[0] + 1])
			read = substitute_dollar(read, env, i, status);
		else
			i[0]++;
	}
	if (i[1] != 0)
	{
		i[0] = 0;
		i[1] = 0;
	}
	return (read);
}

char	*dollarsign(char *read, char **env, int status)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	if (!read || !*read)
		return (read);
	while (read && read[i[0]])
		read = readdollar(read, env, i, status);
	return (read);
}
