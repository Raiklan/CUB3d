/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:39:47 by saich             #+#    #+#             */
/*   Updated: 2022/06/09 17:02:00 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include <string.h>
# include <errno.h>

typedef struct s_info
{
	char			*str;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*floor;
	char			*celling;
	char			**map;
	struct s_info	*next;
}				t_info;

			/* Parsing of the .cub file */
int		print_error(char *str);
t_info	*check_content(t_list **lst);
int		empty_space_line(t_list *lst);
void	suppress_emptyl(t_list **lst);
int		right_conf_for_cub(t_list **lst, t_info *info);
int		is_map(char *str);

//free_utils.c
void	free_info(t_info *info);
int		count_lst(t_list *lst);
#endif
