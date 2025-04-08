# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
#include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
#include "libft/libft.h"
// ls|grep
bool	find_space(char c);

bool is_operator(char c)
{
	return (c == '&' || c == '|' || c == '>' || c == '<');
}
bool	find_space(char c)
{
	return (c == SPACE || c == TAB || c == NEWLINE);
}
void	ft_skip_whitespace(char *str, int *index)
{
	while (str[*index] && find_space(str[*index]))
		(*index)++;
}
bool isquotes(char c)
{
	return (c == '\'' || c == '\"');
}
int	skip_strqoutes(char *str, int *inedx, char quotes)
{
	int counter;

	counter = 0;
	while (str[*inedx] && str[*inedx] != quotes)
	{
		(*inedx)++;
		counter++;
	}
	if (str[*inedx] && str[*inedx] == quotes){
		(*inedx)++;
		counter++;
	}
	return (counter);
}
int	skip_word(char *str, int *i)
{
	int count_word;

	count_word = 0;
	if (*i - 1 > 0 && find_space(str[*i - 1]))
		count_word++;
	while (str[*i] && !is_operator(str[*i]) && !isquotes(str[*i]))
	{
		(*i)++;
		count_word++;
	}
	return (count_word);
}
int	skip_operator(char *str, int *index, char operator)
{
	int	count_operator;

	count_operator = 0;
	while (str[*index] && str[*index] == operator)
	{
		(*index)++;
		count_operator++;
	}
	// if (count_operator > 2)
	// Error fom operation (operator);// and free all aloction 
	// if (str[*index] && !find_space(str[*index]))
	// 	count_operator++;
	return (count_operator);
}

int	ft_lenword(char *str, int s)
{
	int (len), i,opt = 0, qout = 0, addspace = 0;
	char quotes;
	char operator;
	len = 0;
	i = 0;
	while (str[i])
	{
		ft_skip_whitespace(str, &i);
		if (str[i] && isquotes(str[i]))
		{
			if (i - 1 > 0 && find_space(str[i - 1]))
				addspace++;
			quotes = str[i++];
			qout++;// quotes
			qout += skip_strqoutes(str, &i, quotes);
		}
		else if (str[i] && is_operator(str[i])){
			addspace++;
			operator = str[i];
			while (str[i] && str[i] == operator)
			{
				opt++;
				i++;
			}
			if (str[i] && !find_space(str[i]))
				addspace++;
		}
		else
		{
			while (str[i] && !is_operator(str[i]) && !isquotes(str[i]) && !find_space(str[i]))
			{
				if (i - 1 > 0 && find_space(str[i - 1]))
					addspace++;
				i++;
				len++;
			}
		}
	}
	if (s == 1){
	printf("qoutes : %d\n", qout);
	printf("operatoe : %d\n", opt);
	printf("word : %d\n", len);
	printf("space : %d\n", addspace);
	}
	return (len+qout+opt+addspace);
}

char *strdup_addespace(char *str)
{
	char *ptr = malloc(100);
	int i = 0;
	int index = 0;
	char operator;
	char quots;
	while (str[i])
	{
		ft_skip_whitespace(str, &i);
		// handler quotes 
		if (str[i] && isquotes(str[i])){
			if (i - 1 > 0 && find_space(str[i - 1]))
				ptr[index++] = SPACE;
			quots = str[i];
			ptr[index++] = str[i++];
			while (str[i] && str[i] != quots)
				ptr[index++] = str[i++];
			ptr[index++] = str[i++];
		}// handler operatoin 
		else if (str[i] && is_operator(str[i]))
		{
			ptr[index++] = SPACE;
			operator = str[i];
			while (str[i] && str[i] == operator)
			{
				ptr[index++] = str[i++];
				// calcal_howMayOperator();//and exit if mor 2;
			}
			if (str[i] && !find_space(str[i]))
				ptr[index++] = SPACE;
		}// handler word 
		else{
			if (i - 1 > 0 && find_space(str[i - 1]))
				ptr[index++] = SPACE;
			ptr[index++] = str[i++];
		}
	}
	return ptr;
}

int main()
{
	char *len = "ls -la | greptest ||		wc -l>file";//readline("Enter : ");
	char *str = strdup_addespace(len);
	printf("%s\n", str);
	ft_lenword(len, 1);
	printf("lent reual : %lu\n strlen    : %d", strlen(str), ft_lenword(len, 0));
}