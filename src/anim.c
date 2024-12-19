/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:44:22 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/19 12:59:29 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	animate_enemy(t_game *game, int dir)
{
	if (dir)
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
				ENEMY_RIGHT, &game->map->img_width, &game->map->img_height);
	}
	else
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
				ENEMY_LEFT, &game->map->img_width, &game->map->img_height);
	}
}
