/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:54:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/02 15:54:49 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
#include <string.h>
# include <fcntl.h>

int	    main(int ac, char **av, char **envp);
int	    get_fd(char *path, int x);
int	    ft_error(int x);
void    create_processes(char **av, char *cmd_path, int infile_fd, int outfile_fd);

void    execute_first_command(int *pfd, char **av, char *cmd_path, int infile_fd);
void    execute_second_command(int *pfd, char **av, char *cmd_path, int outfile_fd);

#endif
