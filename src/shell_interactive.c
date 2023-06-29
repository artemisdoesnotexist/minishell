/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell_interactive.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-der <avan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 12:23:14 by avan-der      #+#    #+#                 */
/*   Updated: 2023/06/19 14:12:55 by avan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_shell_interactive(t_data *data)
{
	char	*line;
	char	**args;
	
	printf("%s\n", data->prompt);
	// TODO: read line from stdin
	// TODO: tokenize line
}