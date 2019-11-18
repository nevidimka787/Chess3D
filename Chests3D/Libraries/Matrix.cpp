#include "Matrix.h"
#include <math.h>

ConstMatrix1x4::ConstMatrix1x4(double matrix_a_component, double matrix_b_component, double matrix_c_component, double matrix_d_component)
{
	a = matrix_a_component;
	b = matrix_b_component;
	c = matrix_c_component;
	d = matrix_d_component;
}


Matrix1x4::Matrix1x4(double matrix_a_component, double matrix_b_component, double matrix_c_component, double matrix_d_component)
{
	a = matrix_a_component;
	b = matrix_b_component;
	c = matrix_c_component;
	d = matrix_d_component;
}

Matrix1x4::Matrix1x4(int matrix_mode)
{
	switch (matrix_mode)
	{
	case 1:
		a = 1.0;
		b = 1.0;
		c = 1.0;
		d = 1.0;
	default:
		a = 0.0;
		b = 0.0;
		c = 0.0;
		d = 0.0;
		break;
	}
}


Matrix4x4::Matrix4x4(double matrix_a_component, double matrix_b_component, double matrix_c_component, double matrix_d_component, double matrix_e_component, double matrix_f_component, double matrix_g_component, double matrix_h_component, double matrix_i_component, double matrix_j_component, double matrix_k_component, double matrix_l_component, double matrix_m_component, double matrix_n_component, double matrix_o_component, double matrix_p_component)
{
	a = matrix_a_component;
	b = matrix_b_component;
	c = matrix_c_component;
	d = matrix_d_component;
	e = matrix_e_component;
	f = matrix_f_component;
	g = matrix_g_component;
	h = matrix_h_component;
	i = matrix_i_component;
	j = matrix_j_component;
	k = matrix_k_component;
	l = matrix_l_component;
	m = matrix_m_component;
	n = matrix_n_component;
	o = matrix_o_component;
	p = matrix_p_component;
}

Matrix4x4::Matrix4x4(int matrix_mode)
{
	switch (matrix_mode)
	{
	case 1:
		a = 1.0;
		b = 0.0;
		c = 0.0;
		d = 0.0;
		e = 0.0;
		f = 1.0;
		g = 0.0;
		h = 0.0;
		i = 0.0;
		j = 0.0;
		k = 1.0;
		l = 0.0;
		m = 0.0;
		n = 0.0;
		o = 0.0;
		p = 1.0;
		break;
	default:
		a = 0.0;
		b = 0.0;
		c = 0.0;
		d = 0.0;
		e = 0.0;
		f = 0.0;
		g = 0.0;
		h = 0.0;
		i = 0.0;
		j = 0.0;
		k = 0.0;
		l = 0.0;
		m = 0.0;
		n = 0.0;
		o = 0.0;
		p = 0.0;
		break;
	}
}

ConstMatrix1x4 Matrix4x4::Multiply(ConstMatrix1x4 second_matrix)
{
	double new_a, new_b, new_c, new_d;

	new_a = a * second_matrix.a + b * second_matrix.b + c * second_matrix.c + d * second_matrix.d;
	new_b = e * second_matrix.a + f * second_matrix.b + g * second_matrix.c + h * second_matrix.d;
	new_c = i * second_matrix.a + j * second_matrix.b + k * second_matrix.c + l * second_matrix.d;
	new_d = m * second_matrix.a + n * second_matrix.b + o * second_matrix.c + p * second_matrix.d;

	ConstMatrix1x4* return_matrix = new ConstMatrix1x4(new_a, new_b, new_c, new_d);
	return *return_matrix;
}

Matrix1x4 Matrix4x4::Multiply(Matrix1x4 second_matrix)
{
	double new_a, new_b, new_c, new_d;

	new_a = a * second_matrix.a + b * second_matrix.b + c * second_matrix.c + d * second_matrix.d;
	new_b = e * second_matrix.a + f * second_matrix.b + g * second_matrix.c + h * second_matrix.d;
	new_c = i * second_matrix.a + j * second_matrix.b + k * second_matrix.c + l * second_matrix.d;
	new_d = m * second_matrix.a + n * second_matrix.b + o * second_matrix.c + p * second_matrix.d;

	Matrix1x4* return_matrix = new Matrix1x4(new_a, new_b, new_c, new_d);
	return *return_matrix;
}

