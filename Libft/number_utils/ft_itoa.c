/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:43:13 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/09/25 19:34:42 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	fill_str(char *str, long nb, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		str_len;
	long	nb;

	nb = (long)n;
	str_len = 0;
	if (nb <= 0)
		str_len = 1;
	while (nb != 0)
	{
		nb /= 10;
		str_len++;
	}
	nb = (long)n;
	if (n < 0)
		nb *= -1;
	str = ft_calloc(sizeof(char), str_len + 1);
	if (!str)
		return (0);
	fill_str(str, nb, str_len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
