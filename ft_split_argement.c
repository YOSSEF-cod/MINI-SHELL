/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:58:14 by ybounite          #+#    #+#             */
/*   Updated: 2025/04/05 10:46:32 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

int	ft_calcule_quotes(char *str, char quote_char)
{
	int	(i), (counter);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == quote_char)
			counter++;
		i++;
	}
	if (counter % 2 != 0)
	{
		printf("minishell: unexpected EOF while looking for matching '%c'", quote_char);
		free(str);
		exit(1);
	}
	return (counter);
}

char	*get_operator(const char *s)
{
	if (ft_strncmp(s, "&&", 2) == 0)
		return "&&";
	if (ft_strncmp(s, "||", 2) == 0)
		return "||";
	if (ft_strncmp(s, "|", 1) == 0)
		return "|";
	if (ft_strncmp(s, ">", 1) == 0)
		return ">";
	if (ft_strncmp(s, "<", 1) == 0)
		return "<";
	if (ft_strncmp(s, "&", 1) == 0)
		return "&";
	if (ft_strncmp(s, ";", 1) == 0)
		return ";";
	return	NULL;
}

int ft_count_argement(char *str)
{
	int		counter = 0;
	int		i = 0;
	char	quotse_char;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
		{
			counter++;
			if (str[i] == '\'' || str[i] == '\"')
			{
				quotse_char = str[i++];
				ft_calcule_quotes(str, quotse_char);
				while (str[i] && str[i] != quotse_char)
					i++;
				if (str[i] == quotse_char)
					i++;
			}
			else
				while (str[i] && str[i] != '\'' && str[i] != '"' && str[i] != ' ')
					i++;
		}
	}
	return (counter);
}

int lenofword(char *str)
{
	int		len;
	char	quote_char;

	len = 0;
	while (str[len] == ' ')
		len++;
	if (str[len] == '\'' || str[len] == '"')
	{
		quote_char = str[len++];
		while (str[len] && str[len] != quote_char)
			len++;
		if (str[len] == quote_char)
			len++;
	}
	else
		while (str[len] && str[len] != ' ' && str[len] != '\'' && str[len] != '"')
		len++;
	return len;
}

char	*ft_full_arr(char *str, int len_word)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(len_word + 1);
	if (!ptr)
		return NULL;
	while (i < len_word)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
int cont_argement(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (is_operator(s[i]))
			i++;
			
		i++;
	}
	
}
char	**ft_split_argement(char *str)
{
	int i = 0;
	int size = 0;
	int	index = 0;
	int cont_argement = ft_count_argement(str);
	char **ptr = malloc(sizeof(char *) * (cont_argement + 1));
	if (!ptr)
			return NULL;
	while (str[i])
	{
		if (str[i])
		{
			while  (str[i] && str[i] == ' ')
				i++;
			if (str[i])
			{
				int size = lenofword(&str[i]);
				ptr[index] = ft_full_arr(&str[i], size);
				i += size;
				index++;
			}
		}
	}
	return (ptr[index] = NULL, ptr);
}

void	ft_free_arr(char **str)
{
	int i = 0;
	if (!str)
		return ;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
