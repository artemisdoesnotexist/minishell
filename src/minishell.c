/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-der <avan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/16 10:33:10 by avan-der      #+#    #+#                 */
/*   Updated: 2023/06/22 14:51:26 by avan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*------------FLOW-----------*/
// TODO: Lexer
// [ ]: Tokenize input command
// TODO: Parser
// [ ]: Create command table
// TODO: Expander
// [ ]: Wildcard globbing
// [ ]: Pipe + redirection handler
// TODO: Executor
// [ ]: Execute command
// [ ]: Display output

/*-----------FEATURES----------*/
// [x]: Implement prompt
// [ ]: Implement history
// [ ]: Search and launch right executable
// [ ]: Handle single quotes
// [ ]: Handle double quotes
// [ ]: Implement redirections
//  [ ]: Imlement >
//  [ ]: Imlement <
//  [ ]: Imlement >>
//  [ ]: Imlement <<
// [ ]: Implement pipes
// [ ]: Handle environment variables
// [ ]: Handle $?
// [ ]: Handle signals
//  [ ]: ctrl-C
//  [ ]: ctrl-D
//  [ ]: ctrl-\
// [ ]: Implement interactive mode
// [ ]: Implement buildins
// 	[ ]: echo
//  [ ]: cd
//  [ ]: pwd
//  [ ]: export
//  [ ]: unset
//  [ ]: env
//  [ ]: exit

void	init_data(t_data *data)
{
	data->prompt = "[minishell]: ";
}

int	main(void)
{
	t_data	data;
	char	*line;
	char	**tokens;

	init_data(&data);
	while (1)
	{
		line = readline(data.prompt);
		if (!line)
			exit(0);
		tokens = lexer(line);
		free(line);
	free_double_array_char(tokens);
	}
	// if (isatty(STDIN_FILENO) == 1)
	// 	open_shell_interactive(&data);
	// else
	// 	open_shell_not_interactive();
	return (0);
}

