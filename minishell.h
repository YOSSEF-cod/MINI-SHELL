/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:49:16 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/03 14:51:51 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>

# define YELLOW	"\e[1;33m"
# define RED     "\e[1;31m"
# define GREEN   "\e[1;32m"
# define BLUE    "\e[1;34m"
# define WHITE   "\e[1;37m"
# define MINISPELL "\e[1;32m➜ \e[1;34m minishell\e[0m "
// "\001\e[1;38;5;141m\002[minispell]\001\e[1;33m\002 > \001\033[0m\002"

typedef enum {
	CMD = 1, //command 
	PIPE = 2, // |
	OR = 3, // ||
	AND = 4, // && 
	REDIN = 5, // <
	REDOUT = 6, // >
	GLOB = 7, //*
	BACKGROUND, // ;
}	enNodeType;

typedef struct	s_environement_list
{
	enNodeType			type;
	char				*value;
	struct	s_environement_list		*next;
}	t_env_lst;

typedef struct s_string
{
	char	*line;
	char	**command;
	int		exit_status;
}	t_string;

typedef struct s_exec_cmd
{
	char	*full_path;
	char	*path;
	char	**dirs;
	pid_t	pid;
	char	*cmd_path;
	char	**cmd_flags;
}	t_exec_cmd;

/* -------------------------------------------------------------------------- */
/*                       FILE 	=	ft_lestnew.c                           	  */
/* -------------------------------------------------------------------------- */
void		lstadd_back(t_env_lst **head, t_env_lst *new);
t_env_lst	*creatnew_node(char *cmd);
enNodeType	check_type_value(char *cmd);


int			exec_cmd(t_env_lst *list, t_string *string);

/* -------------------------------------------------------------------------- */
/*                       FILE 	=	free_arr.c                            	  */
/* -------------------------------------------------------------------------- */
void		free_arr(char **arr);

/* -------------------------------------------------------------------------- */
/*                               FILE = dealocate_sdata.c                     */
/* -------------------------------------------------------------------------- */
void		deallocate_env_lst_elem(t_env_lst *list);

# endif