/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:53:01 by lemarque          #+#    #+#             */
/*   Updated: 2021/09/23 00:41:14 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_word;
	size_t	strings_size;
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	strings_size = s1_size + s2_size;
	new_word = malloc(sizeof(char) * strings_size + 1);
	if (new_word == NULL)
		return (0);
	while (i < strings_size)
	{
		if (i < s1_size)
			new_word[i] = s1[i];
		else
			new_word[i] = s2[i - s1_size];
		i++;
	}
	new_word[strings_size] = '\0';
	return (new_word);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*new_word;

	size = ft_strlen(s);
	new_word = malloc(sizeof(char) * (size + 1));
	if (!new_word)
		return (0);
	size = 0;
	while (s[size] != '\0')
	{
		new_word[size] = s[size];
		size++;
	}
	new_word[size] = '\0';
	return (new_word);
}

size_t	ft_strlen(const char *str)
{
	size_t	s;

	s = 0;
	while (str[s])
		s++;
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return (ft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
