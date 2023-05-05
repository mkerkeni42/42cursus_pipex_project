/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:53:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/05 14:58:15 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int x)
{
	if (x == 0)
		perror("ERROR: Wrong number of arguments !\n");
	else if (x == 1)
		perror("ERROR: failed to fork the process\n");
	else if (x == 2)
		perror("ERROR: failed to open the pipe\n");
	else if (x == 3)
		perror("ERROR: failed to close the pipe\n");
	else if (x == 4)
		perror("ERROR: failed to write into the pipe\n");
	else if (x == 5)
		perror("ERROR: failed to read from the pipe\n");
	else if (x == 5)
		perror("ERROR: failed to wait for the process to finish\n");
	else if (x == 6)
		perror("ERROR: failed to open the file\n");
	else if (x == 7)
		perror("ERROR: failed to close the file\n");
	else if (x == 8)
		perror("ERROR: Failed to find the command path\n");
	else if (x == 9)
		perror("ERROR: Failed to get the commands");
	else if (x == 10)
		perror("ERROR: the execve function call failed");
	exit(EXIT_FAILURE);
}

int	get_fd(char *path, int x)
{
	int	fd;

	if (x == 0)
		fd = open(path, O_RDONLY, 777);
	else
		fd = open(path, O_WRONLY, 777);
	if (fd == -1)
		ft_error(6);
	return (fd);
}

static char    *get_command_path(char **envp)
{
    char    *path;
    int     i;

    i = -1;
    while (envp[++i])
    {
        if (ft_strnstr(envp[i], "PATH=/usr", ft_strlen(envp[i])))
        {
            path = envp[i] + 5;
            break ;
        }
    }
    return (path);
}

void	create_processes(t_var var)
{
	int	pfd[2];
	int	pid1;
	int	pid2;
	
	if (pipe(pfd) == -1)
		ft_error(2);
	pid1 = fork();
	if (pid1 == -1)
		ft_error(1);
	if (pid1 == 0)
		execute_first_command(var, pfd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error(1);
	if (pid2 == 0)
		execute_second_command(var, pfd);
	if (close(pfd[1]) == -1)
		ft_error(3);
	if (close(pfd[0]) == -1)
		ft_error(3);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int		infile_fd;
	int		outfile_fd;
	char	*path;
	t_var	var;
	
	if (ac != 5)
		ft_error(0);
	infile_fd = get_fd(av[1], 0);
	outfile_fd = get_fd(av[4], 1);
	path = get_command_path(envp);
	if (!path)
	{
		close(infile_fd);
		close(outfile_fd);
		ft_error(8);
	}
	var.av = av;
	var.envp = envp;
	var.infile_fd = infile_fd;
	var.outfile_fd = outfile_fd;
	var.path = path;
	create_processes(var);
	return (0);
}
