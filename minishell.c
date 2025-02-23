/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/23 14:45:21 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main() {
    char *input = NULL;  // Pointer to store user input
	while (1)
	{
		ft_putstr_fd("➜ minishell ", 1);
		input = get_next_line(0);
		if (!input)
			break ;
		printf("You entered: %s", input);
		free(input);
	}
	return 0;
}
