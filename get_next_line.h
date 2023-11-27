/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:36:10 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/11/27 13:14:06 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
char	*loading(char *str, int fd);
char	*ft_strdup(char *s);
char	*create_buff(void);
char	*ft_strjoin(char *str, char *buff, int n);
int	get_len(char *str);
char	*get_next(char *str);
char	*ft_resize(char *str);
char	*fill(char *str, char *old);

#endif
