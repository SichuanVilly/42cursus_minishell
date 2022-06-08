/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_file_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:01:45 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/30 17:03:39 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_open_left(t_data *head, int i)
{
	int	fd;

	fd = open(head->files[i], O_RDWR | 0644);
	if (fd == -1)
		could_not_open(head->files[i]);
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	ft_open_right(t_data *head, int i)
{
	int	fd;

	fd = open(head->files[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		could_not_open(head->files[i]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	ft_open_rightright(t_data *head, int i)
{
	int	fd;

	fd = open(head->files[i], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
		could_not_open(head->files[i]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	could_not_open(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": could not open file or directory\n", 2);
}
