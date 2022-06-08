/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:48:27 by pvillena          #+#    #+#             */
/*   Updated: 2022/05/25 13:41:51 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	num_too_large(const char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd((char *)str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit(255);
}

static unsigned long long int	ft_atouli(char const *str)
{
	unsigned long long int	ans;
	int						sign;

	ans = 0;
	sign = 1;
	if (ft_strncmp("-9223372036854775808", str, 30) == 0)
		exit(0);
	if (*str == 45)
	{
		sign = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		ans = ans * 10 + (*str - 48);
		str++;
	}
	if (ans > 9223372036854775807 && sign < 0)
		num_too_large(str);
	else if (ans > 9223372036854775807 && sign > 0)
		num_too_large(str);
	return ((long long int)(ans * sign));
}

int	atoexit(char const *str)
{
	unsigned long long int	nbr;

	if (ft_strlen(str) == 20 && str[0] != '-')
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd((char *)str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
	nbr = ft_atouli(str);
	if (nbr >= 0)
		return (nbr % 256);
	else
	{
		while (nbr < 0)
			nbr += 256;
		return (nbr);
	}
}
