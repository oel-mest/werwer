/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:25:09 by oel-mest          #+#    #+#             */
/*   Updated: 2025/03/20 02:17:51 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char *append_char(char *str, char c)
{
    char    mystr[2];
    char *new_str;

    mystr[0] = c;
    mystr[1] = 0;
    new_str = ft_strjoin(str, mystr);
    free(str);
    return (new_str);
}



static char *handle_var_expansion(char *args, int *i, t_envnode *env_list)
{
    char *result;
    int start;
    char *var_name;

    result = NULL;
    if (args[*i] == '?')
    {
        (*i)++;
        result = handle_lstatus_var();
    }
    else if (isalnum(args[*i]) || args[*i] == '_')
    {
        start = *i - 1;
        while (args[*i] && (isalnum(args[*i]) || args[*i] == '_'))
            (*i)++;
        var_name = strndup(args + start, *i - start);
        result = ft_getenv(var_name, env_list);
        free(var_name);
    }
    else
        result = ft_strdup("$");
    return result;
}

static void	update_quotes(char c, int *in_single_quote, int *in_double_quote)
{
	if (c == '\'' && !(*in_double_quote))
		*in_single_quote = !(*in_single_quote);
	if (c == '"' && !(*in_single_quote))
		*in_double_quote = !(*in_double_quote);
}

static char	*process_dollar(const char *args, int *i, char *result,
								t_envnode *env_list)
{
	char	*var_value;
	char	*new_result;

	(*i)++;
	var_value = handle_var_expansion((char *)args, i, env_list);
	if (var_value)
	{
	    new_result = ft_strjoin(result, var_value);
		free(result);
		free(var_value);
		return (new_result);
	}
	return (result);
}

char	*expand_env_vars(char *args, t_envnode *env_list)
{
	char	*result;
	int		i;
	int		in_single_quote;
	int		in_double_quote;

	result = malloc(1);
	i = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	if (!args || !result)
		return (free(result), NULL);
	result[0] = '\0';
	while (args[i])
	{
		update_quotes(args[i], &in_single_quote, &in_double_quote);
		if (args[i] == '$' && !in_single_quote)
			result = process_dollar(args, &i, result, env_list);
		else
			result = append_char(result, args[i++]);
	}
	return (result);
}