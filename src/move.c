/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:43:09 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/17 13:43:47 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	move_up(t_game *game)
{
	if (!game->player->go_up)
		return ;
	game->player->img = game->player->img_up;
	if (game->map->matrix[(game->player->y - 1)][(game->player->x)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y - 1)][(game->player->x)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y - 1)][(game->player->x)] = 'P';
	game->player->y -= 1;
	game->moves++;
}

void	move_down(t_game *game)
{
	if (!game->player->go_down)
		return ;
	game->player->img = game->player->img_down;
	if (game->map->matrix[(game->player->y + 1)][(game->player->x)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y + 1)][(game->player->x)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y + 1)][(game->player->x)] = 'P';
	game->player->y += 1;
	game->moves++;
}

void	move_left(t_game *game)
{
	if (!game->player->go_left)
		return ;
	game->player->img = game->player->img_left;
	if (game->map->matrix[(game->player->y)][(game->player->x - 1)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y)][(game->player->x -1)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y)][(game->player->x - 1)] = 'P';
	game->player->x -= 1;
	game->moves++;
}

void	move_right(t_game *game)
{
	if (!game->player->go_right)
		return ;
	game->player->img = game->player->img_right;
	if (game->map->matrix[(game->player->y)][(game->player->x + 1)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y)][(game->player->x + 1)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y)][(game->player->x + 1)] = 'P';
	game->player->x += 1;
	game->moves++;
}
