/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:01:17 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/15 15:34:26 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


static void	get_input(t_var var, int **pfd, int *tmp_fd)
{
	char	*line;

	if (close(pfd[0][0]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
	close_pipes(var, pfd, -1);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, var.av[2], ft_strlen(line)))
		{
			free(line);
			if (close(tmp_fd[1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			return ;
		}
		write(tmp_fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
}

int	create_process_here_doc(t_var var, int **pfd)
{
	int		pid;
	int		tmp_fd[2];

	if (pipe(tmp_fd) == -1)
		ft_error(1, var.in_fd, var.out_fd);
	if (close(pfd[0][0]) == -1)
		ft_error(2, var.in_fd, var.out_fd);
	close_pipes(var, pfd, -1);
	pid = fork();
	if (pid == -1)
		ft_error(0, var.in_fd, var.out_fd);
	if (pid == 0)
		get_input(var, pfd, tmp_fd);
	dup2(tmp_fd[0], STDIN_FILENO);
	if (close(tmp_fd[0]) == -1)
		ft_error(2, var.in_fd, var.out_fd);
	dup2(pfd[0][1], STDOUT_FILENO);
	if (close(pfd[0][1]) == -1)
		ft_error(2, var.in_fd, var.out_fd);
	if (close(tmp_fd[0]) == -1 || close(tmp_fd[1]) == -1)
		ft_error(2, var.in_fd, var.out_fd);
	if (waitpid(pid, NULL, 0) == -1)
		ft_error(3, var.in_fd, var.out_fd);
	exec_cmd(var, 3);
	return (pid);
}
