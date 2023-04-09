/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:35:55 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/04/09 14:28:34 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int x)
{
	if (x == 0)
		write(2, "ERROR: Wrong number of arguments !\n", 35);
	else if (x == 1)
		write(2, "An error occurred with fork\n", 28);
	else if (x == 2)
		write(2, "An error occurred while opening the pipe\n", 41);
	else if (x == 3)
		write(2, "An error occurred while closing the pipe\n", 41);
	else if (x == 4)
		write(2, "An error occurred while writing to the pipe\n", 44);
	else if (x == 5)
		write(2, "An error occurred while reading from the pipe\n", 46);
	else if (x == 5)
		write(2, "An error occurred while waiting\n", 46);
	else if (x == 6)
		write(2, "An error occurred while opening the file\n", 41);	
	exit(EXIT_FAILURE);
}
