/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:40:18 by ybounite          #+#    #+#             */
/*   Updated: 2025/04/05 11:11:38 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	builtins_command(t_env_lst *list)
// {
// 	if (list->type == BUILTINS)
// 	{
// 		if (!ft_strcmp(list->value, "echo"))
// 			send_echo_command(list->next);
// 	}	
// }

// char **splter(char *str)
// {

// }

t_env_lst	*ft_split_command(t_string *input)
{
	t_env_lst	*head;
	t_env_lst	*new;
	int i;

	i = 1;
		input->command = ft_split(input->line, '|');
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
	if (!line)
	{
		perror("Error\n");
		exit(1);
	}
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

void	send_echo_command(t_env_lst *list)
{
	int check = 0;
	while (list && list->type == CMD)
	{
		if (check == 1)
			printf(" ");
		printf("%s", list->value);
		check = 1;
		list = list->next;
	}
	printf("\n");
}

int	start_shell_session(t_string input)
{
	t_env_lst	*list;

	while (1)
	{
		input.line = get_line();// this in to rean tin line
		input.command = ft_spliter(input.line); // return in list of command and spite all command or type
		if (!ft_strcmp(input.line, "exit"))
		{
			printf("exit\n");
			// deallocate_env_lst_elem(list);
			free(input.line);
			free_arr(input.command);
			break ;
		}
		// builtins_command(list);
		// send_to_exec(list, &input);
		// ft_print_list(list);
		// deallocate_env_lst_elem(list);
		// free(input.line);
		// free_arr(input.command);
		print_cmd(input.command);
	}
	rl_clear_history();
	return (0);
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
