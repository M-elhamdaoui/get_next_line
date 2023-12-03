/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:24:05 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/03 19:24:27 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_buff(void)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = (char *)malloc((size_t)(BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	while (i < (size_t)BUFFER_SIZE)
		buff[i++] = '\0';
	buff[i] = '\0';
	return (buff);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (*(s + len) != '\0')
		len++;
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

t_list	*create_lst(int fd, t_list *next)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = next;
	return (new);
}

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

char	*ft_strjoin(char *str, char *buff, int n)
{
	int		s_len;
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	s_len = 0;
	while (*(str + s_len) != '\0')
		s_len++;
	new = (char *)malloc(s_len + n + 1);
	if (!new || !buff)
		return (free(str), str = NULL, NULL);
	while (*(str + i))
	{
		new[i] = str[i];
		i++;
	}
	while (j < n)
	{
		new[i + j] = buff[j];
		j++;
	}
	return (free(str), str = NULL, new[i + j] = '\0', new);
}
