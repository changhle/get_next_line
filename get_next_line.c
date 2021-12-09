/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:47:43 by changhle          #+#    #+#             */
/*   Updated: 2021/12/09 18:29:48 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	char		*str;
	static char	*s_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_str = ft_read_str(fd, s_str);
	if (!s_str)
		return (NULL);
	str = ft_get_newline(s_str);
	while (s_str[i] && s_str[i] == '\n')
		i++;
	if (!s_str[i])
		return (str);
	
	return (str);
}

int	main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
}
