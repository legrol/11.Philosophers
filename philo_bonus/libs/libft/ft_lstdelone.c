/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:02:20 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:02:20 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_lstdelone" deletes and frees a single element of a linked 
 * list using the provided delete function to free the content. The memory of 
 * the element itself is also freed.
 * 
 * @param lst 			A pointer to the element to be deleted. The element's 
 * 						memory is freed, and its content is deleted using the 
 * 						provided delete function.
 * @param del 			A function pointer to a delete function that is used to
 * 						free the content of the element.
 * 
 * @return None. 		The memory for the element is freed, and the content is
 * 						deleted.
 * 
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}
