/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:35:55 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/05/11 12:03:00 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_str(char **str)
{
	int	i;
	
	i = -1;
	while (str[++i])
		free(str[i]);
}

static char	**get_commands(t_var var, int x)
{
	char	**cmds;
	
	if (x == 0)
		cmds = ft_split(var.av[2], ' ');
	else
		cmds = ft_split(var.av[3], ' ');
	return (cmds);
}

static char	*get_cmd_path(t_var var, char **cmds)
{
	char	**splitted_paths;
	char	*cmd_path;
	char	*test_cmd_path;
	int		i;
	
	i = -1;
	splitted_paths = ft_split(var.path, ':');
	while (splitted_paths[++i])
	{
		test_cmd_path = ft_strjoin(splitted_paths[i], "/");
		cmd_path = ft_strjoin(test_cmd_path, cmds[0]);
		free(test_cmd_path);
		if (access(cmd_path, X_OK) == 0)
		{
			free_str(splitted_paths);
			return (cmd_path);
		}
	}
	free(test_cmd_path);
	free(cmd_path);
	free(splitted_paths);
	return (NULL);
}

void	exec_cmd(t_var var)
{
	char	**cmds;
	char	*cmd_path;
	
	cmds = get_commands(var, 0);
	if (!cmds)
		ft_error(6, var.in_fd, var.out_fd);
	cmd_path = get_cmd_path(var, cmds);
	if (!cmd_path)
	{
		free_str(cmds);
		ft_error(5, var.in_fd, var.out_fd);
	}
	cmds[0] = cmd_path;
	if (execve(cmds[0], cmds, var.env) == -1)
		ft_error(7, var.in_fd, var.out_fd);
}
