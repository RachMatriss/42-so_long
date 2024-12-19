/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:32:49 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/19 13:20:43 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"

int	update(t_game *game)
{
	if (!game)
		exit(0);
	if (game->enemy->count)
		move_enemy(game);
	animate_enemy(game, game->enemy->dir);
	draw_map(game);
	return (0);
}

void	init_game(t_game *game)
{
	init_img(game);
	init_player(game);
	init_enemy(game);
	check_map(game);
	draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		check_path(argv[1]);
		game = ft_calloc(1, sizeof(t_game));
		game->mlx_ptr = mlx_init();
		if (!init_map(game, argv[1]))
			exit_game(game, "Error: invalide map \n", 1);
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width,
				game->map->height + SS * 2, "so_long[42WOLF => ramedjra]");
		init_game(game);
		mlx_key_hook(game->win_ptr, move_player, game);
		mlx_loop_hook(game->mlx_ptr, update, game);
		mlx_hook(game->win_ptr, 17, 0, update, NULL);
		mlx_loop(game->mlx_ptr);
	}
	else
		write(1, "Error, please try : ./so_long <map_path> \n", 42);
	return (0);
}
