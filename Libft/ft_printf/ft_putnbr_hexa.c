/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:55:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/11 21:08:59 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long long nb, char *hexa)
{
	if (nb >= 16)
	{
		ft_putnbr_hexa((nb / 16), hexa);
		ft_putnbr_hexa((nb % 16), hexa);
	}
	else
		ft_putchar_fd(hexa[nb], 1);
}
