#include "Collisions.h"
#include <math.h>

bool IsIntersectionLineAndTriangle(double line_x1, double line_y1, double line_z1, double line_x2, double line_y2, double line_z2, double triangle_x1, double triangle_y1, double triangle_z1, double triangle_x2, double triangle_y2, double triangle_z2, double triangle_x3, double triangle_y3, double triangle_z3)
{
	double point_of_intersect_x, point_of_intersect_y, point_of_intersect_z;
	PointOfIntersectionLineAndPlane(line_x1, line_y1, line_z1, line_x2, line_y2, line_z2, triangle_x1, triangle_y1, triangle_z1, triangle_x2, triangle_y2, triangle_z2, triangle_x3, triangle_y3, triangle_z3, &point_of_intersect_x, &point_of_intersect_y, &point_of_intersect_z);
	return IsPointInTriangle(point_of_intersect_x, point_of_intersect_y, point_of_intersect_z, triangle_x1, triangle_y1, triangle_z1, triangle_x2, triangle_y2, triangle_z2, triangle_x3, triangle_y3, triangle_z3);
}

bool IsIntersectionLineAndTriangle(double line_x1, double line_y1, double line_z1, double line_x2, double line_y2, double line_z2, double triangle_x1, double triangle_y1, double triangle_z1, double triangle_x2, double triangle_y2, double triangle_z2, double triangle_x3, double triangle_y3, double triangle_z3, double* return_x, double* return_y, double* return_z)
{
	double point_of_intersect_x, point_of_intersect_y, point_of_intersect_z;
	PointOfIntersectionLineAndPlane(line_x1, line_y1, line_z1, line_x2, line_y2, line_z2, triangle_x1, triangle_y1, triangle_z1, triangle_x2, triangle_y2, triangle_z2, triangle_x3, triangle_y3, triangle_z3, &point_of_intersect_x, &point_of_intersect_y, &point_of_intersect_z);

	*return_x = point_of_intersect_x;
	*return_y = point_of_intersect_y;
	*return_z = point_of_intersect_z;

	return IsPointInTriangle(point_of_intersect_x, point_of_intersect_y, point_of_intersect_z, triangle_x1, triangle_y1, triangle_z1, triangle_x2, triangle_y2, triangle_z2, triangle_x3, triangle_y3, triangle_z3);
}

bool IsPointInTriangle(double point_x, double point_y, double point_z, double triangle_x1, double triangle_y1, double triangle_z1, double triangle_x2, double triangle_y2, double triangle_z2, double triangle_x3, double triangle_y3, double triangle_z3)
{
	double ab_ac, bc_ba, ab_an, ac_an, bc_bn, ba_bn;
	ab_ac = acos(((triangle_x2 - triangle_x1) * (triangle_x3 - triangle_x1) + (triangle_y2 - triangle_y1) * (triangle_y3 - triangle_y1) + (triangle_z2 - triangle_z1) * (triangle_z3 - triangle_z1)) / (sqrt(pow((triangle_x2 - triangle_x1), 2) + pow((triangle_y2 - triangle_y1), 2) + pow((triangle_z2 - triangle_z1), 2)) * sqrt(pow((triangle_x3 - triangle_x1), 2) + pow((triangle_y3 - triangle_y1), 2) + pow((triangle_z3 - triangle_z1), 2))));
	bc_ba = acos(((triangle_x3 - triangle_x2) * (triangle_x1 - triangle_x2) + (triangle_y3 - triangle_y2) * (triangle_y1 - triangle_y2) + (triangle_z3 - triangle_z2) * (triangle_z1 - triangle_z2)) / (sqrt(pow((triangle_x3 - triangle_x2), 2) + pow((triangle_y3 - triangle_y2), 2) + pow((triangle_z3 - triangle_z2), 2)) * sqrt(pow((triangle_x1 - triangle_x2), 2) + pow((triangle_y1 - triangle_y2), 2) + pow((triangle_z1 - triangle_z2), 2))));
	ab_an = acos(((triangle_x2 - triangle_x1) * (point_x - triangle_x1) + (triangle_y2 - triangle_y1) * (point_y - triangle_y1) + (triangle_z2 - triangle_z1) * (point_z - triangle_z1)) / (sqrt(pow((triangle_x2 - triangle_x1), 2) + pow((triangle_y2 - triangle_y1), 2) + pow((triangle_z2 - triangle_z1), 2)) * sqrt(pow((point_x - triangle_x1), 2) + pow((point_y - triangle_y1), 2) + pow((point_z - triangle_z1), 2))));
	ac_an = acos(((triangle_x3 - triangle_x1) * (point_x - triangle_x1) + (triangle_y3 - triangle_y1) * (point_y - triangle_y1) + (triangle_z3 - triangle_z1) * (point_z - triangle_z1)) / (sqrt(pow((triangle_x3 - triangle_x1), 2) + pow((triangle_y3 - triangle_y1), 2) + pow((triangle_z3 - triangle_z1), 2)) * sqrt(pow((point_x - triangle_x1), 2) + pow((point_y - triangle_y1), 2) + pow((point_z - triangle_z1), 2))));
	bc_bn = acos(((triangle_x3 - triangle_x2) * (point_x - triangle_x2) + (triangle_y3 - triangle_y2) * (point_y - triangle_y2) + (triangle_z3 - triangle_z2) * (point_z - triangle_z2)) / (sqrt(pow((triangle_x3 - triangle_x2), 2) + pow((triangle_y3 - triangle_y2), 2) + pow((triangle_z3 - triangle_z2), 2)) * sqrt(pow((point_x - triangle_x2), 2) + pow((point_y - triangle_y2), 2) + pow((point_z - triangle_z2), 2))));
	ba_bn = acos(((triangle_x1 - triangle_x2) * (point_x - triangle_x2) + (triangle_y1 - triangle_y2) * (point_y - triangle_y2) + (triangle_z1 - triangle_z2) * (point_z - triangle_z2)) / (sqrt(pow((triangle_x1 - triangle_x2), 2) + pow((triangle_y1 - triangle_y2), 2) + pow((triangle_z1 - triangle_z2), 2)) * sqrt(pow((point_x - triangle_x2), 2) + pow((point_y - triangle_y2), 2) + pow((point_z - triangle_z2), 2))));
	return (ab_an <= ab_ac && ac_an <= ab_ac && bc_bn <= bc_ba && ba_bn <= bc_ba);
}

