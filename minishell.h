/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:49:16 by ybounite          #+#    #+#             */
/*   Updated: 2025/04/05 11:07:51 by ybounite         ###   ########.fr       */
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

extern char **environ;

typedef enum {
	CMD = 1, //command 
	PIPE = 2, // |
	OR = 3, // ||
	AND = 4, // && 
	REDIN = 5, // <
	REDOUT = 6, // >
	GLOB = 7, //*
	BACKGROUND, // ;
	BUILTINS, // echo -n cd pwd export unset env exit
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

/* -------------------------------------------------------------------------- */
/*                       FILE 	=	ft_mysplit.c                              */
/* -------------------------------------------------------------------------- */
char	**ft_spliter(char *str);

/* -------------------------------------------------------------------------- */
/*                       FILE 	=	exec_cmd.c                           	  */
/* -------------------------------------------------------------------------- */
int			send_to_exec(t_env_lst *list, t_string *string);

/* -------------------------------------------------------------------------- */
/*                               FILE = handler_quotes.c                      */
/* -------------------------------------------------------------------------- */
char		*ft_splitquotes(char *str);
int			ft_calcule_dquotes(char *str);
int			ft_calcule_quotes(char *str);
/* -------------------------------------------------------------------------- */
/*                               FILE = manage_signal.c                       */
/* -------------------------------------------------------------------------- */
void		assign_signals_handler();

/* -------------------------------------------------------------------------- */
/*                       FILE 	=	check_type.c                          	  */
/* -------------------------------------------------------------------------- */
int			check_is_builtins(char *cmd);
enNodeType	check_type_value(char *cmd);


/* -------------------------------------------------------------------------- */
/*                       FILE 	=	ft_error.c                            	  */
/* -------------------------------------------------------------------------- */
void		ft_error_quotes(char quotes);

/* -------------------------------------------------------------------------- */
/*                       FILE 	=	free_arr.c                            	  */
/* -------------------------------------------------------------------------- */
void		free_arr(char **arr);
void	print_cmd(char **cmd);
/* -------------------------------------------------------------------------- */
/*                               FILE = dealocate_sdata.c                     */
/* -------------------------------------------------------------------------- */
void		deallocate_env_lst_elem(t_env_lst *list);

# endif