Matrix4x4 Matrix4x4::Multiply(Matrix4x4 second_matrix)
{
	double new_a, new_b, new_c, new_d, new_e, new_f, new_g, new_h, new_i, new_j, new_k, new_l, new_m, new_n, new_o, new_p;

	new_a = a * second_matrix.a + b * second_matrix.e + c * second_matrix.i + d * second_matrix.m;
	new_b = a * second_matrix.b + b * second_matrix.f + c * second_matrix.j + d * second_matrix.n;
	new_c = a * second_matrix.c + b * second_matrix.g + c * second_matrix.k + d * second_matrix.o;
	new_d = a * second_matrix.d + b * second_matrix.h + c * second_matrix.l + d * second_matrix.p;

	new_e = e * second_matrix.a + f * second_matrix.e + g * second_matrix.i + h * second_matrix.m;
	new_f = e * second_matrix.b + f * second_matrix.f + g * second_matrix.j + h * second_matrix.n;
	new_g = e * second_matrix.c + f * second_matrix.g + g * second_matrix.k + h * second_matrix.o;
	new_h = e * second_matrix.d + f * second_matrix.h + g * second_matrix.l + h * second_matrix.p;

	new_i = i * second_matrix.a + j * second_matrix.e + k * second_matrix.i + l * second_matrix.m;
	new_j = i * second_matrix.b + j * second_matrix.f + k * second_matrix.j + l * second_matrix.n;
	new_k = i * second_matrix.c + j * second_matrix.g + k * second_matrix.k + l * second_matrix.o;
	new_l = i * second_matrix.d + j * second_matrix.h + k * second_matrix.l + l * second_matrix.p;

	new_m = m * second_matrix.a + n * second_matrix.e + o * second_matrix.i + p * second_matrix.m;
	new_n = m * second_matrix.b + n * second_matrix.f + o * second_matrix.j + p * second_matrix.n;
	new_o = m * second_matrix.c + n * second_matrix.g + o * second_matrix.k + p * second_matrix.o;
	new_p = m * second_matrix.d + n * second_matrix.h + o * second_matrix.l + p * second_matrix.p;

	Matrix4x4* return_matrix = new Matrix4x4(new_a, new_b, new_c, new_d, new_e, new_f, new_g, new_h, new_i, new_j, new_k, new_l, new_m, new_n, new_o, new_p);
	return *return_matrix;
}

void Matrix4x4::RotateX(double angle)
{
	Matrix4x4* new_matrix = new Matrix4x4(1.0, 0.0, 0.0, 0.0, 0.0, cos(angle), -sin(angle), 0.0, 0.0, sin(angle), cos(angle), 0.0, 0.0, 0.0, 0.0, 1.0);
	*this = Multiply(*new_matrix);
}

void Matrix4x4::RotateY(double angle)
{
	Matrix4x4* new_matrix = new Matrix4x4(cos(angle), 0.0, sin(angle), 0.0, 0.0, 1.0, 0.0, 0.0, -sin(angle), 0.0, cos(angle), 0.0, 0.0, 0.0, 0.0, 1.0);
	*this = Multiply(*new_matrix);
}

void Matrix4x4::RotateZ(double angle)
{
	Matrix4x4* new_matrix = new Matrix4x4(cos(angle), -sin(angle), 0.0, 0.0, sin(angle), cos(angle), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	*this = Multiply(*new_matrix);
}

void Matrix4x4::Scale(double x, double y, double z)
{
	Matrix4x4* new_matrix = new Matrix4x4(x, 0.0, 0.0, 0.0, 0.0, y, 0.0, 0.0, 0.0, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0);
	*this = Multiply(*new_matrix);
}

void Matrix4x4::Translate(double x, double y, double z)
{
	Matrix4x4* new_matrix = new Matrix4x4(1.0, 0.0, 0.0, x, 0.0, 1.0, 0.0, y, 0.0, 0.0, 1.0, z, 0.0, 0.0, 0.0, 1.0);
	*this = Multiply(*new_matrix);
}

/*

|  a  b  c  d  |
|              |
|  e  f  g  h  |
|              |
|  i  j  k  l  |
|              |
|  m  n  o  p  |

*/