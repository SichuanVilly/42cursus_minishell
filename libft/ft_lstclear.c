/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:52:36 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/12 19:01:46 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_data **lst)
{
	t_data	*temp;

	if (!*lst)
		return ;
	temp = *lst;
	*lst = NULL;
	while (temp)
	{
		if (temp->cmds)
			ft_free(temp->cmds);
		if (temp->files)
			ft_free(temp->files);
		if (temp->dir)
			free(temp->dir);
		free(temp);
		temp = temp->next;
	}
}
