/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:03:51 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/07 17:42:11 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_calcule_dquotes(char *str)
{
	int i = 0;
	int	counter = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			counter++;
		i++;
	}
	return (counter);
}

int	ft_calcule_quotes(char *str)
{
	int	i = 0;
	int	counter = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			counter++;
		i++;
	}
	return (counter);
}

int	count_tokens(char *str)
{
	int (i), 
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
	char	*ptr;

	i = 0;
	x = 0;
	if (ft_calcule_quotes(str) % 2 != 0)
		ft_error_quotes('\'');
	if (ft_calcule_dquotes(str) % 2 != 0)
		ft_error_quotes('\"');
	ptr = malloc(ft_clean_len(str) + 1);
	if (!ptr)
		return (NULL);
	if (str[i] == '\"' || str[i] == '\'')
		i++;
	while (str[i])
		ptr[x++] = str[i++];
	if (ptr[x - 1] == '\'' || ptr[x - 1] == '\"')
		return (ptr[x - 1] = '\0', ptr);
	ptr[x] = '\0';
	return (ptr);
}
char	**control_split_argement(char *str)
{
	char **argement;

	if (ft_calcule_dquotes(str) % 2 == 0)
		argement = ft_split(str, '\"');
	// if (ft_calcule_quotes(str) % 2 == 0)
		
}