/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/04 13:51:14 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_ASTNode *new_node(char *cmd)
// {
// 	t_ASTNode *newnode;
// 	newnode = malloc(sizeof(t_ASTNode));
// 	if (!newnode)
// 		return NULL;
// 	newnode->value = cmd;
// 	newnode->type = check_type();
// 	newnode->left = NULL;
// 	newnode->right = NULL;
// }
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


t_env_lst	*ft_split_command(t_string *input)
{
	t_env_lst	*head;
	t_env_lst	*new;
	int i;

	i = 1;
	input->command = ft_split(input->line, ' ');
	if(!input->command)
		return (NULL);
	head = creatnew_node(input->command[0]);
	while (input->command[i])
	{
		new = creatnew_node(input->command[i]);
		lstadd_back(&head, new);
		i++;
	}
	return (head);
}

char	*get_line()
{
	char *line;

	line =  readline(MINISPELL);
	if (line)
		add_history(line);
	return (line);
}

void	ft_print_list(t_env_lst *list)
{
	while (list)
	{
		printf("%s", list->value);
		printf(" type : %d\n", list->type);
		list = list->next;
	}
}

int	start_shell_session(t_string input)
{
	t_env_lst	*list;

	while (1)
	{
		input.line = get_line();// this in to rean tin line
		if (!input.line)// sheck if this line is emty
			return (exit(1), 1);
		list = ft_split_command(&input);// return in list of command and spite all command or type
		if (!ft_strcmp(input.line, "exit"))
		{
			printf("exit\n");
			deallocate_env_lst_elem(list);
			free(input.line);
			free_arr(input.command);
			break ;
		}
		exec_cmd(list, &input);
		ft_print_list(list);
		deallocate_env_lst_elem(list);
		free(input.line);
		free_arr(input.command);
	}
	rl_clear_history();
}

int main()
{
	t_env_lst *list;
	t_string input;

	ft_bzero(&input, sizeof(t_string));
	assign_signals_handler();
	start_shell_session(input); //start in shell 
	return 0;
}
