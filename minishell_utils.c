/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:29:26 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/24 18:14:54 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_lenchar(char const *s, int c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len] != c && s[len])
		len++;
	return (len);
}

int	count_strs(char **arr)
{
	int	length;

	length = 0;
	if (!arr)
		return (length);
	while (arr[length])
		length++;
	return (length);
}

char	*get_oldpwd(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			return (ft_substr(env[i], 7, UINT_MAX));
		env++;
	}
	return (NULL);
}

char	*get_pwd(void)
{
	char	*str;
	int		n;

	n = 1;
	str = NULL;
	while (1)
	{
		str = malloc(sizeof(char) * n);
		if (getcwd(str, n) == NULL)
			free(str);
		else
			break ;
		n++;
	}
	return (str);
}

int	ft_isnumber(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s++) == 0)
			return (0);
	}
	return (1);
}
