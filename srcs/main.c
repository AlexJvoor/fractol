/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:58:10 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/03 16:02:49 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		usage(void)
{
	ft_putstr("Usage: ./fractol [fractol_name]\n");
	ft_putstr("Available fractols:\n");
	ft_putstr("* Mandelbrot(code [1])\n");
	ft_putstr("* Burningship(code [2])\n");
	ft_putstr("* Julia(code[3])\n");
	ft_putstr("* Celetic madelbrot(code[4])\n");
	ft_putstr("* Buffalo(code[5])\n");
	return (0);
}

int				draw_cl(t_fr *fr)
{
	cl_init(fr->cl);
	fr->set = set_fr();
	return (0);
}

int				main(int ac, char **av)
{
	int			f_code;
	t_fr		*fr;

	if (ac != 2 || !(f_code = ft_atoi(av[1])) || (f_code < 1 && 5 < f_code))
		return (usage());
	fr = frl_new_win(f_code);
	draw_cl(fr);
	get_hooks_n_cl(fr);
	mlx_loop(fr->mlx);
	return (0);
}
