/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_those_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:26:43 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/25 13:31:54 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*signal_case1(char *read, char *new_read)
{
	char	*p;

	p = ft_substr(read, 0, ft_strlen(read) - 1);
	ft_add_history(p);
	free(p);
	free(read);
	free(new_read);
	g_interactive = 0;
	return (ft_strdup(""));
}

static char	*signal_case2(char *read, char *new_read, char *q)
{
	char	*p;

	free(q);
	q = ft_strjoin(read, new_read);
	p = ft_substr(q, 0, ft_strlen(q) - 1);
	ft_add_history(p);
	free(p);
	free(read);
	free(new_read);
	free(q);
	g_interactive = 0;
	return (ft_strdup(""));
}

static char	*free_join(char *s1, char *s2)
{
	char	*r;

	r = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (r);
}

static char	*get_those_quotes(char *read, char quotes)
{
	char	*new_read;
	char	*q;

	read = free_join(read, ft_strdup("\n"));
	g_interactive = 2;
	new_read = readline("> ");
	if (!new_read || g_interactive == 3)
		return (signal_case1(read, new_read));
	g_interactive = 0;
	while (read && !ft_strchr(new_read, (int)quotes))
	{
		new_read = free_join(new_read, ft_strdup("\n"));
		g_interactive = 2;
		q = readline("> ");
		if (!q || g_interactive == 3)
			return (signal_case2(read, new_read, q));
		g_interactive = 0;
		new_read = free_join(new_read, q);
	}
	read = free_join(read, new_read);
	check_those_quotes(read);
	return (read);
}

char	*check_those_quotes(char *read)
{
	char	quotes;
	int		i;

	quotes = 0;
	i = 0;
	while (read[i])
	{
		if ((read[i] == '\'' || read[i] == '"') && quotes == 0)
			quotes = read[i];
		else if ((read[i] == '\'' || read[i] == '"') && quotes == read[i])
			quotes = 0;
		i++;
	}
	if (quotes == 0)
		return (read);
	else
		return (get_those_quotes(read, quotes));
}
