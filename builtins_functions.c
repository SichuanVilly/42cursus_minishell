/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:27:58 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/25 18:00:35 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unset(char **args, char **env)
{
	char	**new_env;
	int		i[2];
	int		flag;
	char	*p;

	i[0] = -1;
	new_env = NULL;
	if (!env || !*env)
		return (new_env);
	while (env[++i[0]])
	{
		flag = 1;
		i[1] = -1;
		while (args[++i[1]])
		{
			p = ft_strjoin(args[i[1]], "=");
			if (ft_strncmp(env[i[0]], p, ft_strlen(p)) == 0)
				flag = 0;
			free(p);
		}
		if (flag != 0)
			new_env = append_str(new_env, env[i[0]]);
	}
	ft_free(env);
	return (new_env);
}

int	ft_pwd(void)
{
	char	*str;
	size_t	n;

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
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (1);
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i++], 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
