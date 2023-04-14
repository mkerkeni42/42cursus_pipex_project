/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:35:55 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/04/14 13:16:36 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int x)
{
	if (x == 0)
		write(2, "ERROR: Wrong number of arguments !\n", 35);
	else if (x == 1)
		write(2, "ERROR: failed to fork the process\n", 34);
	else if (x == 2)
		write(2, "ERROR: failed to open the pipe\n", 31);
	else if (x == 3)
		write(2, "ERROR: failed to close the pipe\n", 32);
	else if (x == 4)
		write(2, "ERROR: failed to write into the pipe\n", 37);
	else if (x == 5)
		write(2, "ERROR: failed to read from the pipe\n", 36);
	else if (x == 5)
		write(2, "ERROR: failed to wait for the process to finish\n", 48);
	else if (x == 6)
		write(2, "EERROR: failed to open the file\n", 32);
	exit(EXIT_FAILURE);
}
