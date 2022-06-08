/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:46:53 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/30 19:59:22 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **result)
{
	int	i;

	i = -1;
	if (!result)
		return (0);
	while (result[++i])
		free(result[i]);
	free(result);
	return (0);
}

t_data	*freecmdslst(char **result)
{
	int	i;

	i = -1;
	if (!result)
		return (0);
	while (result[++i])
		free(result[i]);
	free(result);
	return (0);
}
