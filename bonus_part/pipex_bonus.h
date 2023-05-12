/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:54:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/12 22:59:23 by mkerkeni         ###   ########.fr       */
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
    int     ac;
    char    **env;
    int     in_fd;
    int     out_fd;
    char    *path;
    int     pipe_nb;
}           t_var;

int	    main(int ac, char **av, char **env);
int	    ft_error(int x, int in_fd, int out_fd);
void	close_pipes(t_var var, int **pfd, int i);
int	    **get_pfd(t_var var);

void    create_processes(t_var var);

char    *get_path(char **env);
void    exec_cmd(t_var var, int arg);

#endif
