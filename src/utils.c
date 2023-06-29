/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-der <avan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 15:10:33 by avan-der      #+#    #+#                 */
/*   Updated: 2023/06/20 13:47:00 by avan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int	is_char_in_set(int c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_tokens(char const *s, const char *delims)
{
	size_t					count;
	int						trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (!is_char_in_set(*s, delims) && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (is_char_in_set(*s, delims))
			trigger = 0;
		s++;
	}
	return (count);
}

char	**ft_split_set(char const *s, const char *delims)
{
	char				**arr;
	size_t				i;
	size_t				j;
	size_t				s_len;
	int					start_token;

	arr = (char **)malloc((count_tokens(s, delims) + 1) * sizeof(char *));
	if (!s || !arr)
		return (NULL);
	i = 0;
	j = 0;
	start_token = -1;
	s_len = ft_strlen(s);
	while (i <= s_len)
	{
		if (!is_char_in_set(s[i], delims) && start_token < 0)
			start_token = i;
		else if ((is_char_in_set(s[i], delims) || i == s_len) && start_token != -1)
		{
			arr[j++] = ft_substr(s, start_token, i - start_token);
			start_token = -1;
		}
		i++;
	}
	arr[j] = '\0';
	return (arr);
}

void	free_double_array_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
