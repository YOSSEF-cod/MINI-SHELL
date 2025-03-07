/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:24 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/06 14:39:23 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_quotes(char quotes)
{
	if (quotes == '\'')
	{
		ft_putendl_fd("minishell: unexpected EOF while looking for matching \'\'\'", 1);
		exit(1);
	}
	else if (quotes == '\"')
	{
		ft_putendl_fd("minishell: unexpected EOF while looking for matching '\"'", 1);
		exit(1);
	}
}
