/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 07:25:56 by jvoor             #+#    #+#             */
/*   Updated: 2019/11/22 13:05:19 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinfree(char *s1, char *s2, int code)
{
	char		*str;
	size_t		c;
	size_t		c2;

	c = -1;
	c2 = -1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return(NULL);
	while (*(s1 + (++c)))
		*(str + c) = *(s1 +c);
	while (*(s2 + (++c2)))
		*(str + c++) = *(s2 + c2);
	if (code == 1)
		ft_strdel(&s1);
	else if (code == 2)
		ft_strdel(&s2);
	else
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}		
	return (str);
}
