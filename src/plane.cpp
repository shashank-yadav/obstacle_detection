#include "plane.h"

double plane_t::intersection(ray_t ray)
{
	Point3d line_vec1 = pts[1] - pts[0];
	Point3d line_vec2 = pts[2] - pts[1];

	Point3d plane = line_vec1.cross(line_vec2);

	double D = plane.ddot(pts[0]);
	double t = -1*(D+plane.ddot(ray.pt)) / plane.ddot(ray.direction);

	Point3d intersec_point = ray.pt + t*ray.direction;

	vector<Point2d> proj_contours;
	for (int i = 0; i < 4; ++i){
		proj_contours.push_back( Point2d(pts[i].x , pts[i].y) );
	}

	Point2d proj_intersec_point = Point2d(intersec_point.x , intersec_point.y);

	double isInside = pointPolygonTest( proj_contours, proj_intersec_point, false );
	
	if (isInside <= 0){
		return -1;
	}
	else
	{
		return abs(intersec_point.ddot(intersec_point));
	}
}