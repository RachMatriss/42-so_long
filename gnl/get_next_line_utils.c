/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:27:45 by ramedjra          #+#    #+#             */
/*   Updated: 2023/01/29 13:23:01 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	len = gnl_strlen((char *) s1) + gnl_strlen((char *)s2);
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char )c)
	{
		if (s[i] == '\0')
			return ((char *) 0);
		i++;
	}
	return ((char *)&s[i]);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			i;
	unsigned int	length;

	length = (unsigned int)gnl_strlen(s);
	if (len == 0)
		return (NULL);
	if (start >= length)
		len = 0;
	else if (start < length)
		length = length - start;
	if (length < len)
		len = length;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i] != '\0')
		substring[i] = s[start + i];
	substring[i] = '\0';
	return (substring);
}
