/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:59:08 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/28 16:59:20 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_free(char **list_path)
{
	int i = 0;
	while (list_path[i])
	{
		free(list_path[i]);
		i++;
	}
	free(list_path);
}
