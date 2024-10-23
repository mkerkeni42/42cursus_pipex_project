/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:42:13 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/09/25 19:34:42 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s_len;
	unsigned int	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		return (ft_calloc(1, 1));
	if (len <= s_len)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (s_len - start));
	if (!str)
		return (NULL);
	while (s[start] && start < s_len && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
