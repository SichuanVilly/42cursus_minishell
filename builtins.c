/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:31:04 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/25 17:33:08 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_shlvl(char **env)
{
	char	*shlvl;
	char	*sub;
	int		nbr;

	if (!env || !*env)
		return ;
	while (ft_strncmp(*env, "SHLVL=", 6))
		env++;
	sub = ft_substr(*env, 6, UINT_MAX);
	nbr = ft_atoi(sub) + 1;
	free(sub);
	sub = ft_itoa(nbr);
	shlvl = ft_strjoin("SHLVL=", sub);
	free(sub);
	free(*env);
	*env = shlvl;
}

char	**copy_matrix(char **envp)
{
	char	**env;
	char	**ret;

	if (!envp)
		return (NULL);
	env = malloc(sizeof(char *) * (count_strs(envp) + 1));
	if (!env)
		return (NULL);
	ret = env;
	while (*envp)
		*env++ = ft_strdup(*envp++);
	*env = NULL;
	return (ret);
}

char	**env_builtins(t_data *head, char **env)
{
	if (ft_strncmp(head->cmds[0], "export", 10) == 0)
		env = ft_export(head->cmds, env);
	else if (ft_strncmp(head->cmds[0], "unset", 10) == 0)
		env = ft_unset(head->cmds, env);
	else if (ft_strncmp(head->cmds[0], "cd", 10) == 0)
		env = ft_cd(head->cmds, env);
	else if (ft_strncmp(head->cmds[0], "exit", 10) == 0)
		ft_exit(head->cmds);
	return (env);
}

int	exec_builtins(t_data *head, char **env)
{
	int	exec;

	exec = 1;
	if (ft_strncmp(head->cmds[0], "echo", 10) == 0)
		exec = ft_echo(head->cmds);
	else if (ft_strncmp(head->cmds[0], "export", 10) == 0)
	{
		env = ft_export(head->cmds, env);
		exec = 0;
	}
	else if (ft_strncmp(head->cmds[0], "pwd", 10) == 0)
		exec = ft_pwd();
	else if (ft_strncmp(head->cmds[0], "env", 10) == 0)
		exec = print_matrix(env);
	else if (ft_strncmp(head->cmds[0], "exit", 10) == 0)
	{
		if (env)
			ft_free(env);
		ft_exit(head->cmds);
	}
	return (exec);
}

void	ft_exit(char **cmds)
{
	int	nbr;

	if (!cmds[1])
		exit(0);
	if (ft_isnumber(cmds[1]) == 0 || ft_strlen(cmds[1]) > 20)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmds[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	else if (cmds[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return ;
	}
	nbr = atoexit(cmds[1]);
	exit(nbr);
}
