/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:54:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/04/14 11:58:03 by mkerkeni         ###   ########.fr       */
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

int	main(int ac, char **av);
int	get_file(char *path, int x);

int	ft_error(int x);

#endif
