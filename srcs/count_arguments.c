/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:17:40 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/24 15:17:02 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

/*
** @param: The string to count its number of arguments
** @return: The number of arguments inside the string
** @desc: This function counts the number of arguments present inside a string
*/

unsigned int	count_arguments(char *command_line)
{
	unsigned int	number_of_arguments;
	int				current_quote;
	int				i;

	number_of_arguments = 0;
	current_quote = 0;
	i = 0;
	while (command_line[i] != '\0')
	{
		if (command_line[i] == current_quote)
			current_quote = 0;
		else if (is_quote(command_line[i]) && current_quote == 0
				&& (i > 0 ? command_line[i] != '\\' : 1))
		{
			current_quote = command_line[i];
			number_of_arguments += 1;
		}
		else if (!ft_isspace(command_line[i]) && current_quote == 0 &&
				is_unescaped_quote(i, command_line) && command_line[i] != '\\')
			number_of_arguments += 1;
		i += 1;
	}
	return (number_of_arguments);
}
