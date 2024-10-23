/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:24:24 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/09/25 19:34:42 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] && s[i] != c)
			i++;
		count++;
		}
	}
	return (count);
}

typedef struct s_split {
	char	**final;
	int		i;
	int		j;
	int		count;
}	t_split;

char	**ft_split(char const *s, char c)
{
	t_split	vs;

	vs.i = 0;
	vs.j = 0;
	vs.count = 0;
	vs.final = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!vs.final)
		return (0);
	while (s[vs.i])
	{
		while (s[vs.i] == c && s[vs.i])
			vs.i++;
		while (s[vs.count + vs.i] != c && s[vs.count + vs.i])
			vs.count++;
		if (vs.count > 0)
		{
			vs.final[vs.j++] = ft_substr(s, vs.i, vs.count);
			if (!vs.final[vs.j - 1])
				return (0);
			vs.i += vs.count;
			vs.count = 0;
		}
	}
	vs.final[vs.j] = NULL;
	return (vs.final);
}
