/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:03:51 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/04 17:32:01 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_calcule_dquotes(char *str)
{
	int i;
	while (str[i])
	{
		if (str[i] == '\"')
			i++;
	}
	return (i);
}

int	ft_calcule_quotes(char *str)
{
	int i;
	while (str[i])
	{
		if (str[i] == '\'')
			i++;
	}
	return (i);
}

int	ft_clean_len(char *str)
{
	int i;

	i = 0;
	if (!str)
		return i;
	if (str[i] == '\"' || str[i] == '\'')
		i++;
	while (str[i] && str[i] != '\"' && str[i] != '\'')
		i++;
	return (i);
}

char	*ft_splitquotes(char *str)
{
	int		i;
	int		x;
	char 	*ptr;

	i = 0;
	x = 0;
	if (ft_calcule_quotes(str) % 2 != 0 || ft_calcule_dquotes(str) % 2 != 0)
		exit(1);
	ptr = malloc(ft_clean_len(str) + 1);
	if (!ptr)
		return (NULL);
	
	if (str[i] == '\"' || str[i] == '\'')
		i++;
	while (str[i] && str[i])
		ptr[x++] = str[i++];
	ptr[x] = '\0';
	return (ptr);
}
