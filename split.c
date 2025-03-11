/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:31:17 by azorlutu          #+#    #+#             */
/*   Updated: 2025/01/08 23:31:17 by azorlutu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*get_next_word(char *str, char seperator)
{
	static int	remaining_data = 0;
	char		*string;
	int			word_length;
	int			i;

	word_length = 0;
	i = 0;
	while (str[remaining_data] == seperator)
		++remaining_data;
	while ((str[word_length + remaining_data] != seperator)
		&& str[word_length + remaining_data])
		++word_length;
	string = malloc((sizeof(char) * word_length) + 1);
	if (string == NULL)
		return (NULL);
	while (str[remaining_data] != seperator && str[remaining_data])
		string[i++] = str[remaining_data++];
	string[i] = '\0';
	return (string);
}

static	int	count_words(char *str, char seperator)
{
	int		count;
	bool	is_in_word;

	count = 0;
	is_in_word = false;
	while (*str)
	{
		if (*str == seperator)
		{
			str++;
			is_in_word = false;
		}
		else
		{
			if (is_in_word == false)
			{
				count++;
				is_in_word = true;
			}
			if (*str && *str != seperator)
				str++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char seperator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, seperator);
	vector_strings = malloc(sizeof(char *) * (words_number + 2));
	if (vector_strings == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (vector_strings[i] == NULL)
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, seperator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
