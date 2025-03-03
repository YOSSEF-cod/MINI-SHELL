/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:59:08 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/03 13:21:04 by ybounite         ###   ########.fr       */
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

void	ft_free_linklist(t_env_lst *list)
{
	t_env_lst *ptr;
	ptr = list;
	while (ptr)
	{
		ptr = list->next;
		free(list);
		list = ptr;
	}
}
