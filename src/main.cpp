#include "unionFind.h"
#include "create_rect.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{

	Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    std::vector<Rectangle>  rect_vec = create_rect(image,8);
    
    cout<<rect_vec[0].eigen_vecs[0]<<endl;
    cout<<rect_vec[0].eigen_vecs[1]<<endl;

    for (int i = 0; i < rect_vec.size(); ++i){
    	cv::Point rect_points[1][4];

    	// rect_points[0][0] = cv::Point( rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].min_x , rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].min_y);
    	// rect_points[0][1] = cv::Point( rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].max_x , rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].min_y);
    	// rect_points[0][2] = cv::Point( rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].max_x , rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].max_y);
    	// rect_points[0][3] = cv::Point( rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].min_x , rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].max_y);

    	Point2d pt1 = rect_vec[i].center + rect_vec[i].max_x * rect_vec[i].eigen_vecs[0] + rect_vec[i].max_y*rect_vec[i].eigen_vecs[1]; 
    	Point2d pt2 = rect_vec[i].center + rect_vec[i].min_x * rect_vec[i].eigen_vecs[0] + rect_vec[i].max_y*rect_vec[i].eigen_vecs[1]; 
    	Point2d pt3 = rect_vec[i].center + rect_vec[i].min_x * rect_vec[i].eigen_vecs[0] + rect_vec[i].min_y*rect_vec[i].eigen_vecs[1]; 
    	Point2d pt4 = rect_vec[i].center + rect_vec[i].max_x * rect_vec[i].eigen_vecs[0] + rect_vec[i].min_y*rect_vec[i].eigen_vecs[1]; 

    	rect_points[0][0] = pt1;
    	rect_points[0][1] = pt2;
    	rect_points[0][2] = pt3;
    	rect_points[0][3] = pt4;


    	// rect_points[0][0] = cv::Point( rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].min_y , rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].min_x );
    	// rect_points[0][1] = cv::Point( rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].min_y , rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].max_x );
    	// rect_points[0][2] = cv::Point( rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].max_y , rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].max_x );
    	// rect_points[0][3] = cv::Point( rect_vec[i].center.y + rect_vec[i].eigen_vecs[1].y * rect_vec[i].max_y , rect_vec[i].center.x + rect_vec[i].eigen_vecs[0].x * rect_vec[i].min_x );

    	const cv::Point* ppt[1] = { rect_points[0] };
    	int npt[] = { 4 };

    	cv::fillPoly(image, ppt, npt, 1, cv::Scalar( 255, 255, 255 ), 8 );
    	rect_vec[i].print();
    }
	// unionFind grid(image);
	// grid.segment();
	// Mat output = grid.getMembership();
	imwrite("output.png",image);

	// std::cout<<labels;



	return 0;
}