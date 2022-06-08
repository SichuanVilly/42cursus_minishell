/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:50:58 by jlopez-f          #+#    #+#             */
/*   Updated: 2022/05/18 20:01:59 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_history(void)
{
	int		fd;
	char	*line;
	char	*aux;

	fd = open(".minishell_history", O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (line)
		aux = ft_substr(line, 0, ft_strlen(line) - 1);
	while (line)
	{
		add_history(aux);
		free(line);
		free(aux);
		line = get_next_line(fd);
		if (line)
			aux = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	close (fd);
}

void	ft_add_history(char *read)
{
	int	fd;

	fd = open(".minishell_history", O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
		return ;
	add_history(read);
	ft_putstr_fd(read, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}
