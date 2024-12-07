/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:02:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:02:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstiter" iterates through a linked list and applies a given 
 * function to the content of each element.
 * 
 * @param lst 			A pointer to the first element of the linked list.
 * @param f 			A function pointer to a function that is applied to the
 * 						content of each element in the list.
 * 
 * @return None. 		The function performs the operation on each element's 
 * 						content without modifying the structure of the list.
 * 
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
