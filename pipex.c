/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:35:55 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/03 00:22:27 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_commands(t_var var, int x)
{
	char	**cmd;
	
	if (x == 0)
		cmd = ft_split(var.av[2], ' ');
	else
		cmd = ft_split(var.av[3], ' ');
	return (cmd);
}

static char	*get_cmd_path(t_var var, char **cmd)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(var.path, "/");
	cmd_path = ft_strjoin(cmd_path, cmd[0]);
	return (cmd_path);
}

void	execute_first_command(t_var var, int *pfd)
{
	char	**cmd1;
	char	*cmd_path;
	
	dup2(var.infile_fd, STDIN_FILENO);
	if (close(var.infile_fd) == -1)
		ft_error(7);
	if (close(pfd[0]) == -1)
		ft_error(3);
	dup2(pfd[1], STDOUT_FILENO);
	if (close(pfd[1]) == -1)
		ft_error(3);
	cmd1 = get_commands(var, 0);
	cmd_path = get_cmd_path(var, cmd1);
	cmd1[0] = cmd_path;
	if (execve(cmd_path, cmd1, var.envp) == -1)
		perror("Error with execve of the first command\n");
}

void	execute_second_command(t_var var, int *pfd)
{
	char	**cmd2;
	char	*cmd_path;
	
	dup2(var.outfile_fd, STDOUT_FILENO);
	if (close(var.outfile_fd) == -1)
		ft_error(7);
	if (close(pfd[1]) == -1)
		ft_error(3);
	dup2(pfd[0], STDIN_FILENO);
	if (close(pfd[0]) == -1)
		ft_error(3);
	cmd2 = get_commands(var, 1);
	cmd_path = get_cmd_path(var, cmd2);
	cmd2[0] = cmd_path;
	if (execve(cmd2[0], cmd2, var.envp) == -1)
		perror("Error with execve of the second command\n");
}
