class ConstMatrix1x4
{
public:
	ConstMatrix1x4(double matrix_a_component, double matrix_b_component, double matrix_c_component, double matrix_d_component);

	double a, b, c, d;
};

class Matrix1x4
{
public:
	Matrix1x4(double matrix_a_component, double matrix_b_component, double matrix_c_component, double matrix_d_component);
	Matrix1x4(int matrix_mode);

	double a, b, c, d;
};

class Matrix4x4
{
public:
	Matrix4x4(double matrix_a_component, double matrix_b_component, double matrix_c_component, double matrix_d_component, double matrix_e_component, double matrix_f_component, double matrix_g_component, double matrix_h_component, double matrix_i_component, double matrix_j_component, double matrix_k_component, double matrix_l_component, double matrix_m_component, double matrix_n_component, double matrix_o_component, double matrix_p_component);
	Matrix4x4(int matrix_mode);
	ConstMatrix1x4 Multiply(ConstMatrix1x4 matrix);
	Matrix1x4 Multiply(Matrix1x4 matrix);
	Matrix4x4 Multiply(Matrix4x4 matrix);
	void RotateX(double angle);
	void RotateY(double angle);
	void RotateZ(double angle);
	void Scale(double x, double y, double z);
	void Translate(double x, double y, double z);

	double a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
};
/*

|  a  b  c  d  |
|              |
|  e  f  g  h  |
|              |
|  i  j  k  l  |
|              |
|  m  n  o  p  |

*/