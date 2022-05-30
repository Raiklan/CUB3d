/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:28:43 by saich             #+#    #+#             */
/*   Updated: 2022/05/30 20:39:42 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(char **map)
{
	int		i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
	}
}

void	free_info(t_info *info)
{
	if (info->celling)
		free(info->celling);
	if (info->ea_path)
		free(info->ea_path);
	if (info->floor)
		free(info->floor);
	if (info->no_path)
		free(info->no_path);
	if (info->so_path)
		free(info->so_path);
	if (info->we_path)
		free(info->we_path);
	free_map(info->map);
	free(info);
}
