/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:15:05 by pcatrina          #+#    #+#             */
/*   Updated: 2020/11/25 10:15:08 by pcatrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exit(t_data *data)
{
	ft_putstr_fd("Exit . . .", 1);
	free_memory(data->env);
	free_memory(data->next);
	free_memory(data->prev);
	exit(0);
}