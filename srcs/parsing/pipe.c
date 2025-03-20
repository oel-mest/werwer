/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:34:20 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 01:58:16 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_ast	*handle_syntax_error(t_ast *left, t_ast *node, t_token **tokens)
{
	if (!tokens || !*tokens)
		printf("6minishell: syntax error near unexpected token `newline'\n");
	else
		printf("7minishell: syntax error near unexpected token `%s'\n",
			(*tokens)->value);
	free_ast(left);
	free_ast(node);
	return (NULL);
}

static t_ast	*parse_pipeline_segment(t_token **tokens, int inpar, t_ast *left)
{
	t_ast	*node;
	t_ast	*right;

	node = create_ast_node(NODE_PIPE, inpar);
	*tokens = (*tokens)->next;
	if (!*tokens)
		return (handle_syntax_error(left, node, tokens));
	if (is_special_token(*tokens))
		return (handle_syntax_error(left, node, tokens));
	if ((*tokens)->type == TOKEN_LPAREN)
		right = handle_parentheses(tokens, inpar);
	else
		right = parse_command(tokens, inpar);
	if (!right)
	{
		free_ast(node);
		return (NULL);
	}
	node->left = left;
	node->right = right;
	return (node);
}

t_ast	*parse_pipeline(t_token **tokens, int inpar)
{
	t_ast	*left;
	t_ast	*node;

	left = parse_command(tokens, inpar);
	if (!left)
		return (NULL);
	while (*tokens && (*tokens)->type == TOKEN_PIPE)
	{
		node = parse_pipeline_segment(tokens, inpar, left);
		if (!node)
			return (NULL);
		left = node;
	}
	return (left);
}
