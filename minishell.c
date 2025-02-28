/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/28 17:17:25 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *input = NULL;
	while (1)
	{
		input =  readline("\e[1;32m➜ \e[1;34m minishell\e[0m ");
		if (!input)
			break ;
		if (!ft_strcmp(input, "exit"))
			return (free(input), exit(0), 0);
		free(input);
	}
	return 0;
}
