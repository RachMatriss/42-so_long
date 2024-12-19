/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:43:20 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/17 13:43:32 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	ft_free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

size_t	ft_arrlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_arrdup(char **arr)
{
	int		i;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * (ft_arrlen(arr) + 1));
	if (!str)
		return (NULL);
	while (arr[i])
	{
		str[i] = ft_strdup(arr[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
