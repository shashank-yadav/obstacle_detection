#include <vector>
#include <limits>
#include <opencv2/opencv.hpp>
#include <algorithm>

// #define INT_MAX std::numeric_limits<int>::max();
// #define INT_MIN std::numeric_limits<int>::min();

using namespace cv;
using namespace std;


struct Rectangle
{
	double min_x , min_y; 
	double max_x , max_y;
	vector<Point2d> eigen_vecs;
	Point2d center;

	Rectangle(){
		min_x = (double)INT_MAX;
		min_y = (double)INT_MAX;
		max_x = (double)INT_MIN;
		max_y = (double)INT_MIN;
	}

	void print(){
		cout<<center<<endl;
    	cout<<eigen_vecs[0]<<" "<<min_x<<" "<<max_x<<endl;
    	cout<<eigen_vecs[1]<<" "<<min_y<<" "<<max_y<<endl;
    	cout<<endl;
	}
};

std::vector<Rectangle> create_rect(Mat &image, const int n_clusters);

Rectangle get_orientation(std::vector<Point2i> pts);