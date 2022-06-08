/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollarutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:36:23 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/25 18:08:10 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_special	insertstr(t_special s, char *read, char *insert, int *i)
{
	while (s.j < i[0] - 1)
	{
		s.new[s.j] = read[s.k];
		s.j++;
		s.k++;
	}
	s.k += s.dollen + 1;
	while (insert && s.l < s.tlen[1])
	{
		s.new[s.j] = insert[s.l];
		s.j++;
		s.l++;
	}
	while (s.j < s.tlen[0] - 1)
	{
		s.new[s.j] = read[s.k];
		s.j++;
		s.k++;
	}
	s.new[s.j] = '\0';
	return (s);
}

static char	*substit(char *read, char *insert, int *i, int dollen)
{
	t_special	s;

	s.j = 0;
	s.k = 0;
	s.l = 0;
	s.tlen[1] = 0;
	s.dollen = dollen;
	if (insert)
		s.tlen[1] = ft_strlen(insert);
	s.tlen[0] = ft_strlen(read) - dollen - 1 + s.tlen[1] + 1;
	s.new = malloc(sizeof(char) * s.tlen[0]);
	s = insertstr(s, read, insert, i);
	free(read);
	free(insert);
	return (s.new);
}

static char	*novar(char *read, int *i, int len)
{
	if (!len)
	{
		i[1] = 0;
		return (read);
	}
	return (substit(read, NULL, i, len));
}

static void	mininit(int *len, int *i, int *j, int *k)
{
	*len = 0;
	i[0]++;
	*j = i[0] - 1;
	*k = 0;
	i[1] = 1;
}

char	*substitute_dollar(char *read, char **env, int *i, int status)
{
	int		len;
	int		j;
	int		k;
	char	*var;
	char	*p;

	mininit(&len, i, &j, &k);
	if (read[i[0]] == '?')
		return (substit(read, ft_itoa(status), i, 1));
	if (!env || !*env)
		return (novar(read, i, len));
	while (read[++j] && (ft_isalpha(read[j]) || read[j] == '_'))
		len++;
	p = ft_substr(read, i[0], len);
	var = ft_strjoin(p, "=");
	j = i[0];
	while (env[k] && ft_strncmp(var, env[k], len + 1))
		k++;
	free(var);
	free(p);
	if (!env[k])
		return (novar(read, i, len));
	read = substit(read, ft_strdup(env[k] + len + 1), i, len);
	return (read);
}
