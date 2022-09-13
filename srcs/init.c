/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:17:04 by jbarette          #+#    #+#             */
/*   Updated: 2022/08/03 16:13:54 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*init(void)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	parser->parser_cmd = NULL;
	parser->parser_opt = 0;
	parser->parser_args = NULL;
	parser->parser_sig = 0;
	parser->parser_count = 0;
	parser->parser_error = 0;
	parser->parser_pwd = NULL;
	parser->parser_arguments = NULL;
	parser->parser_commands = NULL;
	parser->parser_count_arg = 0;
	parser->parser_count_cmd = 0;
	return (parser);
}

t_env	*init_env(void)
{
	t_env		*env;
	t_element	*element;

	env = malloc(sizeof(*env));
	element = malloc(sizeof(element));
	if (env == NULL || element == NULL)
		exit(EXIT_FAILURE);
	element->value = NULL;
	element->next = NULL;
	env->first = element;
	return (env);
}

void	free_parser(t_parser *parser)
{
	free(parser->parser_cmd);
	free(parser->parser_args);
	free(parser->parser_arguments);
	free(parser->parser_commands);
	free(parser);
}
