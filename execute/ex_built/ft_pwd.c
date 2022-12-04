/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:07:53 by youssama          #+#    #+#             */
/*   Updated: 2022/07/07 16:24:59 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	char	cwd[1024];
	char	*dir;

	(void)cmd;
	dir = getcwd(cwd, sizeof(cwd));
	if (!dir)
	{
		perror("minishell: pwd: ");
		g_data.exit_status = EXIT_FAILURE;
		return (-1);
	}
	printf("%s\n", dir);
	g_data.exit_status = EXIT_SUCCESS;
	return (EXIT_SUCCESS);
}
