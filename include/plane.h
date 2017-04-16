#include <opencv2/opencv.hpp>
#include <cmath>

using namespace std;
using namespace cv;

struct ray_t
{
	Point3d pt;
	Point3d direction;
};

class plane_t
{

//Assuming continuius orientation of points
vector<Point3d> pts;

public:
	plane_t();
	~plane_t();
	//gives -1 if no intersection with plane, otherwiese distance of camera center from point of intersection
	double intersection(ray_t ray );
	
};