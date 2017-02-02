/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:37:00 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/02 17:57:08 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

static char		*repl_envfree(char *src, char *start, int len, t_env *env)
{
	int		i;
	int		j;
	char	*out;
	char	*src2;

	i = 0;
	src2 = ft_strdup(src);
	free (src);
	j = ft_strlen(src2) - ft_strlen(start);
	out = ft_strndup(src2, j);
	if (env)
		out = ft_strjoinfree(out, env->value, 1);
	if (src2[j + len] == '\\')
		len += 1;
	out = ft_strjoinfree(out, src2 + (j + len), 1);
	return (out);
}

static int		chr_repl_env(char *str)
{
	int		out;

	out = 0;
	while (ft_isalnum(str[out]) || str[out] == '_')
		out++;
	return (out);
}

char	**ft_replace_env(char **out, int *i)
{
	t_env	*tmp;
	t_info	*info;
	char	*str;
	int		len;

	tmp = NULL;
	info = singleton(NULL);
	if (!out[*i] || (str = ft_strstr(out[*i], "$")) == NULL)
		return (out);
	len = chr_repl_env(str + 1);
	str = ft_strndup(str + 1, len);
	tmp = ft_env_chr(info->env, str);
	str = ft_strstr(out[*i], "$");
	out[*i] = repl_envfree(out[*i], str, len + 1, tmp);
	return (out);
}

t_cmd	*ft_line_parse(char *str)
{
	t_cmd	*out;
	int		n[2];
	int		quote;

	ft_bzero(n, sizeof(n));
	out = NULL;
	while (str[n[0] - ((n[0] < 1)? 0 : 1)])
	{
		if (str[n[0]] == '\"' || str[n[0]] == '\'')
		{
			quote = n[0]++;
			while (str[n[0]] && str[n[0]] != str[quote])
				n[0]++;
			if (!str[n[0]])
				return (out);
		}
		if (str[n[0]] == ';' || !str[n[0]])
		{
			if (n[1] != n[0])
				ft_line_exploit(str, n[1], n[0], &out);
			n[1] = n[0] + 1;
		}
		n[0]++;
	}
	return (out);
}

void	ft_line_exploit(char *str, int start, int i, t_cmd **out)
{
	t_cmd	*list;
	t_cmd	*ok;
	char	*tmp;
	char	**tb;

	if ((tmp = (char*)ft_memalloc(sizeof(char) * (i - start) + 1)) == NULL)
		return ;
	tmp = ft_strncpy(tmp, str + start, i - start);
	tb = ft_strsplitwq(tmp);
	free(tmp);
	if ((ok = (t_cmd*)ft_memalloc(sizeof(t_cmd))) == NULL)
		return ;
	ok->av = tb;
	ok->pipe = 0;
	ok->opipe = NULL;
	ok->next = NULL;
	if (*out == NULL)
		*out = ok;
	else
	{
		list = *out;
		while (list && list->next)
			list  = list->next;
		list->next = ok;
	}
}
