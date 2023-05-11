/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:54:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/11 12:51:11 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_var {
    char    **av;
    char    **env;
    int     in_fd;
    int     out_fd;
    char    *path;
}           t_var;

int	    main(int ac, char **av, char **env);
int	    ft_error(int x, int in_fd, int out_fd);
void	close_unused_pipes(int **pfd, int x, int y, int z);

void    create_processes(t_var var, int pipe_fd);

void    exec_cmd(t_var var, int *pfd);

#endif
