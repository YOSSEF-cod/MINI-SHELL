/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:44 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/08 08:35:54 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **split_command(char *cmd);
void free_tokens(char **tokens);

int	ft_isspace(char c)
{
	return (c == ' ');
}

int ft_isquotes(char c)
{
	return (c == '\'' || c == '\"');
}
void	ft_skipespase(char *cmd, int *i)
{
	while (ft_isspace(cmd[*i]))
		(*i)++;
}

// int	count_tokens(char *str)
// {
// 	int (i), (count);
// 	i = 0;
// 	count = 0;
	
// 	while (str[i])
// 	{
// 		ft_skipespase(str, &i);
// 		if (str[i] == '\0')
// 			break;
// 		count++;
// 		if (str[i] == '"' || str[i] == '\'')
// 		{
// 			i++;
// 			while (str[i])
// 			{
// 				if ((str[i] == '\\' && str[i + 1] == '"') || (str[i] == '\\' && str[i + 1] == '\''))
// 					i += 2;
// 				else if (str[i] == '"')
// 				{
// 					i++;
// 					break ;
// 				}
// 				else
// 					i++;
// 			}
// 		}else
// 			while (str[i] != ' ' && str[i] != '\'' && str[i] != '\"' && str[i])
// 				i++;
// 	}
// 	return (count);
// }

int count_tokens(char *cmd)
{
	int (count), (i);
	count = 0;
	i = 0;
	while (cmd[i])
	{
		ft_skipespase(cmd, &i);
		if (cmd[i] == '\0')
			break;  // Exit if end of string
		count++;  // Start a new token
		if (cmd[i] == '"' || cmd[i] == '\'')
		{
			i++;
			while (cmd[i] != '\0')
			{
				if ((cmd[i] == '\\' && cmd[i + 1] == '"') || (cmd[i] == '\\' && cmd[i + 1] == '"'))
					i += 2;  // Skip escaped quote
				else if (cmd[i] == '"')
				{
					i++;
					break ;
				}
				else
					i++;
			}
		} else // Skip non-quoted content
			while (cmd[i] != '\0' && !isspace(cmd[i]) && (cmd[i] != '"'))
				i++;
	}
	return count;
}

int main()
{
    char *command = "echo \"hello world\" hes' word'two";
    char **tokens = split_command(command);

	printf("%d", count_tokens(command));
    printf("Count: %d\n", count_tokens(command));
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token[%d]: '%s'\n", i, tokens[i]);
    }
    free_tokens(tokens);
    return 0;
}
// char	**parse_command(char *str)
// {
// 	char	**ptr;
// 	int		len;
	
// 	len = ft_len(str);
// 	ptr = malloc(len + 1);
// 	int i = 0;
// 	while (i < len)
// 	{
		
// 		i++;
// 	}
	
// 	printf ("%d", len);
// }


// void parse_command(const char *cmd)
// {
//     int in_quote = 0;  // Flag to check if inside quotes
//     char token[256];   // Buffer for each token
//     int j = 0;

//     for (int i = 0; cmd[i] != '\0'; i++)
// 	{
//         if (cmd[i] == '"' || cmd[i] == '\'')
//             in_quote = !in_quote;  // Toggle the in_quote flag
//         else if (isspace(cmd[i]) && !in_quote)
// 		{
//             if (j > 0)
// 			{
//                 token[j] = '\0';
//                 printf("Token: %s\n", token);
//                 j = 0;
//             }
//         } else
//             token[j++] = cmd[i];
//     }

//     // Last token
//     if (j > 0)
// 	{
//         token[j] = '\0';
//         printf("Token: %s\n", token);
//     }
// }
// int count_tokens(const char *cmd) {
//     int count = 0, in_quote = 0, i = 0;

//     while (cmd[i] != '\0') {
//         while (isspace(cmd[i])) i++;  // Skip spaces

//         if (cmd[i] == '"') in_quote = !in_quote;  // Toggle quotes

//         if (cmd[i] != '\0' && (in_quote || !isspace(cmd[i]))) {
//             count++;  // Only count once when token starts

//             // Move to the end of the token
//             while (cmd[i] != '\0' && (in_quote || !isspace(cmd[i]))) {
//                 if (cmd[i] == '"') in_quote = !in_quote;  // Toggle quotes inside token
//                 i++;
//             }
//         }
//     }
//     return count;
// }





// Count tokens based on spaces and escaped quotes


// Split the command into tokens
char **split_command(char *cmd) {
    int token_count = count_tokens(cmd);
    char **tokens = malloc((token_count + 1) * sizeof(char *));
    char buffer[256];
    int i = 0, j = 0, token_index = 0;
    int in_quote = 0;

    while (cmd[i] != '\0') {
        while (isspace(cmd[i])) i++;  // Skip spaces

        if (cmd[i] == '\0') break;  // Exit if end of string

        j = 0;  // Reset buffer index
        if (cmd[i] == '"') {
            in_quote = 1;  // Inside quote
            i++;  // Skip the opening quote
            while (cmd[i] != '\0') {
                if (cmd[i] == '\\' && cmd[i+1] == '"')
				{
                    buffer[j++] = '"';  // Add escaped quote
                    i += 2;  // Skip the backslash and quote
                } else if (cmd[i] == '"') {
                    in_quote = 0;  // End of quote
                    i++;
                    break;
                } else {
                    buffer[j++] = cmd[i++];  // Copy normal character
                }
            }
        } else {
            // Normal token (no quotes)
            while (cmd[i] != '\0' && !isspace(cmd[i]) && cmd[i] != '"') {
                buffer[j++] = cmd[i++];
            }
        }
        buffer[j] = '\0';  // Null-terminate the token
        tokens[token_index++] = strdup(buffer);  // Store the token
    }

    tokens[token_index] = NULL;  // Mark the end of the array
    return tokens;
}

void free_tokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}




// int main() {
//    char *command = "echo \"hello world\" \"hes word two\"";
//     // parse_command(command);
// 	printf("%d\n", count_tokens(command));
//     return 0;
// }

// int main()
// {
// 	printf ("%d", ft_len("echo \"hello world \'\""));
// }