/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frl_cl_prep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoor <jvoor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:16:27 by jvoor             #+#    #+#             */
/*   Updated: 2020/02/03 15:54:04 by jvoor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static cl_device_id	get_device_id(void)
{
	cl_platform_id	platform;
	cl_device_id	device;
	int				err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err != 0)
		ft_putstr("clGetPlatformID_err\n");
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (err != 0)
		ft_putstr("clGetDeviceIDs_err\n");
	return (device);
}

void				create_program(cl_context context, cl_int err,
	cl_program *program)
{
	char			*program_buf;
	size_t			files_num;
	size_t			strlen;

	files_num = 1;
	program_buf = read_file("srcs/try_01.cl");
	strlen = ft_strlen(program_buf);
	*program = clCreateProgramWithSource(context,
		files_num, (const char **)&program_buf, &strlen, &err);
	if (err != 0)
		ft_putstr("clCreateProgramWithSource_err");
}

static void			get_kernels(t_cl *cl, cl_int err)
{
	cl->kernel_fr_01 = clCreateKernel(cl->program, "fractol_01", &err);
	cl->kernel_fr_02 = clCreateKernel(cl->program, "fractol_02", &err);
	cl->kernel_fr_03 = clCreateKernel(cl->program, "fractol_03", &err);
	cl->kernel_fr_04 = clCreateKernel(cl->program, "fractol_04", &err);
	cl->kernel_fr_05 = clCreateKernel(cl->program, "fractol_05", &err);
	if (err != 0)
		ft_putstr("clCreateKernel_err\n");
}

static void			create_program_n_get_kernels(cl_device_id *device,
	t_cl *cl)
{
	char			*log;
	cl_int			err;
	size_t			log_size;

	create_program(cl->context, err = 0, &cl->program);
	err = clBuildProgram(cl->program, 1, device, NULL, NULL, NULL);
	if (err != 0)
	{
		clGetProgramBuildInfo(cl->program, *device, CL_PROGRAM_BUILD_LOG,
				0, NULL, &log_size);
		log = (char *)malloc(log_size);
		clGetProgramBuildInfo(cl->program, *device, CL_PROGRAM_BUILD_LOG,
				log_size, log, NULL);
		ft_putstr("build program - error\n");
	}
	get_kernels(cl, err);
}

void				cl_init(t_cl *cl)
{
	cl_device_id	device;
	cl_int			err;

	device = get_device_id();
	cl->context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
	if (err != 0)
		ft_putstr("clCreateContext_err\n");
	cl->queue = clCreateCommandQueue(cl->context, device, 0, &err);
	if (err != 0)
		ft_putstr("clCreateCommandQueue_err\n");
	create_program_n_get_kernels(&device, cl);
}
