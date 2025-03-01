/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/01 13:54:23 by ybounite         ###   ########.fr       */
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

// t_ASTNode	*split_command(char *command)
// {
// 	t_ASTNode *AST;
// 	int i = 0;
// 	char **command = ft_split(command, ' ');
// 	if(!command)
// 		return ;
// 	while (command[i])
// 	{
// 		AST = new_node(command[i]);
// 		i++;
// 	}
// 	return (AST);
// }
char *get_line()
{
	char *line;

	line =  readline("\e[1;32m➜ \e[1;34m minishell\e[0m ");
	if (line)
		add_history(line);
	printf("%s\n", line);
	return (line);
}
int main()
{
	t_ASTNode *ASTNode;
	t_string input;

	ft_bzero(&input, sizeof(t_string));
	while (1)
	{
		input.line = get_line();
		if (!input.line)
			return (1);
		if (!ft_strcmp(input.line, "exit"))
			return (free(input.line), 0);
	}
	return 0;
}
