/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:44:50 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/04 13:59:32 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	(void)signum;
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	assign_signals_handler()
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
}