/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealocate_sdata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:44:10 by ybounite          #+#    #+#             */
/*   Updated: 2025/03/03 13:51:29 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// deallocate_env_lst_elem
// deallocate_cmd_list

void	deallocate_env_lst_elem(t_env_lst *list)
{
	t_env_lst *ptr;
	ptr = list;
	while (ptr)
	{
		ptr = list->next;
		free(list);
		list = ptr;
	}
	free(list);
}


// void	deallocate_sdata(t_sdata *sdata)
// {
// 	deallocate_cmd_list(sdata->f_cmds);
// 	free_arr(sdata->env);
// 	free_arr(sdata->bin_paths);
// 	deallocate_env_lst(sdata->env_lst);
// 	close(sdata->save_stdin);
// 	close(sdata->save_stdout);
// }