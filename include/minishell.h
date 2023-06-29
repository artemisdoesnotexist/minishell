/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-der <avan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 12:15:28 by avan-der      #+#    #+#                 */
/*   Updated: 2023/06/22 14:54:22 by avan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data {
	const char	*prompt;
}	t_data;

typedef struct s_simple_command {
	char	*cmd;
	char	*option;
	char	*option2;
}	t_simple_command;

typedef struct s_command_table {
	t_simple_command	*simple_cmd;
	char				*in;
	char				*out;
	char				*err;
}	t_command_table;

// Shell
void	open_shell_interactive(t_data *data);
// void	open_shell_not_interactive(t_data *data);

// Lexer
char	**lexer(char const *line);

// Parser
t_command_table	*parser(char **tokens);

// Utils
char	**ft_split_set(char const *s, const char *delims);
void	free_double_array_char(char **arr);
#endif