/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:57:53 by ijaija            #+#    #+#             */
/*   Updated: 2024/05/13 11:18:42 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_CONTROL_H
# define HEAD_CONTROL_H

# include <stdlib.h>
# include <unistd.h>

# define MALLOC_ERR "Error: malloc(3) failed\n"
# define ADDR_ADD_ERR "Error trying to add a null pointer to session struct\n"

# define M_ALLOC 1
# define M_DEL 2
# define M_CLEAN 3

typedef struct s_heapaddr
{
	void				*addr;
	struct s_heapaddr	*next;
}			t_memslot;

typedef struct s_heapslots
{
	struct s_heapaddr	*head;
	struct s_heapaddr	*tail;
	int					count;
}			t_memsession;

void	exit_on_error(char *error, int len);
void	session_init(t_memsession **session_ptr);

# endif