/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:49:16 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/02 16:49:40 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

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

void ft_free(char **list_path);

# endif