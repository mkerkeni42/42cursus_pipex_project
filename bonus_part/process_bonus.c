/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:07:22 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/12 16:06:17 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	wait_for_processes(t_var var, int first_pid, int last_pid, int *pids, int x)
{
	int	i;

	i = 0;
	if (x == 0)
	{
		if (waitpid(first_pid, NULL, 0) == -1)
			ft_error(3, var.in_fd, var.out_fd);
	}
	if (x == 1)
	{
		while (i < (var.pipe_nb - 1))
		{
			if (waitpid(pids[i], NULL, 0) == -1)
			ft_error(3, var.in_fd, var.out_fd);
			i++;
		}
	}
	if (x == 2)
	{
		if (waitpid(last_pid, NULL, 0) == -1)	
			ft_error(3, var.in_fd, var.out_fd);
	}
}

static int	create_last_process(t_var var, int **pfd)
{
	int	pid;
	int	i;
	
	i = -1;
	pid = fork();
	if (pid == -1)
		ft_error(0, var.in_fd, var.out_fd);
	if (pid == 0)
	{
		if (close(pfd[var.pipe_nb - 1][1]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		while (++i < var.pipe_nb - 1)
		{
			if (close(pfd[i][1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			if (close(pfd[i][0]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
		}
		dup2(pfd[var.pipe_nb - 1][0], STDIN_FILENO);
		if (close(pfd[var.pipe_nb - 1][0]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		dup2(var.out_fd, STDOUT_FILENO);
		if (close(var.out_fd) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		exec_cmd(var, (var.ac) - 2);
	}
	return (pid);
}

static int	*create_mid_processes(t_var var, int **pfd)
{
	int	*pids;
	int	i;
	
	pids = malloc(sizeof(int) * (var.pipe_nb - 1));
	i = -1;
	while (++i < var.pipe_nb - 1)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error(0, var.in_fd, var.out_fd);
		if (pids[i] == 0)
		{
			close_pipes(var, pfd, i);
			if (close(pfd[i][1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			if (close(pfd[i + 1][0]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			dup2(pfd[i][0], STDIN_FILENO);
			if (close(pfd[i][0]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			dup2(pfd[i + 1][1], STDOUT_FILENO);
			if (close(pfd[i + 1][1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			exec_cmd(var, 2 + i + 1);
		}
	}
	return (pids);
}

static int	create_first_process(t_var var, int **pfd)
{
	int	pid;
	int	i;

	i = -1;
	pid = fork();
	if (pid == -1)
		ft_error(0, var.in_fd, var.out_fd);
	if (pid == 0)
	{
		dup2(var.in_fd, STDIN_FILENO);
		if (close(var.in_fd) == -1)
			ft_error(4, var.in_fd, var.out_fd);
		if (close(pfd[0][0]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		i = 0;
		while (++i < var.pipe_nb)
		{
			if (close(pfd[i][0]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			if (close(pfd[i][1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
		}
		dup2(pfd[0][1], STDOUT_FILENO);
		if (close(pfd[0][1]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		exec_cmd(var, 2);
	}
	return (pid);
}
/*static int	**get_pfd(t_var var)
{
	int	**pfd;
	int		i;

	i = -1;
	pfd = malloc(sizeof(int *) * (var.pipe_nb));
	if (!pfd)
		ft_error(8, var.in_fd, var.out_fd);
	while (++i < var.pipe_nb)
		pfd[i] = malloc(sizeof(int) * 2);
	if (!pfd)
		ft_error(8, var.in_fd, var.out_fd);
	i = -1;
	while (++i < var.pipe_nb)
	{
		if (pipe(pfd[i]) == -1)
			ft_error(1, var.in_fd, var.out_fd);
	}
	return (pfd);
}*/
void	create_processes(t_var var)
{
	int	**pfd;
	int	first_pid;
	int	last_pid;
	int	*mid_pids;
	int	i;
	
	
	i = -1;
	pfd = malloc(sizeof(int *) * (var.pipe_nb));
	if (!pfd)
		ft_error(8, var.in_fd, var.out_fd);
	while (++i < var.pipe_nb)
		pfd[i] = malloc(sizeof(int) * 2);
	if (!pfd)
		ft_error(8, var.in_fd, var.out_fd);
	i = -1;
	while (++i < var.pipe_nb)
	{
		if (pipe(pfd[i]) == -1)
			ft_error(1, var.in_fd, var.out_fd);
	}
	first_pid = create_first_process(var, pfd);
	if (var.pipe_nb > 1)
		mid_pids = create_mid_processes(var, pfd);
	last_pid = create_last_process(var, pfd);
	i = -1;
	while (++i < var.pipe_nb)
	{
		if (close(pfd[i][0]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
		if (close(pfd[i][1]) == -1)
			ft_error(2, var.in_fd, var.out_fd);
	}
	wait_for_processes(var, first_pid, last_pid, mid_pids, 0);
	if (var.pipe_nb > 1)
		wait_for_processes(var, first_pid, last_pid, mid_pids, 1);
	wait_for_processes(var, first_pid, last_pid, mid_pids, 2);
}
