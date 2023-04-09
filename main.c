/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:53:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/04/09 14:39:07 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_file(char *path, int x)
{
	int	fd;

	if (x == 0)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY);
	if (fd == -1)
		ft_error(6);
	return (fd);
}

int	main(int ac, char **av)
{
	int	pid;
	int	fd[2];
	int	infile_fd;
	int	outfile_fd;
	char	*buffer;
	
	if (ac != 5)
		ft_error(0);
	buffer = malloc(sizeof(char) * ft_strlen(av[2]) + 1);
	infile_fd = get_file(av[1], 0);
	outfile_fd = get_file(av[4], 1);
	if (pipe(fd) == -1)
		ft_error(2);
	pid = fork();
	if (pid == -1)
		ft_error(1);
	if (pid == 0)
	{
		if (close(fd[0]) == -1)
			ft_error(3);
		if (write(fd[1], &av[2][i], 1) == -1)
			ft_error(4);
		if (close(fd[1]) == -1)
			ft_error(3);	
	}
	else
	{
		if (close(fd[1]) == -1)
			ft_error(3);
		if (read(fd[0], buffer, ft_strlen(av[2])) == -1)
			ft_error(5);
		if (close(fd[0]) == -1)
			ft_error(3);
	}
	if (wait(NULL) == -1 || errno != ECHILD)
		ft_error(6);
	return (EXIT_SUCCESS);
}

/*int	main(void)
{
	int	id;
	int	x;
	int	y;
	int	fd[2];
	
	x = 0;
	y = 0;
	if (pipe(fd) == -1)
	{
		printf("An error occurred while opening the pipe\n");
		return (1);
	}
	id = fork();
	if (id == -1)
		printf("An error occurred with fork\n");
	if (id == 0)
	{
		close(fd[0]);
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
			printf("An error occurred while writing to the pipe\n");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
			printf("An error occurred while reading from the pipe\n");
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}*/