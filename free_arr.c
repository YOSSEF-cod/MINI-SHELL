/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:47:41 by ybounite          #+#    #+#             */
/*   Updated: 2025/04/05 11:10:14 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}
void	print_cmd(char **cmd)
{
	int i = 0;
	while (cmd[i])
	{
		printf("%s\n", cmd[i]);
		i++;
	}
	
}