/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:44 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:59 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>

int	ft_len(char *str)
{
	int (i), (cont);
	i = 0;
	cont = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i] == '\'' && str[i] == '\"')
			i++;
		if (str[i] != ' ' || str[i] != '\'' || str[i] == '\"')
			cont++;
		while (str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
			i++;
	}
	return (cont);
}

// char	**ft_mysplit(char *str)
// {
// 	char	**ptr;
// 	int		len;
	
// 	len = ft_len(str);
// 	printf ("%d", len);
// }
int main()
{
	printf ("%d", ft_len("echo \"hello world \'\""));
}