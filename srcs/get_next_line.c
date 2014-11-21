/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:00:27 by tchezier          #+#    #+#             */
/*   Updated: 2014/11/21 17:25:26 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int get_next_line(int const fd, char **line)
{
	char buf[BUF_SIZE + 1];
	int ret;
	int x;

	x = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
			buf[ret] = '\0';
			ft_putnbr(ret);
			ft_putchar('\n');
			ft_putstr(buf);
			ft_strcpy(line[x], buf);
			x++;
	}
	ft_putstr("\n on sort du while !");
	ft_putchar('\n');
	ft_putstr("copie reussi");
	return (0);
}

int main()
{
	int fd;
	int back;
	char **line2;

	line2 = NULL;
	fd = open("getlines", O_RDONLY);
	ft_putnbr(fd);
	ft_putchar('\n');
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	back = get_next_line(fd, line2);
	ft_putnbr(back);
	ft_putchar('\n');
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
