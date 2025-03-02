/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/02 16:55:26 by ybounite         ###   ########.fr       */
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
	else
		return (CMD);
}

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

t_env_lst	*ft_split_command(t_string *input)
{
	t_env_lst *head;
	t_env_lst *new;
	int i = 1;
	input->command = ft_split(input->line, ' ');
	if(!input->command)
		return NULL;
	head = creatnew_node(input->command[0]);
	while (input->command[i])
	{
		new = creatnew_node(input->command[i]);
		lstadd_back(&head, new);
		i++;
	}
	return (head);
}

char *get_line()
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

int main()
{
	t_env_lst *list;
	t_string input;

	ft_bzero(&input, sizeof(t_string));
	while (1)
	{
		input.line = get_line();
		if (!input.line)
			return (1);
		list = ft_split_command(&input);
		if (!ft_strcmp(input.line, "exit"))
			return (free(input.line), 0);
		ft_print_list(list);
		ft_free(input.command);
	}
	rl_clear_history();
	return 0;
}
