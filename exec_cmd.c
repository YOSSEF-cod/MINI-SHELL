/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:55:38 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/03 12:29:43 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

char	*find_executable_path(t_exec_cmd	*exec_cmd, t_env_lst *list)
{
	exec_cmd->path = getenv("PATH");
	if (!exec_cmd->path)
	{
		printf("minishell: PATH not found\n");
		return NULL;
	}
	exec_cmd->dirs = ft_split(exec_cmd->path, ':');
	int i = 0;
	while (exec_cmd->dirs[i])
	{
		exec_cmd->full_path = ft_strjoin(exec_cmd->dirs[i], "/");
		if (list->type = CMD)
			exec_cmd->full_path = ft_strjoin(exec_cmd->dirs[i], list->value);
		if (access(exec_cmd->full_path, X_OK) == 0)
		{
			ft_free(exec_cmd->dirs);
			return (exec_cmd->full_path);
		}
		ft_free(exec_cmd->dirs);
		i++;
	}
	ft_free(exec_cmd->dirs);
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
char	**check_flags_in_command(t_env_lst *list)
{
	char	**cmd;

}

void	exec_cmd(t_env_lst *list)
{
	t_exec_cmd	*exec_cmd;
	pid_t		pid;
	char		*cmd_path;

	exec_cmd->cmd_path = find_executable_path(exec_cmd, list);
	exec_cmd->cmd_flags = check_flags_in_command(list);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0) // Process enfant
	{
		if (execve(exec_cmd->cmd_path, exec_cmd->cmd_flags, environ) == -1)
		{
			perror("minishell");
			exit(1);
		}
	}
	else // Process parent
		wait(NULL);
	free(cmd_path);
}
