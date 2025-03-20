/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:31:03 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 01:57:40 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_ast(t_ast *ast)
{
	if (!ast)
		return;
	free_ast(ast->left);
	free_ast(ast->right);
	if (ast->cmd)
		free_cmd(ast->cmd);
	if (ast->type == NODE_SUB)
		free_redi(ast->redi);
	free(ast);
}
