/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:15:51 by tchezier          #+#    #+#             */
/*   Updated: 2015/01/21 18:50:48 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int anyn(const char *str)
{
	int x;

	x = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			return (x);
		x++;
		str++;
	}
	return (-1);
}

int restetr(char **line, char **reste)
{
	int		x;

	while (*reste != NULL)
	{
		x = anyn(*reste);
		if (x > 0)
		{
			*line = ft_strjoin(*line, ft_strsub(*reste, 0, x));
			if (((size_t)(x + 1)) < ft_strlen(*reste))
				*reste = ft_strdup(*reste + (x + 1));
			else
				*reste = NULL;
			return (1);
		}
		else if (x == 0)
		{
			*reste = ft_strdup(*reste + 1);
			return (1);
		}
		*line = ft_strjoin(*line, *reste);
		*reste = NULL;
	}
	return (-2);
}

int buftr(char *buf, char **line, char **reste)
{
	int		x;
	char	*tmp;

	x = anyn(buf);
	if (x > 0)
	{
		tmp = ft_strsub(buf, 0, x);
		*line = ft_strjoin(*line, tmp);
		if (((size_t)(x + 1)) < ft_strlen(buf))
			*reste = ft_strdup(buf + (x + 1));
		else
			*reste = NULL;
		free(tmp);
		return (1);
	}
	else if (x == 0)
	{
		*reste = ft_strdup(buf + 1);
		return (1);
	}
	*line = ft_strjoin(*line, buf);
	*reste = NULL;
	return (-2);
}

int get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*reste = NULL;
	int			ret;

	ret = 0;
	if (fd < 0 || (fd == 1) || (fd == 99))
		return (-1);
	*line = ft_strdup("\0");
	while (1)
	{
		if (reste != NULL)
			if (restetr(line, &reste) == 1)
				return (1);
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if ((ret == 0 && reste == NULL) || (ret == -1))
		{
			free(reste);
			return (ret);
		}
		if (buftr(buf, line, &reste) == 1)
			return (1);
	}
	return (0);
}
