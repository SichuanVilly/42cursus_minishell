/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:35:05 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/12 15:03:17 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**append_str(char **origin, char *append)
{
	char	**ret;
	int		i;

	ret = (char **)malloc(sizeof(char *) * (count_strs(origin) + 2));
	i = 0;
	if (origin)
	{
		while (origin && origin[i])
		{
			ret[i] = ft_strdup(origin[i]);
			i++;
		}
		ft_free(origin);
	}
	ret[i] = ft_strdup(append);
	ret[++i] = NULL;
	return (ret);
}

t_data	*get_file(char **cmds, char dir, int *i, t_data *head)
{
	char	*p;
	char	str[2];

	p = head->dir;
	str[0] = dir;
	str[1] = '\0';
	head->dir = ft_strjoin(head->dir, str);
	if ((dir == RIGHTRIGHT || dir == LEFTLEFT) && cmds[*i + 1])
		head->files = append_str(head->files, cmds[++(*i)]);
	else if (cmds[*i + 1])
		head->files = append_str(head->files, cmds[++(*i)]);
	if (p)
		free(p);
	return (head);
}

t_data	*parse_machine(char **cmds, int *i)
{
	t_data	*head;

	head = ft_calloc(sizeof(t_data), 1);
	head->std[0] = dup(STDIN_FILENO);
	head->std[1] = dup(STDOUT_FILENO);
	while (cmds[++(*i)])
	{
		if (cmds[*i][0] == '|' && !cmds[*i][1])
			break ;
		if (ft_strncmp(cmds[*i], ">>", 2) == 0 && !cmds[*i][2])
			head = get_file(cmds, RIGHTRIGHT, i, head);
		else if (ft_strncmp(cmds[*i], "<<", 2) == 0 && !cmds[*i][2])
			head = get_file(cmds, LEFTLEFT, i, head);
		else if (ft_strncmp(cmds[*i], "<", 1) == 0 && !cmds[*i][1])
			head = get_file(cmds, LEFT, i, head);
		else if (ft_strncmp(cmds[*i], ">", 1) == 0 && !cmds[*i][1])
			head = get_file(cmds, RIGHT, i, head);
		else
			head->cmds = append_str(head->cmds, cmds[*i]);
	}
	return (head);
}
