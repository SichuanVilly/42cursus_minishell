/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:38:27 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/30 19:40:43 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_status(pid_t pid, int cmd_nbr)
{
	int	status;
	int	signal;

	signals_handlers_default();
	waitpid(pid, &status, 0);
	while (--cmd_nbr > 0)
		wait(NULL);
	signals_handlers();
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		signal = 128 + WTERMSIG(status);
		if (signal == 130)
			ft_putstr_fd("^C\n", 1);
		else if (signal == 131)
			ft_putstr_fd("^\\Quit: 3\n", 1);
		return (128 + WTERMSIG(status));
	}
	return (-1);
}

static void	free_my_vars(char *cmd1, char **all_paths, char *p)
{
	free(cmd1);
	ft_free(all_paths);
	free(p);
}

static char	*get_path(char **envp, char *cmd1)
{
	char	**all_paths;
	char	*check_path;
	char	*p;
	int		i;

	if (!cmd1 || !*cmd1 || !envp || !*envp)
		exit(1);
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (access(cmd1, F_OK) == 0)
		return (cmd1);
	if (!envp || !*envp)
		return (NULL);
	cmd1 = ft_strjoin("/", cmd1);
	p = ft_substr(*envp, 5, INT_MAX);
	all_paths = ft_split(*envp, ':');
	check_path = ft_strjoin(*all_paths, cmd1);
	i = -1;
	while (access(check_path, F_OK) != 0 && all_paths[++i])
	{
		free(check_path);
		check_path = ft_strjoin(all_paths[i], cmd1);
	}
	free_my_vars(cmd1, all_paths, p);
	return (check_path);
}

static void	exec_cmds(t_data *temp, int pipe_fd[2], char **env)
{
	char	*path;

	dup_fds(pipe_fd, temp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (!temp->cmds)
		exit(0);
	else if (ft_strncmp(temp->cmds[0], "cd", 5) == 0
		|| ft_strncmp(temp->cmds[0], "unset", 10) == 0)
		exit(0);
	if (exec_builtins(temp, env) == 0)
		exit(0);
	path = get_path(env, temp->cmds[0]);
	if (execve(path, temp->cmds, env) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(temp->cmds[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

int	pipex(t_data *head, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_data	*temp;

	temp = head;
	pid = 0;
	while (temp)
	{
		if (pipe(pipe_fd) == -1)
			return (-1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			exec_cmds(temp, pipe_fd, env);
		if (temp->next != NULL)
			dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		temp = temp->next;
	}
	close(STDIN_FILENO);
	return (get_status(pid, ft_lstsize(head)));
}
