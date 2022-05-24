/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:13 by saich             #+#    #+#             */
/*   Updated: 2022/05/24 19:53:17 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_info(t_info *info)
{
	info->celling = NULL;
	info->ea_path = NULL;
	info->floor = NULL;
	info->map = NULL;
	info->no_path = NULL;
	info->so_path = NULL;
	info->we_path = NULL;
	info->str = NULL;
	info->next = NULL;
}

int	check_content(t_list **lst)
{
	t_info	*info;

	init_info(info);
	
}
