__kernel void		fractol_01(__global int *img, double step_x, double step_y, int depth,
		int width, double left_b, double top_b, double radius, int color_mult)//mandelbrot
{
	double			comp_x, comp_y;
	double			tmp;
	double			real, imag;
	int				i = -1;
	int				gid = get_global_id(0);

	comp_x = left_b + step_x * (gid % width);
	comp_y = top_b + step_y * (gid / width);
	real = 0.0;
	imag = 0.0;
	while (++i < depth && real * real + imag * imag < radius)
	{
		tmp = real * real - imag * imag;
		imag = 2 * real * imag + comp_y;
		real = tmp + comp_x;
	}
	if (i < depth)
		img[gid] = i * color_mult;
	else
		img[gid] = 0;
}

__kernel void		fractol_02(__global int *img, double step_x, double step_y, int depth,
		int width, double left_b, double top_b, double radius, int color_mult)//burningship
{
	double			comp_x, comp_y;
	double			tmp;
	double			real, imag;
	int				i = -1;
	int				gid = get_global_id(0);

	comp_x = left_b + step_x * (gid % width);
	comp_y = top_b + step_y * (gid / width);
	real = 0.0;
	imag = 0.0;
	while (++i < depth && real * real + imag * imag < radius)
	{
		tmp = real * real - imag * imag;
		imag = -2 * fabs(real * imag) + comp_y;
		real = tmp + comp_x;
	}
	if (i < depth)
		img[gid] = i * color_mult;
	else
		img[gid] = 0;
}

__kernel void		fractol_03(__global int *img, double step_x, double step_y, int depth,
		int width, double left_b, double top_b, double radius, int color_mult,
		double m_m_im, double m_m_re)//julia
{
	double			tmp;
	double			real, imag;
	int				i = -1;
	int				gid = get_global_id(0);

	real = left_b + step_x * (gid % width);
	imag = top_b + step_y * (gid / width);
	while (++i < depth && real * real + imag * imag < radius)
	{
		tmp = real * real - imag * imag;
		imag = 2 * real * imag + m_m_im;
		real = tmp + m_m_re;
	}
	if (i < depth)
		img[gid] = i * color_mult;
	else
		img[gid] = 0;
}

__kernel void		fractol_04(__global int *img, double step_x, double step_y, int depth,
		int width, double left_b, double top_b, double radius, int color_mult)//celetic madelbrot
{
	double			comp_x, comp_y;
	double			tmp;
	double			real, imag;
	int				i = -1;
	int				gid = get_global_id(0);

	comp_x = left_b + step_x * (gid % width);
	comp_y = top_b + step_y * (gid / width);
	real = 0.0;
	imag = 0.0;
	while (++i < depth && real * real + imag * imag < radius)
	{
		tmp = real * real - imag * imag;
		imag = 2 * real * imag + comp_y;
		real = fabs(tmp) + comp_x;
	}
	if (i < depth)
		img[gid] = i * color_mult;
	else
		img[gid] = 0;
}

__kernel void		fractol_05(__global int *img, double step_x, double step_y, int depth,
		int width, double left_b, double top_b, double radius, int color_mult)//buffalo
{
	double			comp_x, comp_y;
	double			tmp;
	double			real, imag;
	int				i = -1;
	int				gid = get_global_id(0);

	comp_x = left_b + step_x * (gid % width);
	comp_y = top_b + step_y * (gid / width);
	real = 0.0;
	imag = 0.0;
	while (++i < depth && real * real + imag * imag < radius)
	{
		tmp = real * real - imag * imag;
		imag = -2 * fabs(real * imag) + comp_y;
		real = fabs(tmp) + comp_x;
	}
	if (i < depth)
		img[gid] = i * color_mult;
	else
		img[gid] = 0;
}