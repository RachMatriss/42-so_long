/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:44:00 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/19 12:53:40 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	init_img(t_game *game)
{
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL, &game->map->img_width, &game->map->img_height);
	game->map->empty_img = mlx_xpm_file_to_image(game->mlx_ptr,
			EMPTY, &game->map->img_width, &game->map->img_height);
	game->map->c_img = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE, &game->map->img_width, &game->map->img_height);
	game->map->exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT, &game->map->img_width, &game->map->img_height);
}
