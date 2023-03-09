/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:40:42 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/09 15:46:34 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Reserva con malloc un array de strings resultante de separar 's' en sub-str
 * utilizando el caracter 'c' como delimitador. El array debe terminar con un 
 * puntero Null.*/

static unsigned int	ft_num_words(const char *s, char c)
{
	unsigned int	num_w;

	num_w = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			num_w++;
		while (*s && *s != c)
			s++;
	}
	return (num_w);
}

static char	*ft_put_word(char *word, char const *s, unsigned int i, int w_len)
{
	unsigned int	j;

	j = 0;
	while (w_len > 0)
	{
		word[j] = s[i - w_len];
		j++;
		w_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_array(const char *s, char c, char **s2, unsigned int num_w)
{
	unsigned int	i;
	unsigned int	w_len;
	unsigned int	w;

	i = 0;
	w = 0;
	w_len = 0;
	while (w < num_w)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			w_len++;
			i++;
		}
		s2[w] = (char *)malloc(sizeof(char) * (w_len + 1));
		if (!s2)
			return (0);
		ft_put_word(s2[w], s, i, w_len);
		w_len = 0;
		w++;
	}
	s2[w] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	num_w;

	num_w = ft_num_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (num_w + 1));
	if (!s || !strings)
		return (0);
	ft_array(s, c, strings, num_w);
	return (strings);
}
