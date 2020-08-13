/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:38:11 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/04 04:58:56 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fr			*frl_new_win(int f_code)
{
	t_fr		*fr;

	if (!(fr = (t_fr*)malloc(sizeof(t_fr))))
		return (NULL);
	if (!(fr->cl = (t_cl *)malloc(sizeof(t_fr))))
		return (NULL);
	fr->fr_code = f_code;
	fr->m_m_flag = 1;
	fr->m_m = init_complex(-0.4, 0.6);
	fr->mlx = mlx_init();
	fr->mlx->win = mlx_new_window(fr->mlx, IMG_W, IMG_H, "Fractol");
	fr->mlx->img = mlx_new_image(fr->mlx, IMG_W, IMG_H);
	fr->mlx->data = (int *)mlx_get_data_addr(fr->mlx->img, &fr->mlx->bpp,
		&fr->mlx->sl, &fr->mlx->endn);
	fr->c = set_consts();
	fr->mlx->width = IMG_W;
	fr->mlx->height = IMG_H;
	return (fr);
}

t_complex		*init_complex(double re, double im)
{
	t_complex	*complex;

	if (!(complex = ((t_complex*)malloc(sizeof(t_complex)))))
		return (NULL);
	complex->re = re;
	complex->im = im;
	return (complex);
}

t_consts		*set_consts(void)
{
	t_consts	*c;

	if (!(c = (t_consts*)malloc(sizeof(t_consts))))
		return (NULL);
	c->min_re = -3.0;
	c->max_re = 3.0;
	c->min_im = -3.0;
	c->max_im = 3.0;
	return (c);
}
