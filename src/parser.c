/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-der <avan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 14:49:54 by avan-der      #+#    #+#                 */
/*   Updated: 2023/06/29 15:59:36 by avan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command_table	*parser(char **tokens)
{
	t_command_table	*cmd_table;
	int	i;

	cmd_table = malloc(sizeof(t_command_table));
	if (!cmd_table)
		return (NULL);
	cmd_table->simple_cmd = malloc(sizeof(t_simple_command));
	// TODO: check if first token valid command
	i = 0;
	// cmd_table->simple_cmd->cmd = tokens[0];
	// while (tokens[i])
	// {
	// 	if (cmd_table->simple_cmd->cmd == "")
	// 		cmd_table->simple_cmd->cmd = tokens[i];
	// 	printf(">> %s\n", cmd_table->simple_cmd->cmd);
	// 	i++;
	// }
	// TODO: free tokens
}