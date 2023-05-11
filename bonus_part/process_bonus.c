/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:07:22 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/11 12:49:46 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	wait_for_processes(t_var var, int first_pid, int last_pid, int *mid_pids)
{
	int	i;

	i = -1;
	if (waitpid(first_pid, NULL, 0) == -1)
		ft_error(3, var.in_fd, var.out_fd);
	while (++i < (sizeof(mid_pids) / 4))
	{
		if (waitpid(mid_pids[i], NULL, 0) == -1)
		ft_error(3, var.in_fd, var.out_fd);
	}
	if (waitpid(last_pid, NULL, 0) == -1)
		ft_error(3, var.in_fd, var.out_fd);
}

static int	create_last_process(t_var var, int **pfd, int pipe_nb)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error(0, var.in_fd, var.out_fd);
	if (pid == 0)
	{
		dup2(pfd[pipe_nb - 1][0], STDIN_FILENO);
		if (close(pfd[pipe_nb - 1][0]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		dup2(var.out_fd, STDOUT_FILENO);
		if (close(var.out_fd) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		exec_cmd(var, pfd);
	}
	return (pid);
}

static int	*create_mid_processes(t_var var, int **pfd, int pipe_nb)
{
	int	*pids;
	int	i;
	
	pids = malloc(sizeof(int) * (pipe_nb - 1));
	i = -1;
	while (++i < pipe_nb - 1)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error(0, var.in_fd, var.out_fd);
		if (pids[i] == 0)
		{
			dup2(pfd[i][0], STDIN_FILENO);
			if (close(pfd[i][0]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			dup2(pfd[i + 1][1], STDOUT_FILENO);
			if (close(pfd[i + 1][1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			exec_cmd(var, pfd);
		}
		return (pids);
	}
}

static int	create_first_process(t_var var, int **pfd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error(0, var.in_fd, var.out_fd);
	if (pid == 0)
	{
		dup2(var.in_fd, STDIN_FILENO);
		if (close(var.in_fd) == -1)
			ft_error(4, var.in_fd, var.out_fd);
		close_unused_pipes(pfd, );
		if (close(pfd[0][0]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		dup2(pfd[0][1], STDOUT_FILENO);
		if (close(pfd[0][1]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		exec_cmd(var, pfd);
	}
	return (pid);
}

void	create_processes(t_var var, int pipe_nb)
{
	int	**pfd;
	int	first_pid;
	int	last_pid;
	int	*mid_pids;
	int	i;
	
	
	i = -1;
	pfd = malloc(sizeof(int *) * (pipe_nb));
	if (!pfd)
		ft_error(8, var.in_fd, var.out_fd);
	while (++i < pipe_nb)
		pfd[i] = malloc(sizeof(int) * 2);
	if (!pfd)
		ft_error(8, var.in_fd, var.out_fd);
	i = -1;
	while (++i < pipe_nb) //open as many pipes as there are pipes in the command line
	{
		if (pipe(pfd[i]) == -1)
			ft_error(1, var.in_fd, var.out_fd);
	}
	first_pid = create_first_process(var, pfd);
	mid_pids = create_middle_processes(var, pfd, pipe_nb);
	last_pid = create_last_process(var, pfd, pipe_nb);
	wait_for_processes(var, first_pid, last_pid, mid_pids);
}
