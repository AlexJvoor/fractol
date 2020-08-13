/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:56:32 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/04 04:58:40 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# include "libft.h"

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define IMG_W 1400
# define IMG_H 1400

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_consts
{
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
}				t_consts;

typedef struct	s_cl
{
	cl_command_queue	queue;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel_fr_01;
	cl_kernel			kernel_fr_02;
	cl_kernel			kernel_fr_03;
	cl_kernel			kernel_fr_04;
	cl_kernel			kernel_fr_05;
}				t_cl;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			sl;
	int			endn;
	int			width;
	int			height;
}				t_mlx;

typedef struct	s_set
{
	double		left_b;
	double		right_b;
	double		top_b;
	double		bot_b;
	double		radius;
	double		const_real;
	double		const_imagin;
	int			depth;
	int			color_mult;
	int			center_x;
	int			center_y;
}				t_set;

typedef struct	s_fr
{
	int			fr_code;
	int			m_m_flag;
	char		**cl_filename;
	t_set		*set;
	t_mlx		*mlx;
	t_cl		*cl;
	t_complex	*m_m;
	t_consts	*c;
}				t_fr;

/*
** frl_cl_prep.c
*/

void			cl_init(t_cl *cl);

/*
** frl_draw.c
*/

int				get_hooks_n_cl(t_fr *fr);
int				refresh(t_fr *fr);

/*
** frl_init.c
*/

t_fr			*frl_new_win(int f_code);
t_complex		*init_complex(double re, double im);
t_consts		*set_consts();

/*
** frl_keys.c
*/

int				key_press_cl(int key, t_fr *fr);
int				mouse_button_press_cl(int btn, int x, int y, t_fr *fr);
int				mouse_move_cl(int x, int y, t_fr *fr);
int				x_press(void);

/*
** frl_norm_file01.c
*/

cl_kernel		set_kernel(t_fr *fr);
char			*read_file(char *path);
void			reset(t_fr *fr);
t_set			*set_fr(void);

/*
** frl_win.c
*/

void			reset_constants_mousp(int x, int y, t_fr *fr);
void			reset_constants_mousm(int x, int y, t_fr *fr);

/*
** main.c
*/

int				draw_cl(t_fr *fr);

#endif
