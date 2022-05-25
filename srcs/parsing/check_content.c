/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:13 by saich             #+#    #+#             */
/*   Updated: 2022/05/25 19:37:11 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_info	*init_info(void)
{
	t_info	*info;

	if (check_malloc(&info, sizeof(t_info)))
		return (NULL);
	info->celling = NULL;
	info->ea_path = NULL;
	info->floor = NULL;
	info->map = NULL;
	info->no_path = NULL;
	info->so_path = NULL;
	info->we_path = NULL;
	info->str = NULL;
	info->next = NULL;
	return (info);
}
static char	*trim_nl(char *str)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			len++;
		i++;
	}
	if (check_malloc(&tmp, sizeof(char) * len + 1))
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			tmp[len++] = str[i];
		i++;
	}
	tmp[len] = '\0';
	free(str);
	return (tmp);
}

static char	*trim_space(char *str)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			len++;
		i++;
	}
	if (check_malloc(&tmp, sizeof(char) * len + 1))
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			tmp[len++] = str[i];
		i++;
	}
	tmp[len] = '\0';
	free(str);
	return (tmp);
}

/* int	check_first_letter(char *str)
{
	if (str[0] == 'N' || str[0] == 'W' || str[0] == 'E' || str[0] == 'S' || \
str[0] == 'F' || str[0] == 'C')
		
} */

static void	suppress_emptyl(t_list **lst)
{
	t_list	*cur;
	t_list	*tmp;

	while (*lst && (*lst)->content[0] == '\n' && (*lst)->content[1] == '\0')
	{
		cur = *lst;
		*lst = (*lst)->next;
		free(cur->content);
		free(cur);
	}
	tmp = *lst;
	while (tmp)
	{
		cur = tmp->next;
		while (cur && cur->content[0] == '\n' && cur->content[1] == '\0')
		{
			if (cur->next)
				tmp->next = cur->next;
			else
				tmp->next = NULL;
			free(cur->content);
			cur->next = NULL;
			free(cur);
			cur = tmp->next;
		}
		tmp = tmp->next;
	}
}

static int	suppress_space(t_list **lst)
{
	t_list	*tmp;
	int		i;

	suppress_emptyl(lst);
	tmp = *lst;
	i = 0;
	while (tmp)
	{
		if (i < 6)
			tmp->content = trim_space(tmp->content);
		else
			tmp->content = trim_nl(tmp->content);
		if (!tmp->content)
			return (print_error(strerror(errno)));
		tmp = tmp->next;
		i++;
	}
	return (0);
}

t_info	*check_content(t_list **lst)
{
	t_info	*info;

	info = init_info();
	if (!info)
		return NULL;
	if (suppress_space(lst))
		return (NULL);
	while(*lst)
	{
		printf("%s\n", (*lst)->content);
		*lst = (*lst)->next;
	}
	return (NULL);
}
