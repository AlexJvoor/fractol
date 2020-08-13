/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_norm_file01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:04:39 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/03 16:26:35 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

cl_kernel		set_kernel(t_fr *fr)
{
	if (fr->fr_code == 1)
		return (fr->cl->kernel_fr_01);
	else if (fr->fr_code == 2)
		return (fr->cl->kernel_fr_02);
	else if (fr->fr_code == 3)
		return (fr->cl->kernel_fr_03);
	else if (fr->fr_code == 4)
		return (fr->cl->kernel_fr_04);
	else if (fr->fr_code == 5)
		return (fr->cl->kernel_fr_05);
	else
		return (NULL);
}

char			*read_file(char *path)
{
	int			fd;
	int			number;
	char		*buff;

	fd = open(path, O_RDONLY);
	buff = (char*)malloc(sizeof(char) * 10000);
	if (fd < 2)
		exit(99);
	number = read(fd, buff, 10000);
	buff[number] = '\0';
	close(fd);
	return (buff);
}

void			reset(t_fr *fr)
{
	fr->set = set_fr();
	fr->c = set_consts();
}

t_set			*set_fr(void)
{
	t_set		*set;

	if (!(set = (t_set *)malloc(sizeof(t_set))))
		return (NULL);
	set->left_b = -3.0;
	set->right_b = 3.0;
	set->top_b = -3.0;
	set->bot_b = 3.0;
	set->depth = 50;
	set->color_mult = 500000;
	set->radius = 4;
	return (set);
}
