/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:42:32 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/17 13:42:41 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->matrix[i])
	{
		j = 0;
		while (game->map->matrix[i][j])
		{
			if (ft_strchr("01PCEG", game->map->matrix[i][j]) == 0
			&& game->map->matrix[i][j] != '\n')
				exit_game(game, "Error : invalide character in map \n", 1);
			j++;
		}
		i++;
	}
}

void	sanity_checks(t_game *game)
{
	check_chars(game);
	if (game->enemy->count > 1)
		exit_game(game, "Error : Map has more then one enemy \n", 1);
	if (game->player->count > 1)
		exit_game(game, "Error : Map has more then one player \n", 1);
	if (game->player->count == 0)
		exit_game(game, "Error : Map has No player \n", 1);
	if (game->map->exits == 0)
		exit_game(game, "Error : Map has no exits or coins \n", 1);
	if (game->map->exits > 1)
		exit_game(game, "Error : Map has more then one exit \n", 1);
	if (game->map->coins == 0)
		exit_game(game, "Error : Map has no coins \n", 1);
}
