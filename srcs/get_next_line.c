/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchezier <tchezier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:00:27 by tchezier          #+#    #+#             */
/*   Updated: 2014/11/22 18:57:23 by tchezier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int get_next_line(int const fd, char **line)
{
	char buf[BUF_SIZE + 1];
	char **tmp;
	int ret;
	int x;
	int i;
	int borne;

	x = 0;
	tmp = malloc((ft_strlen(buf) + 1) * (sizeof(char **)));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
			buf[ret] = '\0';
			ft_putendl("le buf :");
			ft_putendl(buf);
			ft_putnbr(ret);
			ft_putchar('\n');
			tmp[x] = ft_strdup(buf);
			ft_putendl("la chaine tmp :");
			ft_putendl(tmp[x]);
			x++;
	}
	line = malloc ((x + 1) * (sizeof(char **)));
	borne = 0;
	while(borne < x)
	{
		ft_putendl("on copie tmp dans line !");
		i = 0;
		line[borne] = tmp[borne];
		ft_putstr("tmp[");
		ft_putnbr(borne);
		ft_putstr("]\n");
		ft_putendl(tmp[borne]);
		ft_putstr("line[");
		ft_putnbr(borne);
		ft_putstr("]\n");
		ft_putendl(line[borne]);
		borne++;
	}
	ft_putstr("\n on sort du while !");
	ft_putchar('\n');
	ft_putstr("copie reussi");
	return (0);
}

char *backn(char *str)
{
	char *poubelle;
	size_t x;

	x = 0;
	while ((str[x] != '\0') && (str[x] != '\n'))
		x++;
	if (str[x] == '\n')
	{
		x++;
		while (str[x] != '\0')
		{
			*poubelle = str[x];
			poubelle++;
		}
		*poubelle = '\0';
	}
	else
		poubelle = NULL; 
	return (poubelle);
}

size_t prevn(const char *str)
{
	size_t x;

	x = 0;
	while ((str[x] != 0) && (str[x] != '\n'))
		x++;
	if (x < ft_strlen(str))
		return (x - 1);
	else
		return (ft_strlen(str));
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
