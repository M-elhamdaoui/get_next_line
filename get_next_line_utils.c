/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:36:22 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/27 12:53:04 by mel-hamd         ###   ########.fr       */
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