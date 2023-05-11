/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:53:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/11 12:51:42 by mkerkeni         ###   ########.fr       */
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

void	close_unused_pipes(int **pfd, int x, int y, int z)
{
	if (x == 1)
	{
		close
	}
}

static int	get_fd(char *path, int x)
{
	int	fd;

	if (x == 0)
		fd = open(path, O_RDONLY, 0777);
	else
		fd = open(path, O_WRONLY, 0777);
	if (fd == -1)
	{
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static char    *get_command_path(char **env)
{
    char    *path;
    int     i;

    i = -1;
    while (env[++i])
    {
        if (ft_strnstr(env[i], "PATH=/usr", ft_strlen(env[i])))
        {
            path = env[i] + 5;
            break ;
        }
    }
    return (path);
}

int	main(int ac, char **av, char **env)
{
	int		in_fd;
	int		out_fd;
	char	*path;
	int		pipe_nb;
	t_var	var;
	
	if (ac < 5)
	{
		perror("ERROR: Wrong number of arguments !\n");
		exit(EXIT_FAILURE);
	}
	in_fd = get_fd(av[1], 0);
	out_fd = get_fd(av[4], 1);
	path = get_command_path(env);
	if (!path)
		ft_error(5, in_fd, out_fd);
	var.av = av;
	var.env = env;
	var.in_fd = in_fd;
	var.out_fd = out_fd;
	var.path = path;
	pipe_nb = ac - 4;
	create_processes(var, pipe_nb);
	return (0);
}