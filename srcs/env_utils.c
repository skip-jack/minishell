/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <pcatrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:05:08 by pcatrina          #+#    #+#             */
/*   Updated: 2020/11/23 13:24:18 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*find_env(t_list **env_dup, char *str)
{
	t_list	*tmp;
	t_env	*env;

	tmp = *env_dup;
	while (tmp)
	{
		env = tmp->content;
		if (!(ft_strcmp((const char *)env->env_name, str)))
			return (env->env_cont);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env		*find_env1(t_list **env_dup, char *str)
{
	t_list	*tmp;
	t_env	*env;

	tmp = *env_dup;
	while (tmp)
	{
		env = tmp->content;
		if (!(ft_strcmp((const char *)env->env_name, str)))
			return (env);
		tmp = tmp->next;
	}
	return (NULL);
}

t_env		*env_to_cont(char *env)
{
	t_env	*var;
	char 	*tmp;

	var = (t_env *)malloc(sizeof(t_env));
	tmp = ft_strchr(env, '=');
	var->env_name = ft_substr(env, 0, tmp - env);
	var->env_cont = ft_substr(env, tmp - env + 1, ft_strlen(env));
	return (var);
}

t_list		*dub_env(char **env)
{
	t_list	*env_dup;
	int		i;

	i = -1;
	env_dup = NULL;
	while (env[++i])
		ft_lstadd_back(&env_dup, ft_lstnew(env_to_cont(env[i])));
	return (env_dup);
}

void		test_env_list(t_list **env_dup)
{
	t_list	*tmp;
	t_env	*env;

	tmp = *env_dup;
	while (tmp)
	{
		env = tmp->content;
		ft_putstr_fd((env->env_name), 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd((env->env_cont), 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}
