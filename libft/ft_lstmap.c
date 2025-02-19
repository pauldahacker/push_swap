/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:38:12 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/02 12:40:44 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*to_add;
	void	*temp;

	if (!del || !lst || !f)
		return (NULL);
	mapped = NULL;
	while (lst)
	{
		temp = f(lst->content);
		to_add = ft_lstnew(temp);
		if (!to_add)
		{
			del(temp);
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, to_add);
		lst = lst->next;
	}
	return (mapped);
}
