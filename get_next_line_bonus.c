/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbach <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:39:44 by jbach             #+#    #+#             */
/*   Updated: 2022/01/10 20:39:45 by jbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*str;
	int			reading;
	static char	buf[1025][BUFFER_SIZE + 1];

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE < 1)
		return (0);
	str = NULL;
	str = ft_strjoin(str, buf[fd]);
	reading = 1;
	while (reading && ft_strchr(buf[fd]) == 0)
	{
		reading = read(fd, buf[fd], BUFFER_SIZE);
		if (reading < 0)
		{
			free (str);
			return (NULL);
		}
		buf[fd][reading] = '\0';
		str = ft_strjoin(str, buf[fd]);
	}
	str = ft_getline(str);
	ft_getbuf(buf[fd]);
	return (str);
}
