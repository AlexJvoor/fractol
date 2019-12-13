/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:28:05 by jvoor             #+#    #+#             */
/*   Updated: 2019/12/12 22:34:04 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				err_mem()
{
	ft_putstr("\n\nmem error");
	terminate(1);
}


void				err_input()
{
	ft_putstr("\n\ninput format './fractol [fractol name]'");
	terminate(1);
}
