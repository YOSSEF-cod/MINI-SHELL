/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:36:54 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/06 11:47:44 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_builtins(char *cmd)
{
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "exit"));
}

enNodeType	check_type_value(char *cmd)
{
	if (!ft_strcmp(cmd, "|"))
		return (PIPE);
	else if (!ft_strcmp(cmd, "||"))
		return (OR);
	else if (!ft_strcmp(cmd, "&&"))
		return (AND);
	else if (!ft_strcmp(cmd, "<"))
		return (REDIN);
	else if (!ft_strcmp(cmd, ">"))
		return (REDOUT);
	else if (!ft_strcmp(cmd, "*"))
		return (GLOB);
	else if (!ft_strcmp(cmd, ";"))
		return (BACKGROUND);
	else if (check_is_builtins(cmd))
		return (BUILTINS);
	else
		return (CMD);
}
