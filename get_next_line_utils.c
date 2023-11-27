/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:36:22 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/27 12:59:44 by mel-hamd         ###   ########.fr       */
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

char	*ft_strdup(char *s)
{
	char	*new;
	int		len;

	if (!s)
		return (NULL);
	len = get_len(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	new[len] = '\0';
	return (new);
}

char	*create_buff(void)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (i < (size_t)BUFFER_SIZE)
		buff[i++] = '\0';
	buff[i] = '\0';
	return (buff);
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
