/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:53:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/04/14 13:19:00 by mkerkeni         ###   ########.fr       */
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
	int	pfd[2];
	int	infile_fd;
	int	outfile_fd;
	char	*buf;
	
	if (ac != 5)
		ft_error(0);
	buf = malloc(sizeof(char) * ft_strlen(av[2]) + 1);
	infile_fd = get_file(av[1], 0);
	outfile_fd = get_file(av[4], 1);
	if (pipe(pfd) == -1)
		ft_error(2);
	pid = fork();
	if (pid == -1)
		ft_error(1);
	if (pid == 0)
	{
		if (close(pfd[1]) == -1)
			ft_error(3);
		if (read(pfd[0], buf, ft_strlen(av[2])) == -1)
			ft_error(5);
		if (close(pfd[0]) == -1)
			ft_error(3);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (close(pfd[0]) == -1)
			ft_error(3);
		if (write(pfd[1], &av[2], ft_strlen(av[2])) == -1)
			ft_error(4);
		if (close(pfd[1]) == -1)
			ft_error(3);	
		if (wait(NULL) == -1)
			ft_error(5);
		exit (EXIT_SUCCESS);
	}
}
