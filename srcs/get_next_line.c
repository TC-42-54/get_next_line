/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:00:27 by tchezier          #+#    #+#             */
/*   Updated: 2014/11/20 10:30:58 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int get_next_line(int const fd, char ** line)
{
	char buf[BUF_SIZE + 1];
	int ret;

	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		//*line = strdup(buf);
		//line++;
	}
	*line = strdup(buf);
	return (0);
}

int main()
{
	int fd;
	int back;
	char **line;

	line = NULL;
	fd = open("getlines", O_RDONLY);
	ft_putnbr(fd);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while (back != 0)
	{
		back = get_next_line(fd, line);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
