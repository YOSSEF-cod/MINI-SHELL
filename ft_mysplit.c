/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:44 by ybounite          #+#    #+#             */
/*   Updated: 2025/04/05 11:15:42 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int 	ft_isoperator(char c)
{
	return (c == '&' || c == '|' || c == '>' || c == '<');
}

int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isoperator(*str))
			str++;
		if (*str && !ft_isoperator(*str))
		{
			count++;
			while (*str && !ft_isoperator(*str))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char    *word;
	int	i;

	i = 0;
	while (str[i] && !ft_isoperator(str[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isoperator(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_spliter(char *str)
{
	char    **arr;
	int     i;

    i = 0;
    arr = malloc(sizeof(char *) * (count_words(str) + 1));
	while (*str)
	{
		while (*str && ft_isoperator(*str))
			str++;
		if (*str && !ft_isoperator(*str))
		{
			arr[i] = malloc_word(str);
			i++;
			while (*str && !ft_isoperator(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
