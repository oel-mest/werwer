/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:39:52 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 02:14:26 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *read_input(void)
{
    char *line = NULL;

	line = readline(">>");
    if (!line) {
        free(line);
        return NULL;
    }
    return (line);
}
void    check_leaks()
{
    system("leaks minishell");
}

int main(int argc, char *argv[], char *envp[])
{ 
    atexit(check_leaks);
    t_envnode *head = parse_envp(envp);
	(void)argc;
	(void)argv;
    printf("Minishell by oussama\n");
    char *line = read_input();
	while(line != NULL)
	{
        add_history(line);
		t_token *tokens = tokenize(line);
        if (tokens != NULL)
        {
            print_tokens(tokens);
            t_ast *ast = parse(tokens);
            free_tokens(tokens);
            free(line);
            if (ast != NULL)
            {
                print_ast_tree(ast, head);
                free_ast(ast);
            }
        }
        free_env_list(head);
		line = NULL;
	}
    return EXIT_SUCCESS;
}