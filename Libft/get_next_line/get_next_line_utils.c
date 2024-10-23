/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:58:43 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/12 21:53:47 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int x)
{
	char	*str_final;
	int		i;
	int		len_final;

	i = 0;
	len_final = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	str_final = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_final)
		return (NULL);
	else
	{
		ft_strcpy(str_final, s1);
		while (s2[i] != '\0')
		{
			str_final[i + ft_strlen(s1)] = s2[i];
			i++;
		}
		str_final[len_final] = '\0';
	}
	free (s1);
	if (x == 1)
		free (s2);
	return (str_final);
}
