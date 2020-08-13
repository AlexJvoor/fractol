/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:49:47 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/03 10:56:14 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			reset_constants_mousp(int x, int y, t_fr *fr)
{
	double			step_xp;
	double			step_xm;
	double			step_yp;
	double			step_ym;

	step_xm = (fr->set->right_b - fr->set->left_b) *
		((double)x / (double)IMG_W) / 10;
	step_xp = (fr->set->right_b - fr->set->left_b) *
		(1 - ((double)x / (double)IMG_W)) / 10;
	step_yp = (fr->set->bot_b - fr->set->top_b) *
		((double)y / (double)IMG_H) / 10;
	step_ym = (fr->set->bot_b - fr->set->top_b) *
		(1 - ((double)y / (double)IMG_H)) / 10;
	fr->set->left_b += step_xm;
	fr->set->right_b -= step_xp;
	fr->set->top_b += step_yp;
	fr->set->bot_b -= step_ym;
}

void			reset_constants_mousm(int x, int y, t_fr *fr)
{
	double			step_xp;
	double			step_xm;
	double			step_yp;
	double			step_ym;

	step_xm = (fr->set->right_b - fr->set->left_b) *
		((double)x / (double)IMG_W) / 10;
	step_xp = (fr->set->right_b - fr->set->left_b) *
		(1 - ((double)x / (double)IMG_W)) / 10;
	step_yp = (fr->set->bot_b - fr->set->top_b) *
		((double)y / (double)IMG_H) / 10;
	step_ym = (fr->set->bot_b - fr->set->top_b) *
		(1 - ((double)y / (double)IMG_H)) / 10;
	fr->set->left_b -= step_xm;
	fr->set->right_b += step_xp;
	fr->set->top_b -= step_yp;
	fr->set->bot_b += step_ym;
}
