/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:39:47 by jvoor             #+#    #+#             */
/*   Updated: 2019/12/12 23:39:39 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static int			check_av(char **av)
// {
// 	return(ft_strcmp((const char *)av, "ff"));
// }

// static void			pix_set_color(int x, int y, int **data, int color)
// {
// 	data[x + y * WIDTH] = &color;
// }

int					input_check(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		return (0);
	return(1);
}

static t_cam		*cam_init(void)
{
	t_cam			*cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		err_mem();
	cam->x_off = 0;
	cam->y_off = 0;
	cam->zoom = 0.1;
	return (cam);
}

// static void		set_col_to_addr(t_fr *fr, double t, int x, int y)
// {
// 	int			c;
// 	//int			color;
// 	int			r;
// 	//int			g;
// 	//int			b;
// 	//double		t;

// 	//t = (double)iter / (double)MAX_ITER;
// 	r = (int)(9 * pow(t, 3) * 255 * 255 * 255);
//  	// g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
//  	// b = (int)(8.5 * pow((1 - t), 3) * t * 255);
//  	//color = 0xFFFFFF;

// 	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
// 	{
// 		c = (x * (fr->bpp / 8)) + (y * fr->sl);
// 		fr->img_data[c] = r;
// 		//fr->img_data[++c] = color >> 8;
// 		//fr->img_data[++c] = color >> 16;
// 		//fr->img_data[++c] = 0;		
// 	}
// 	//return(((i * 6) % 255) << 16 | ((i * 6) % 255));
// }


static t_dr		*draw_init(void)
{
	t_dr			*draw;

	if (!(draw = (t_dr*)malloc(sizeof(t_dr))))
		err_mem();
	draw->iter = 60;
	return (draw);
}

static t_cntr		*cntr_init()
{
	t_cntr		*cntr;

	if (!(cntr = (t_cntr*)malloc(sizeof(t_cntr))))
		err_mem();
	cntr->zm_pt_x = WIDTH / 2;
	cntr->zm_pt_y = HEIGHT / 2;
	cntr->c_re = -1;
	cntr->c_im = 0;
	return(cntr);
}

static void			init_fr(t_fr *fr)
{
	if (!(fr = (t_fr*)malloc(sizeof(t_fr))))
		err_mem();
	//printf("/n/nin init fr/n/n");
	printf("\n\nmlx");
	fr->mlx = mlx_init();
	printf("\n\ncam");
	fr->cam = cam_init();
	printf("\n\ncntr");
	fr->cntr = cntr_init();
	printf("\n\ndraw");
	fr->dr = draw_init();
	printf("\n\nn_win");
	fr->win = mlx_new_window(fr->mlx, WIDTH, HEIGHT, "TRASH");
	printf("\n\nn_im");
	fr->img  =mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	printf("\n\ngda");
	fr->img_data = (int *)mlx_get_data_addr(fr->img, &fr->bpp, &fr->sl, &fr->endn);
	printf("\n\nend_ini_fr");
}

// static void			draw_smth(t_fr *fr, int x, int y, double t)
// {
// 	// int				i;
// 	// //double			t;

// 	// //t = (double)fr->dr->iter/(double)MAX_ITER;
// 	// i = -1;
// 	// fr->dr->re[NEW] = (x - fr->cntr->zm_pt_x) / (fr->cam->zoom * WIDTH) + fr->cam->x_off;
// 	// fr->dr->im[NEW] = (y - fr->cntr->zm_pt_y) / (fr->cam->zoom * HEIGHT) + fr->cam->y_off;
// 	// while (fr->dr->re[NEW] * fr->dr->re[NEW] + fr->dr->im[NEW] * fr->dr->im[NEW] < 4 && ++i < fr->dr->iter)
// 	// {
// 	// 	fr->dr->re[OLD] = fr->dr->re[NEW];
// 	// 	fr->dr->im[OLD] = fr->dr->im[NEW];
// 	// 	fr->dr->re[NEW] = fr->dr->re[OLD] * fr->dr->re[OLD] - fr->dr->im[OLD] * fr->dr->im[OLD] + fr->cntr->c_re;
// 	// 	fr->dr->im[NEW] = 2 * fr->dr->re[OLD] * fr->dr->im[OLD] + fr->cntr->c_im;
// 	// }
// 	// if (i < fr->dr->iter)
// 	// 	set_col_to_addr(fr, 0, x, y);
// 	// else
// 	// 	set_col_to_addr(fr, t, x, y);	
// }

// static char			set_color(int itr, int max_itr)
// {
// 	double			t;
// 	int				r;
// 	int				g;
// 	int				b;
// 	int				color;

// 	t = (double)itr / (double)max_itr;
// 	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
// 	g = (int)(15 * pow((1 - t), 2) * pow(t,2) * 255);
// 	b = (int)(8.5 * pow ((1 - t), 3) * t * 255);
// 	color = r * 255 * 255 + g * 255 + b;
// 	return(color);
// }

void				draw(t_fr *fr)
{
	printf("\n\nstart_draw");
	//t_com			max;
	//t_com			min;
	t_com			*fct;
	//t_com			z;
	//t_com			c;
	int				x;
	int				y;
	int				itr;

	(void)itr;
	//(void)z;
	printf("\n\nfct = ...");
	if (!(fct = (t_com*)malloc(sizeof(t_com))))
		err_mem();
	fct = init_com((MA_R - MI_R) / (WIDTH - 1), (MA_I - MI_I) / (HEIGHT - 1));
	// double			t;

	// t = (double)fr->dr->iter/(double)MAX_ITER;
	printf("\n\nft_bzero");
	ft_bzero(fr->img_data, (WIDTH * fr->bpp / 8) * HEIGHT);
	printf("\n\nclear_win");
	mlx_clear_window(fr->mlx, fr->win);
	printf("\n\nafter_win_clear");
	y = -1;
	//printf("/n/niny/n/n");
	while (++y < HEIGHT)
	{
		printf("\n\nin while pow1");
		//fr->c->im = 0.250 - y * fct.im;
		x = -1;
		//printf("/n/ninx");
		// while (++x < WIDTH)
		// {
		// 	printf("\n\nin while pow2");
		// 	printf("\n\n");
		// 	fr->c->re = MI_R + x * fct.re;
		// 	z = init_com(fr->c->re, fr->c->im);
		// 	itr = 0;
		// 	// while (pow(z.re, 2.0) + pow(z.im, 2.0)<= 4 && itr < fr->max_itr)
		// 	// {
		// 	// 	z = init_com(pow(z.re, 2.0) - pow(z.im, 2.0) + fr->c->re, 2.0 * z.re * z.im + fr->c->im);
		// 	// 	itr++;
		// 	// }
		// 	//printf("/n/nmemset/n/n");
		// 	pix_set_color(x, y, &fr->img_data, 0xFFFFFF);
		// }

	}
	//printf("%f %f %f %f %i %f %f", MI_R, MA_R, MI_I, MA_I, WIDTH, fct.im, fct.re);
	// fr->dr->y = -1;
	// while (++fr->dr->y < HEIGHT)
	// {
	// 	fr->dr->x = -1;
	// 	while (++fr->dr->x < WIDTH)
	// 		draw_smth(fr, fr->dr->x, fr->dr->y, t);
	// }
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

int					main(int ac, char **av)
{
	t_fr	*fr;

	printf("\n\nstart");
	if (input_check(ac, av) == 0)
		err_input();
	if (!((fr = (t_fr*)malloc(sizeof(t_fr)))))
		err_mem();
	printf("\n\nin_check");
	init_fr(fr);
	printf("\n\nini_fr");
	draw(fr);
	printf("\n\ndraw");
	keys_hook(fr);
	printf("\n\nkeys_n_loop");
	mlx_loop(fr->mlx);
	return(0);
}
