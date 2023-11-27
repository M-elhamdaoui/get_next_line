/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:36:22 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/27 12:55:13 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char c)
{
	unsigned char	*st;
	int				i;

	i = 0;
	st = (unsigned char *)str;
	if (!str)
		return (NULL);
	while (*(st + i))
	{
		if (*(st + i) == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*loading(char *str, int fd)
{
	int		n;
	char	*buff;

	n = 1;
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			return (NULL);
	}
	buff = create_buff();
	if (!buff)
		return (free(str), NULL);
	while (n > 0 && str && !ft_strchr(str, '\n'))
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
			return (free(str), free(buff), NULL);
		if (n > 0)
			str = ft_strjoin(str, buff, n);
	}
	free(buff);
	buff = NULL;
	return (str);
}
