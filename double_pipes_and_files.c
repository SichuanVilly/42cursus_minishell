/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_pipes_and_files.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:48:14 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/30 19:52:40 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**syntax_error_pipe(char **cmds, int *status)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
	*status = 258;
	ft_free(cmds);
	return (NULL);
}

static char	**syntax_error_newline(char **cmds, int *status, int i)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (!cmds[i + 1])
		ft_putstr_fd("newline'\n", 2);
	else
	{
		ft_putstr_fd(cmds[i + 1], 2);
		ft_putstr_fd("'\n", 2);
	}
	*status = 258;
	ft_free(cmds);
	return (NULL);
}

char	**double_pipes_and_files(char **cmds, int *status)
{
	int	i;

	if (!cmds)
		return (NULL);
	i = -1;
	while (cmds[++i])
	{
		if (cmds[i][0] == '|' && cmds[i + 1][0] == '|')
			return (syntax_error_pipe(cmds, status));
		if (((cmds[i][0] == '<' || cmds[i][0] == '>')
			&& (!cmds[i + 1] || (cmds[i + 1][0] == '<'
			|| cmds[i + 1][0] == '>'))))
			return (syntax_error_newline(cmds, status, i));
	}
	return (cmds);
}
