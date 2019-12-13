/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:34:47 by jvoor             #+#    #+#             */
/*   Updated: 2019/12/03 20:18:27 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		move_cam(int key, t_fr *fr)
{
	if (key == B_RT)
		fr->cam->x_off -= 0.03 / fr->cam->zoom;
	if (key == B_LT)
		fr->cam->x_off += 0.03 / fr->cam->zoom;
	if (key == B_DN)
		fr->cam->y_off -= 0.03 / fr->cam->zoom;
	if (key == B_UP)
		fr->cam->y_off += 0.03 / fr->cam->zoom;
	draw(fr);
}

static void		zoom(int bn, int x, int y, t_fr *fr)
{
	(void)x;
	(void)y;
	if (bn == M_SC_UP)
		fr->cam->zoom +=0.005;
	if (bn == M_SC_DN && fr->cam->zoom > 0.005)
		fr->cam->zoom -= 0.005;
	draw(fr);
}

void			terminate(int flag)
{
	exit(flag);
}

static int		x_close(void *param)
{
	(void)param;
	terminate(EXIT);
	return(0);
}

static void		change_shape(int x, int y, t_fr *fr)
{
	if (x <= WIDTH && x >= 0 && y <= HEIGHT)
	{
		fr->cntr->c_re = (x - WIDTH / 2) * 0.0006;
		fr->cntr->c_im = (y - HEIGHT / 2) * 0.0006;
	}
	draw(fr);
}

int			key_controls(int key, t_fr *fr)
{
	if (key == B_ESC)
		x_close(fr);
	else if (key == B_UP || key == B_DN || key == B_LT || key == B_RT)
		move_cam(key, fr);
	return(0);
}

static int		mouse_press(int bn, int x, int y, t_fr *fr)
{
	if (bn == M_SC_UP || bn == M_SC_DN)
		zoom(bn, x, y, fr);
	return (0);	
}

static int		mouse_move(int x, int y, t_fr *fr)
{
	change_shape(x, y, fr);
	return (0);
}

// static int		mouse_release()
// {
	
// 	return (0);
// }

void			keys_hook(t_fr *fr)
{
	mlx_hook(fr->win, 17, 0, x_close, fr);
	mlx_hook(fr->win, 2, 0, key_controls, fr);
	mlx_hook(fr->win, 4, 0, mouse_press, fr);
	//mlx_hook(fr->win, 5, 0, mouse_release, fr);
	mlx_hook(fr->win, 6, 0, mouse_move, fr);
}