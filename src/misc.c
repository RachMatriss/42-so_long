/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:43:53 by ramedjra          #+#    #+#             */
/*   Updated: 2023/05/17 15:15:59 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	draw_score(t_game *game)
{
	int		x;
	int		y;
	char	*moves;

	moves = ft_itoa(game->moves);
	x = (game->map->x / 2) * SS;
	y = game->map->y * SS + 32;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Moves: ");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->map->empty_img, x + 42, y - 20);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0x0000FF00, moves);
	free(moves);
}

int	check_exit(t_game *game)
{
	char	*msg;

	msg = ft_strjoin("You Win , Congratulation ! \n Total Real moves: ",
			ft_itoa(game->moves));
	if (game->map->coins == game->map->coins_counter)
		exit_game(game, msg, 0);
	return (0);
}

int	check_move(char **matrix, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(matrix[0]);
	y_len = ft_arrlen(matrix);
	if ((x >= 0 && x < x_len && y >= 0 && y < y_len && matrix[y][x] != '1'))
		return (1);
	return (0);
}

void	draw_xpm(t_game **game, void *img, int x, int y)
{
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		img, x, y);
}

void	exit_game(t_game *game, char *msg, int status)
{
	ft_printf("%s \n", msg);
	if (game->win_ptr && game)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	exit(status);
}
