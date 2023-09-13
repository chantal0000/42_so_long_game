/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:09:48 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/13 13:43:04 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nw;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			nw = ft_lstlast(*(lst));
			nw->next = new;
		}
	}
}
