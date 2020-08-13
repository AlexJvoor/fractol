/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:36:22 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/04 05:01:50 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press_cl(int key, t_fr *fr)
{
	if (key == 53)
		exit(0);
	if (key == 78 || key == 69)
		fr->set->depth += (key == 69) ? 1 : -1;
	if (key == 125 || key == 126)
		fr->set->color_mult += (key == 125) ? -10 : 10;
	if (key == 49)
		reset(fr);
	if (key == 82)
		fr->m_m_flag = (fr->m_m_flag == 1) ? 0 : 1;
	refresh(fr);
	return (0);
}

int			mouse_button_press_cl(int btn, int x, int y, t_fr *fr)
{
	(void)x;
	(void)y;
	if (btn == 4)
		reset_constants_mousp(x, y, fr);
	else if (btn == 5)
		reset_constants_mousm(x, y, fr);
	refresh(fr);
	return (0);
}

int			mouse_move_cl(int x, int y, t_fr *fr)
{
	if (fr->m_m_flag == 1)
	{
		fr->m_m->im = 4 * ((double)x / IMG_W - 0.5);
		fr->m_m->re = 4 * ((double)(IMG_H - y) / IMG_H - 0.5);
	}
	refresh(fr);
	return (0);
}

int			x_press(void)
{
	exit(0);
	return (0);
}
