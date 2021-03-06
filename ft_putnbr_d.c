/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:24:42 by aer-razk          #+#    #+#             */
/*   Updated: 2021/12/15 13:24:47 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_d(unsigned int n, int fd, int *i)
{
	unsigned int	k;

	k = n;
	if (k < 0)
	{
		write(fd, "-", 1);
		(*i)++;
		k = -k;
	}
	if (k >= 0)
	{
		if (k < 10)
		{
			write (fd, &"0123456789"[k], 1);
			(*i)++;
		}
		else
		{
			ft_putnbr_d(k / 10, fd, i);
			(*i)++;
			write(fd, &"0123456789"[k % 10], 1);
		}
	}
}
