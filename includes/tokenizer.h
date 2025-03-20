/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:23:33 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 22:14:18 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "minishell.h"

typedef struct s_token {
    char *value;
    int type;
    int has_space;
    struct s_token *next;
} t_token;

typedef enum e_token_type {
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_WORD,
	SINGLE_Q,
	DOUBLE_Q,
    TOKEN_PIPE,         // |
    TOKEN_REDIRECT_IN,  // <
    TOKEN_REDIRECT_OUT, // >
    TOKEN_APPEND,       // >>
    TOKEN_HEREDOC,      // <<
    TOKEN_AND,          // &&
    TOKEN_OR            // ||
} t_token_type;

void append_token(t_token **head, t_token *new_token);
t_token *create_token(char *value, t_token_type type, int l_space);

int handle_quotes(const char *input, int *i, t_token **tokens, int *has_space);

void handle_special_tokens(const char *input, int *i, t_token **tokens, int *has_space);

char *handle_double_token(const char *input, int *i);
char *handle_single_token(const char *input, int *i);
char *get_double_redir(const char *input, int *i, int *token_type);
char *get_single_redir(const char *input, int *i, int *token_type);

void handle_word(const char *input, int *i, t_token **tokens, int *has_space);

t_token *tokenize(const char *input);
void free_tokens(t_token *tokens);

#endif