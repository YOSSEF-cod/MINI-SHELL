/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:55:38 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/03 09:27:20 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command_path(char cmd)
{

}

char	*get_path()
{
	char	*path;

	path = getenv("PATH"); // Jib PATH
	if (!path)
	{
		printf("minishell: PATH not found\n");
		return (NULL);
	} 
	return (path);
}

void	exec_cmd(char **args)
{
	t_exec_cmd	exec_cmd;
	
	exec_cmd.cmd_path = find_command_path(args[0]); 
}
