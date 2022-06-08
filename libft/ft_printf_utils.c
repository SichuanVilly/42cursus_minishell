/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 22:32:05 by pvillena          #+#    #+#             */
/*   Updated: 2022/02/10 14:18:22 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_p(char c, int *print)
{
	write(1, &c, 1);
	(*print)++;
}

void	ft_putstr_p(char *s, int *print)
{
	if (!s)
	{
		ft_putstr_p("(null)", print);
		return ;
	}
	while (*s)
		ft_putchar_p(*s++, print);
}

void	ft_aux_putnbr_p(int n, int *print)
{
	if (n < 10)
		ft_putchar_p(n + 48, print);
	else
	{
		ft_aux_putnbr_p(n / 10, print);
		ft_putchar_p(n % 10 + 48, print);
	}
}

void	ft_putnbr_p(int n, int *print)
{
	if (n == -2147483648)
	{
		ft_putstr_p("-2147483648", print);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		(*print)++;
		n *= -1;
	}
	ft_aux_putnbr_p(n, print);
}

void	ft_unsigned_putnbr_p(unsigned int n, int *print)
{
	if (n < 10)
		ft_putchar_p(n + 48, print);
	else
	{
		ft_aux_putnbr_p(n / 10, print);
		ft_putchar_p(n % 10 + 48, print);
	}
}
