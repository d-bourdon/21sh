/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:43:17 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/08 11:44:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	autocomplete(char *line, char *c, size_t *cur_pos)
{
	(void)line;
	(void)cur_pos;
	if (c[0] == '\t' && c[1] == 0)
		;
}
