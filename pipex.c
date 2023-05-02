/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:35:55 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/02 15:55:08 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	execute_first_command(int *pfd, char **av, char *cmd_path, int infile_fd)
{
	dup2(infile_fd, STDIN_FILENO);
		if (close(pfd[0]) == -1)
			ft_error(3);
		dup2(pfd[1], STDOUT_FILENO);
		if (close(pfd[1]) == -1)
			ft_error(3);
		execve(av[1], av, envp); // find how to execute command on infile data
}

void	execute_second_command(int *pfd, char **av, char *cmd_path, int outfile_fd)
{
		if (close(pfd[1]) == -1)
			ft_error(3);
		dup2(pfd[0], STDIN_FILENO); // we read from the pipe instead of stdin
		if (close(pfd[0]) == -1)
			ft_error(3);
		execve(pfd[0], av, envp); // we execute command on what is in the pipe
		// here we need to find a way to redirect the output of the execve in the outfile
}
