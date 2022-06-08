/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:11:19 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/18 18:47:17 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_writeheredoc(char *limiter, int *pfd)
{
	size_t	len;
	char	*line;

	len = ft_strlen(limiter);
	while (limiter)
	{
		line = readline(">");
		if (!line || g_interactive == 3)
		{
			close(pfd[0]);
			close(pfd[1]);
			g_interactive = 0;
			exit(1);
		}
		if (!ft_strncmp(line, limiter, len))
		{
			close(pfd[0]);
			close(pfd[1]);
			g_interactive = 0;
			exit(0);
		}
		ft_putstr_fd(line, pfd[1]);
		ft_putstr_fd("\n", pfd[1]);
		free(line);
	}
}

static void	ft_readheredoc(t_data *head, int i)
{
	int		pfd[2];
	pid_t	pid;

	dup2(head->std[0], STDIN_FILENO);
	if (pipe(pfd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		g_interactive = 2;
		ft_writeheredoc(head->files[i], pfd);
	}
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	signals_handlers_default();
	wait(NULL);
	signals_handlers();
}

void	dup_fds(int pipe_fd[2], t_data *head)
{
	int	i;

	i = -1;
	while (head->files && head->files[++i])
	{
		if (head->dir[i] == LEFT)
			ft_open_left(head, i);
		else if (head->dir[i] == LEFTLEFT)
			ft_readheredoc(head, i);
		else if (head->dir[i] == RIGHT)
			ft_open_right(head, i);
		else if (head->dir[i] == RIGHTRIGHT)
			ft_open_rightright(head, i);
	}
	if (head->next != NULL && (!ft_strchr(head->dir, RIGHT)
			&& !ft_strchr(head->dir, RIGHTRIGHT)))
		dup2(pipe_fd[1], STDOUT_FILENO);
	else if (!ft_strchr(head->dir, RIGHT)
		&& !ft_strchr(head->dir, RIGHTRIGHT))
		dup2(head->std[1], STDOUT_FILENO);
}
