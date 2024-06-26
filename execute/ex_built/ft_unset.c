/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:39:45 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:25:02 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_isdigit(char c)
{
	return (c >= 0 && c <= 9);
}

void	unset_env(char *args, t_env *env)
{
	t_env_elem	*elem;

	elem = NULL;
	if (args && !ft_isalpha(args[0]))
	{
		printf("minishell: unset: `%s`: not a valid identifier\n",
			args);
		g_data.exit_status = EXIT_FAILURE;
	}
	else
	{
		elem = search_env_elem(env, args);
		if (elem)
			del_env_elem(env, elem);
	}
}

int	ft_unset(t_cmd *cmd, char ***ev)
{
	t_env	*env;
	int		i;
	int		j;

	i = 1;
	j = 0;
	env = NULL;
	env = create_env(*ev);
	g_data.exit_status = EXIT_SUCCESS;
	while (cmd->args[i])
	{
		unset_env(cmd->args[i], env);
		i++;
	}
	*ev = convert_array(env);
	del_env(env);
	return (g_data.exit_status);
}
