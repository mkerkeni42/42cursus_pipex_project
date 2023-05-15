/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:53:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/15 12:03:01 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_error(int x, int in_fd, int out_fd)
{
	if (x == 0)
		perror("ERROR: failed to fork the process\n");
	else if (x == 1)
		perror("ERROR: failed to open the pipe\n");
	else if (x == 2)
		perror("ERROR: failed to close the pipe\n");
	else if (x == 3)
		perror("ERROR: failed to wait for the process to finish\n");
	else if (x == 4)
		perror("ERROR: failed to close the file\n");
	else if (x == 5)
		perror("ERROR: Failed to find the command path\n");
	else if (x == 6)
		perror("ERROR: Failed to get the commands");
	else if (x == 7)
		perror("ERROR: the execve function call failed");
	else if (x == 8)
		perror("ERROR: failed to open the file\n");
	close(in_fd);
	close(out_fd);
	exit(EXIT_FAILURE);
}

void	close_pipes(t_var var, int **pfd, int i)
{
	int	j;

	j = -1;
	while (++j < var.pipe_nb)
	{
		if (j != i && j != i + 1)
		{
			if (close(pfd[j][0]) == -1)
				ft_error(2, var.in_fd, var.out_fd);
			if (close(pfd[j][1]) == -1)
				ft_error(2, var.in_fd, var.out_fd);	
		}
	}
}

int	**get_pfd(t_var var)
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
		if (pipe(pfd[i]) == -1)
			ft_error(1, var.in_fd, var.out_fd);
	return (pfd);
}

static int	get_fd(char *path, int x)
{
	int	fd;

	if (x == 0)
		fd = open(path, O_RDONLY, 0777);
	else
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	main(int ac, char **av, char **env)
{
	int		in_fd;
	int		out_fd;
	char	*path;
	t_var	var;
	
	if (ac < 5)
	{
		perror("ERROR: Wrong number of arguments !\n");
		exit(EXIT_FAILURE);
	}
	in_fd = get_fd(av[1], 0);
	out_fd = get_fd(av[ac - 1], 1);
	path = get_path(env);
	if (!path)
		ft_error(5, in_fd, out_fd);
	var.av = av;
	var.ac = ac;
	var.env = env;
	var.in_fd = in_fd;
	var.out_fd = out_fd;
	var.path = path;
	var.pipe_nb = ac - 4;
	create_processes(var);
	return (0);
}
