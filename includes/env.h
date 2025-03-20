/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:51:40 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 02:03:18 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

typedef struct s_envnode {
	char				*var;
	char				*value;
	struct s_envnode	*next;
}	t_envnode;

char    *ft_getenv(char *name, t_envnode *head);
t_envnode *parse_envp(char **envp);

char	*expand_env_vars(char *args, t_envnode *env_list);

char    *handle_lstatus_var();
#endif