/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:21:00 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/03 19:21:02 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char	*get_next_line(int fd);

typedef struct t_list
{
	char			*str;
	int				fd;
	struct t_list	*next;
}	t_list;

char	*create_buff(void);
void	cleanup(t_list **head, t_list *toclean);
char	*loading(t_list *lst, t_list **head);
t_list	*create_lst(int fd, t_list *next);
t_list	*get_current(t_list **head, int fd);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *str, char *buff, int n);
char	*ft_strdup(char *s);

#endif
