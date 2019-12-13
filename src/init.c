/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:26:38 by jvoor             #+#    #+#             */
/*   Updated: 2019/12/12 23:41:41 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_com           *init_com(double x, double y)
{
    t_com       *com;

    if (!(com = (t_com*)malloc(sizeof(t_com))))
        err_mem();
    com->re = x;
    com->re = y;
    return (com);
}

t_com			*init_fct()
{
	t_com		*fct;

	fct = init_com((MA_R - MI_R) / (WIDTH - 1), (MA_I - MI_I) / (HEIGHT - 1));
	return(fct);
}	
