/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:55:38 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/04 13:43:47 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

char *find_executable_path(t_exec_cmd *exec_cmd, t_env_lst *list)
{
	int i = 0;
	exec_cmd->path = getenv("PATH");
	if (!exec_cmd->path)
		return (printf("minishell: PATH not found\n"), NULL);
	exec_cmd->dirs = ft_split(exec_cmd->path, ':');
	while (exec_cmd->dirs[i]) 
	{
		exec_cmd->full_path = ft_strjoin(exec_cmd->dirs[i], "/");
		if (list->type == CMD)
		{
			exec_cmd->full_path = ft_strjoin(exec_cmd->full_path, list->value);
			printf("%s\n", exec_cmd->full_path);
			if (access(exec_cmd->full_path, X_OK) == 0)
				return (free_arr(exec_cmd->dirs), exec_cmd->full_path);
		}
		free(exec_cmd->full_path);
		i++;
	}
	return (free_arr(exec_cmd->dirs), NULL);
}

char	*get_path()
{
	char *path = getenv("PATH"); // Get PATH
	if (!path)
	{
		printf("minishell: PATH not found\n");
		return NULL;
	}
	return path;
}

int	exec_cmd(t_env_lst *list, t_string *string)
{
	t_exec_cmd	*exec_cmd;
	pid_t		pid;

	exec_cmd = malloc(sizeof(t_exec_cmd));
	if (!exec_cmd)
		return (perror("malloc failed"), 1);
	exec_cmd->cmd_path = find_executable_path(exec_cmd, list);
	if (!exec_cmd->cmd_path)
		return ( printf("minishell: command not found %s\n",string->command[0]), free(exec_cmd), 1);  // Free exec_cmd if no path was found
	pid = fork();
	if (pid == -1)
		return (perror("fork"), free(exec_cmd), 1);
	if (pid == 0)
	{

		if (execve(exec_cmd->cmd_path, string->command, environ) == -1)
			return (perror("minishell"), exit(1), 1);
	}
	else
		wait(NULL);
	free(exec_cmd->cmd_path);
	free(exec_cmd);
	return (0);
}
