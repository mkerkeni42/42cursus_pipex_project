/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:58:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/11 21:09:19 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_low(unsigned long long nb, int count)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putnbr_hexa(nb, base);
	while (nb >= 16)
	{
		nb = nb / 16;
		count++;
	}
	count++;
	return (count);
}
