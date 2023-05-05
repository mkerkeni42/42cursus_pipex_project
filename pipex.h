/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:54:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/05 11:48:53 by mkerkeni         ###   ########.fr       */
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
# include <string.h>
# include <fcntl.h>

typedef struct s_var {
    char    **av;
    char    **envp;
    int     infile_fd;
    int     outfile_fd;
    char    *path;
}           t_var;

int	    main(int ac, char **av, char **envp);
int	    get_fd(char *path, int x);
int	    ft_error(int x);
void    create_processes(t_var var);
void    execute_first_command(t_var var, int *pfd);
void    execute_second_command(t_var var, int *pfd);
void    free_str(char **str);

#endif
