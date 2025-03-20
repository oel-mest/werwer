/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:29:34 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 01:33:07 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "minishell.h"

void free_cmd(t_cmd *cmd);
void free_ast(t_ast *node);
void	free_tokens(t_token *tokens);
void	free_env_list(t_envnode *env_list);
void	free_redi(t_redi *redi);
void	free_output_list(t_output *output_list);

#endif