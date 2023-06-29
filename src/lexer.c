/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-der <avan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 13:07:12 by avan-der      #+#    #+#                 */
/*   Updated: 2023/06/22 14:50:49 by avan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// TODO: Deal with paraentheses
char	**lexer(char const *line)
{
	char **tokens;

	tokens = ft_split_set(line, " \t\r\n");
	parser(tokens);
	if (!tokens)
		exit(0);
	return (tokens);
}