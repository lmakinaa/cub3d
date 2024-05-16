/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:13:52 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/13 11:14:15 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "heap_control.h"

void	exit_on_error(char *error, int len)
{
	write(2, error, len);
	exit(1);
}

void	session_init(t_memsession **session_ptr)
{
	t_memsession	*session;

	session = malloc(sizeof(t_memsession));
	if (!session)
		exit_on_error(MALLOC_ERR, 23);
	session->head = NULL;
	session->tail = NULL;
	session->count = 0;
	*session_ptr = session;
}
