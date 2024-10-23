/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:54:14 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/12 21:55:12 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_buf(char	*buf, char *final, char *temp)
{
	int		i;
	char	*after_nl;
	char	*before_nl;

	i = 0;
	while (buf[i] != *(ft_strchr(buf, '\n')))
		i++;
	before_nl = ft_substr(buf, 0, i + 1);
	after_nl = ft_substr(buf, i + 1, ft_strlen(buf) - i);
	final = ft_strjoin_gnl(final, before_nl, 1);
	ft_strcpy(temp, after_nl);
	free(after_nl);
	return (final);
}

static char	*trim_temp(char *temp, char *final)
{
	int		i;
	char	*after_nl;
	char	*before_nl;

	i = 0;
	while (temp[i] != *(ft_strchr(temp, '\n')))
		i++;
	before_nl = ft_substr(temp, 0, i + 1);
	after_nl = ft_substr(temp, i + 1, ft_strlen(temp) - i);
	final = ft_strjoin_gnl(final, before_nl, 1);
	ft_strcpy(temp, after_nl);
	free(after_nl);
	return (final);
}

static char	*handle_error(char *final, char *temp, int bool)
{
	free(final);
	if (bool == 1)
		final = NULL;
	temp[0] = '\0';
	return (NULL);
}

char	*handle_buf(char *buf, char *temp, char *final)
{
	if (ft_strchr(buf, '\n') != 0)
		final = trim_buf(buf, final, temp);
	else
		final = ft_strjoin_gnl(final, buf, 0);
	return (final);
}

char	*get_next_line(int fd)
{
	t_var		vars;
	static char	temp[1024][(BUFFER_SIZE + 1)];

	vars.ret = 1;
	vars.buf[0] = '\0';
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	vars.final = malloc(sizeof(char));
	vars.final[0] = '\0';
	if (ft_strchr(temp[fd], '\n') != 0 && *temp[fd])
		return (trim_temp(temp[fd], vars.final));
	vars.final = ft_strjoin_gnl(vars.final, temp[fd], 0);
	while (vars.ret != 0 && ft_strchr(vars.buf, '\n') == 0)
	{
		vars.ret = read(fd, vars.buf, BUFFER_SIZE);
		if (vars.ret == -1)
			return (handle_error(vars.final, temp[fd], 0));
		vars.buf[vars.ret] = '\0';
		vars.final = handle_buf(vars.buf, temp[fd], vars.final);
	}
	if (vars.ret == 0 && vars.final[0] == '\0')
		return (handle_error(vars.final, temp[fd], 1));
	else if (vars.ret == 0 && ft_strchr(temp[fd], '\n') == 0)
		temp[fd][0] = '\0';
	return (vars.final);
}
