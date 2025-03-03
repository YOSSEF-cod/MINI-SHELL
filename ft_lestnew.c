/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lestnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:37:06 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/03 13:39:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_lst	*creatnew_node(char *cmd)
{
	t_env_lst *new;

	new = malloc(sizeof(t_env_lst));
	if (!new)
		return (NULL);
	new->value = cmd;
	new->type = check_type_value(cmd);
	new->next = NULL;
	return (new);
}

void	lstadd_back(t_env_lst **head, t_env_lst *new)
{
	t_env_lst *ptr;

	if (!head || !new)
		return ;
	if (!head)
	{
		ptr = new;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
