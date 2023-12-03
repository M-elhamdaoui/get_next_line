/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:19:14 by mel-hamd          #+#    #+#             */
/*   Updated: 2023/12/03 19:23:14 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*get_current(t_list **head, int fd)
{
	t_list	*temp;

	temp = *head;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
		return (temp = create_lst(fd, *head), *head = temp, temp);
	return (temp);
}

void	cleanup(t_list **head, t_list *toclean)
{
	t_list	*temp;
	t_list	*next;

	next = NULL;
	temp = *head;
	if (!toclean || !head || !*head)
		return ;
	if ((*head)->fd == toclean->fd)
	{
		next = (*head)->next;
		(free((*head)->str), free(*head), *head = next);
		return ;
	}
	while (temp && temp->next && temp->next->fd != toclean->fd)
		temp = temp->next;
	if (!temp->next)
		return ;
	(free(temp->next->str), temp->next->str = NULL);
	next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

char	*loading(t_list *lst, t_list **head)
{
	char	*buff;
	int		n;

	n = 1;
	if (!lst)
		return (NULL);
	if (!lst->str)
		lst->str = ft_strdup("");
	buff = create_buff();
	if (!buff)
		return (cleanup(head, lst), lst = NULL, NULL);
	while (n > 0 && lst->str && !ft_strchr(lst->str, '\n'))
	{
		n = read(lst->fd, buff, BUFFER_SIZE);
		if (n < 0)
			return (cleanup(head, lst), free(buff), lst = NULL, NULL);
		if (n >= 0)
			lst->str = ft_strjoin(lst->str, buff, n);
	}
	return (free(buff), buff = NULL, lst->str);
}

char	*get_next(t_list *lst, t_list **head)
{
	char	*dup;
	int		i;
	char	*res;

	i = 0;
	if (!loading(lst, head))
		return (cleanup(head, lst), lst = NULL, NULL);
	while (*(lst->str + i) && *(lst->str + i) != '\n')
		i++;
	if (*(lst->str + i) == '\n')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	dup = ft_strdup(lst->str + i);
	if (!dup)
		return (free(res), cleanup(head, lst), NULL);
	while (--i >= 0)
		res[i] = *(lst->str + i);
	return (free(lst->str), lst->str = dup, res);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*current;
	char			*next;

	current = get_current(&lst, fd);
	if (!current)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (cleanup(&lst, current), NULL);
	next = get_next(current, &lst);
	if (!next || *next == '\0')
		return (cleanup(&lst, current), free(next), NULL);
	return (next);
}
