/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:39:47 by saich             #+#    #+#             */
/*   Updated: 2022/05/24 19:50:25 by saich            ###   ########.fr       */
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

#endif
