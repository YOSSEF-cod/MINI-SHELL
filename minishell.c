/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/01 18:27:22 by ybounite         ###   ########.fr       */
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

void	ft_split_command(t_string *input)
{
	t_ASTNode *AST;
	int i = 0;
	input->command = ft_split(input->line, ' ');
	if(!input->command)
		return ;
	while (input->command[i])
	{
		printf("%s\n", input->command[i]);
		i++;
	}
}

char *get_line()
{
	char *line;

	line =  readline("\e[1;32m➜ \e[1;34m minishell\e[0m ");
	if (line)
		add_history(line);
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
		ft_split_command(&input);
		if (!ft_strcmp(input.line, "exit"))
			return (free(input.line), 0);
		ft_free(input.command);
	}
	rl_clear_history();
	return 0;
}
