/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:25:29 by dcapers           #+#    #+#             */
/*   Updated: 2020/02/27 22:25:30 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_joinfree(char *s1, char *s2)
{
	char	*result;

	if (!s1 && s2)
		result = ft_strdup(s2);
	else if (!s2 && s1)
		result = ft_strdup(s1);
	else
		result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static int		get_new_line(char **line, char **st)
{
	char	*mem;
	size_t	i;

	mem = *st;
	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	*line = ft_strsub(mem, 0, i);
	if (mem[i] != '\0')
		*st = ft_strsub(mem, i + 1, ft_strlen(mem) - i - 1);
	else
	{
		free(*st);
		*st = NULL;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*mem[10240];
	int				ret;

	if (fd < 0 || fd >= 10240)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!mem[fd])
			mem[fd] = ft_strnew(1);
		mem[fd] = get_joinfree(mem[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (mem[fd] == NULL || mem[fd][0] == '\0'))
		return (0);
	return (get_new_line(line, &mem[fd]));
}
