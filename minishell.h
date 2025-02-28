/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:49:16 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/28 17:12:44 by ybounite         ###   ########.fr       */
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

typedef enum {
	CMD = 1,
	PIPE = 2,
	OR = 3,
	AND = 4,
	REDIN = 5,
	REDOUT = 6,
	GLOB = 7,
}	NodeType;

typedef struct ASTNode {
	NodeType type;
	char *value;
	struct ASTNode *left;
	struct ASTNode *right;
} t_ASTNode;

void ft_free(char **list_path);

# endif