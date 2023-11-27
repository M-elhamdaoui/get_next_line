/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:36:15 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/27 13:12:59 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_len(char *str)
{
	if (*str)
		return (get_len(str + 1) + 1);
	return (0);
}

char	*get_next(char *str)
{
	char	*next;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (*(str + len) && *(str + len) != '\n')
		len++;
	if (*(str + len) == '\n')
		len++;
	next = (char *)malloc(len + 1);
	if (!next)
		return (NULL);
	while (i < len)
	{
		next[i] = str[i];
		i++;
	}
	return (next[len] = '\0', next);
}

char	*ft_resize(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (*(str + i) == '\n')
		i++;
	while (*(str + i + j))
		j++;
	new = (char *)malloc(j + 1);
	if (!new)
		return (free(str), str = NULL, NULL);
	new = fill(new, str + i);
	free(str);
	if (*new == '\0')
		return (free(new), new = NULL, NULL);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (free(str), str = NULL, NULL);
	if (!ft_strchr(str, '\n'))
		str = loading(str, fd);
	next = get_next(str);
	str = ft_resize(str);
	if (!next || *next == '\0')
		return (free(str), free(next), str = NULL, NULL);
	return (next);	
}