void PointOfIntersectionLineAndPlane(double line_x1, double line_y1, double line_z1, double line_x2, double line_y2, double line_z2, double plane_x1, double plane_y1, double plane_z1, double plane_x2, double plane_y2, double plane_z2, double plane_x3, double plane_y3, double plane_z3, double* return_x, double* return_y, double* return_z)
{
	double plane_a_parameter, plane_b_parameter, plane_c_parameter, plane_d_parameter;;
	plane_a_parameter = (plane_z1 - plane_z2) * (plane_y2 - plane_y3) + (plane_z2 - plane_z3) * (plane_y2 - plane_y1);//y2 - y3 or y3 - y2 need to replace
	plane_b_parameter = (plane_z1 - plane_z2) * (plane_x3 - plane_x2) + (plane_z2 - plane_z3) * (plane_x1 - plane_x2);
	plane_c_parameter = (plane_y2 - plane_y1) * (plane_x3 - plane_x2) + (plane_y3 - plane_y2) * (plane_x1 - plane_x2);//y2 - y3 or y3 - y2 need to replace
	plane_d_parameter = -plane_a_parameter * plane_x1 - plane_b_parameter * plane_y1 - plane_c_parameter * plane_z1;

	*return_x = (-plane_d_parameter * (line_x1 - line_x2) - plane_b_parameter * (line_y1 * (line_x1 - line_x2) - line_x1 * (line_y1 - line_y2)) - plane_c_parameter * (line_z1 * (line_x1 - line_x2) - line_x1 * (line_z1 - line_z2))) / (plane_a_parameter * (line_x1 - line_x2) + plane_b_parameter * (line_y1 - line_y2) + plane_c_parameter * (line_z1 - line_z2));
	*return_y = (-plane_d_parameter * (line_y1 - line_y2) - plane_a_parameter * (line_x1 * (line_y1 - line_y2) - line_y1 * (line_x1 - line_x2)) - plane_c_parameter * (line_z1 * (line_y1 - line_y2) - line_y1 * (line_z1 - line_z2))) / (plane_a_parameter * (line_x1 - line_x2) + plane_b_parameter * (line_y1 - line_y2) + plane_c_parameter * (line_z1 - line_z2));
	*return_z = (-plane_d_parameter * (line_z1 - line_z2) - plane_a_parameter * (line_x1 * (line_z1 - line_z2) - line_z1 * (line_x1 - line_x2)) - plane_b_parameter * (line_y1 * (line_z1 - line_z2) - line_z1 * (line_y1 - line_y2))) / (plane_a_parameter * (line_x1 - line_x2) + plane_b_parameter * (line_y1 - line_y2) + plane_c_parameter * (line_z1 - line_z2));
}

void PointOfIntersectionLineAndPlane(double line_x1, double line_y1, double line_z1, double line_x2, double line_y2, double line_z2, double plane_a_parameter, double plane_b_parameter, double plane_c_parameter, double plane_d_parameter, double* return_x, double* return_y, double* return_z)
{
	*return_x = (-plane_d_parameter * (line_x1 - line_x2) - plane_b_parameter * (line_y1 * (line_x1 - line_x2) - line_x1 * (line_y1 - line_y2)) - plane_c_parameter * (line_z1 * (line_x1 - line_x2) - line_x1 * (line_z1 - line_z2))) / (plane_a_parameter * (line_x1 - line_x2) + plane_b_parameter * (line_y1 - line_y2) + plane_c_parameter * (line_z1 - line_z2));
	*return_y = (-plane_d_parameter * (line_y1 - line_y2) - plane_a_parameter * (line_x1 * (line_y1 - line_y2) - line_y1 * (line_x1 - line_x2)) - plane_c_parameter * (line_z1 * (line_y1 - line_y2) - line_y1 * (line_z1 - line_z2))) / (plane_a_parameter * (line_x1 - line_x2) + plane_b_parameter * (line_y1 - line_y2) + plane_c_parameter * (line_z1 - line_z2));
	*return_z = (-plane_d_parameter * (line_z1 - line_z2) - plane_a_parameter * (line_x1 * (line_z1 - line_z2) - line_z1 * (line_x1 - line_x2)) - plane_b_parameter * (line_y1 * (line_z1 - line_z2) - line_z1 * (line_y1 - line_y2))) / (plane_a_parameter * (line_x1 - line_x2) + plane_b_parameter * (line_y1 - line_y2) + plane_c_parameter * (line_z1 - line_z2));
}