/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:55:36 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/30 18:43:21 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_putecho(char **args, int i)
{
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(args[i++], 1);
	return (i);
}

int	check_echo_args(char **args, int i, int j, int *new_line)
{
	int	skip;

	skip = 0;
	if (args[1] && args[1][0] == '-')
	{
		*new_line = 0;
		while (args[1][++i])
		{
			if ('n' != args[1][i])
				*new_line = 1;
		}
		i = 0;
	}
	while (args[1] && args[j] && args[j][0] == '-')
	{
		skip++;
		while (args[j][++i])
		{
			if ('n' != args[j][i])
				return (--skip);
		}
		j++;
		i = 0;
	}
	return (skip);
}

int	ft_echo(char **args)
{
	int	i;
	int	j;
	int	skip;
	int	new_line;

	i = 0;
	j = 2;
	skip = 0;
	new_line = 1;
	skip = check_echo_args(args, i, j, &new_line);
	i = 1;
	if (new_line == 0)
		i = 2 + skip;
	if (!args[i])
	{
		if (new_line == 1)
			ft_putstr_fd("\n", 1);
		return (0);
	}
	ft_putstr_fd(args[i++], 1);
	while (args[i])
		i = ft_putecho(args, i);
	if (new_line == 1)
		ft_putchar_fd('\n', 1);
	return (0);
}
