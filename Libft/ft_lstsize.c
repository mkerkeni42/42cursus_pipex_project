/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:54:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2022/11/27 12:24:43 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current_lst;

	if (lst == NULL)
		return (0);
	i = 0;
	current_lst = lst->next;
	while (current_lst != NULL)
	{
		i++;
		current_lst = current_lst->next;
	}
	return (i + 1);
}
