/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:50:20 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/03 15:54:27 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_args_n_calc_julia(t_fr *fr, cl_mem *mem_img)
{
	double		step_x;
	double		step_y;
	size_t		glob_size;
	cl_kernel	kernel;
	cl_int		err;

	kernel = fr->cl->kernel_fr_03;
	glob_size = IMG_H * IMG_W;
	step_x = (fr->set->right_b - fr->set->left_b) / IMG_W;
	step_y = (fr->set->bot_b - fr->set->top_b) / IMG_H;
	err = clSetKernelArg(kernel, 0, sizeof(cl_mem), mem_img);
	err |= clSetKernelArg(kernel, 1, sizeof(double), &step_x);
	err |= clSetKernelArg(kernel, 2, sizeof(double), &step_y);
	err |= clSetKernelArg(kernel, 3, sizeof(int), &fr->set->depth);
	err |= clSetKernelArg(kernel, 4, sizeof(int), &fr->mlx->width);
	err |= clSetKernelArg(kernel, 5, sizeof(double), &fr->set->left_b);
	err |= clSetKernelArg(kernel, 6, sizeof(double), &fr->set->top_b);
	err |= clSetKernelArg(kernel, 7, sizeof(double), &fr->set->radius);
	err |= clSetKernelArg(kernel, 8, sizeof(int), &fr->set->color_mult);
	err |= clSetKernelArg(kernel, 9, sizeof(double), &fr->m_m->im);
	err |= clSetKernelArg(kernel, 10, sizeof(double), &fr->m_m->re);
	err = clEnqueueNDRangeKernel(fr->cl->queue, kernel, 1, NULL, &glob_size,
									NULL, 0, NULL, NULL);
	if (err != 0)
		ft_putstr("NDR_err\n");
}

static void		set_args_n_calc(t_fr *fr, cl_mem *mem_img)
{
	double		step_x;
	double		step_y;
	size_t		glob_size;
	cl_kernel	kernel;
	cl_int		err;

	kernel = set_kernel(fr);
	glob_size = IMG_H * IMG_W;
	step_x = (fr->set->right_b - fr->set->left_b) / IMG_W;
	step_y = (fr->set->bot_b - fr->set->top_b) / IMG_H;
	err = clSetKernelArg(kernel, 0, sizeof(cl_mem), mem_img);
	err |= clSetKernelArg(kernel, 1, sizeof(double), &step_x);
	err |= clSetKernelArg(kernel, 2, sizeof(double), &step_y);
	err |= clSetKernelArg(kernel, 3, sizeof(int), &fr->set->depth);
	err |= clSetKernelArg(kernel, 4, sizeof(int), &fr->mlx->width);
	err |= clSetKernelArg(kernel, 5, sizeof(double), &fr->set->left_b);
	err |= clSetKernelArg(kernel, 6, sizeof(double), &fr->set->top_b);
	err |= clSetKernelArg(kernel, 7, sizeof(double), &fr->set->radius);
	err |= clSetKernelArg(kernel, 8, sizeof(int), &fr->set->color_mult);
	if (err != 0)
		ft_putstr("clCreateKernelArg_err");
	err = clEnqueueNDRangeKernel(fr->cl->queue, kernel, 1, NULL, &glob_size,
									NULL, 0, NULL, NULL);
	if (err != 0)
		ft_putstr("NDR_err\n");
}

int				refresh(t_fr *fr)
{
	cl_int		err;
	cl_mem		mem_img;

	mem_img = clCreateBuffer(fr->cl->context, CL_MEM_READ_WRITE,
								fr->mlx->sl * fr->mlx->height, NULL, &err);
	if (fr->fr_code != 3)
		set_args_n_calc(fr, &mem_img);
	else
		set_args_n_calc_julia(fr, &mem_img);
	err = clEnqueueReadBuffer(fr->cl->queue, mem_img, CL_TRUE, 0,
								fr->mlx->sl * fr->mlx->height,
								fr->mlx->data, 0, NULL, NULL);
	mlx_put_image_to_window(fr->mlx->mlx, fr->mlx->win,
							fr->mlx->img, 0, 0);
	clReleaseMemObject(mem_img);
	return (0);
}

int				get_hooks_n_cl(t_fr *fr)
{
	mlx_hook(fr->mlx->win, 2, 0, key_press_cl, fr);
	mlx_hook(fr->mlx->win, 4, 0, mouse_button_press_cl, fr);
	mlx_hook(fr->mlx->win, 6, 0, mouse_move_cl, fr);
	mlx_hook(fr->mlx->win, 17, 0, x_press, fr);
	return (0);
}
