/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:45:04 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/16 17:21:28 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	size_t	i;
	size_t	j;
	char	*new;

	new = (char *)malloc(len1 + len2 + 1);
	if (!new)
		return (ft_free(&s1));
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (ft_strjoin(s1, s2, len1, len2));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		new = malloc(sizeof(char) * (1));
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
