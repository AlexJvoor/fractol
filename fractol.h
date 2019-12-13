/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:37:04 by jvoor             #+#    #+#             */
/*   Updated: 2019/12/12 23:37:55 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
//# include <pthread.h>

# include "libft/libft.h"

//----- Iters
# define OLD 0
# define NEW 1
//# define MAX_ITER 50
# define POW(x) (x * x)

//----- Errs n exit
# define EXIT 0
# define NO_MEM_ERR 1
# define INP_ERR 5

//----- W & H
# define WIDTH 1920
# define HEIGHT 1080

# define MI_R -2.0
# define MA_R 2.0
# define MI_I -2.0
# define MA_I (MI_I + (MA_R - MI_R) * HEIGHT / WIDTH)

//----- BUTONS
# define B_ESC 53
# define B_LT 123
# define B_RT 124
# define B_DN 125
# define B_UP 126

//----- M_BUTONS
# define M_SC_UP 4
# define M_SC_DN 5

typedef struct		s_com
{
	double			re;
	double			im;
}					t_com;

typedef struct		s_dr
{
	int				x;
	int				y;
	double			re[2];
	double			im[2];
	int				iter;
}					t_dr;

typedef struct		s_cam
{
	float			x_off;
	float			y_off;
	double			zoom;
}					t_cam;

typedef struct		s_cntr
{
	int				zm_pt_x;
	int				zm_pt_y;
	double			c_re;
	double			c_im;
}					t_cntr;

typedef struct		s_fr
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*img_data;
	int				bpp;
	int				sl;
	int				endn;
	char			type;
	//int				max_itr;
	t_com			*c;
	t_dr			*dr;
	t_cam			*cam;
	t_cntr			*cntr;		
}					t_fr;

t_com           	*init_com(double x, double y);
t_com				*init_fct();
void				err_mem();
void				err_input();
void				keys_hook(t_fr *fr);
void				terminate(int flag);
void				draw(t_fr *fr);
int					input_check(int ac, char **av);

#endif
