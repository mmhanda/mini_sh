/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:31:20 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:24:49 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_cmd *cmd, char **env)
{
	int	i;

	i = 0;
	if (!cmd->args[1])
	{
		while (env[i])
		{
			if (ft_strchr(env[i], '=') != -1)
				printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		g_data.exit_status = EXIT_FAILURE;
		return (ft_perror("minishell: env: Too many arguments.", NULL));
	}
	return (EXIT_SUCCESS);
}
