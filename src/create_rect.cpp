#include "create_rect.h"

Rectangle get_orientation(std::vector<Point2i> pts , Point2d &center)
{
	//Construct a buffer used by the pca analysis
    int sz = static_cast<int>(pts.size());
    Mat data_pts = Mat(sz, 2, CV_64FC1);
    for (int i = 0; i < data_pts.rows; ++i)
    {
        data_pts.at<double>(i, 0) = pts[i].x;
        data_pts.at<double>(i, 1) = pts[i].y;
    }
    
    //Perform PCA analysis
    PCA pca_analysis(data_pts, Mat(), CV_PCA_DATA_AS_ROW);
    
    //Store the center of the object
    Point cntr = Point(static_cast<int>(pca_analysis.mean.at<double>(0, 0)),
                      static_cast<int>(pca_analysis.mean.at<double>(0, 1)));
    
    //Store the eigenvalues and eigenvectors
    vector<Point2d> eigen_vecs(2);
    vector<double> eigen_val(2);
    for (int i = 0; i < 2; ++i)
    {
        eigen_vecs[i] = Point2d(pca_analysis.eigenvectors.at<double>(i, 0),
                                pca_analysis.eigenvectors.at<double>(i, 1));
        eigen_val[i] = pca_analysis.eigenvalues.at<double>(0, i);
    }

    Rectangle rect;
    rect.eigen_vecs = eigen_vecs;
    rect.center = center;

    for (int i = 0; i < sz; ++i){
    	Point2d p = Point2d(pts[i].x , pts[i].y) - center;
    	
    	double p_axis1 = p.ddot(eigen_vecs[0]);
    	double p_axis2 = p.ddot(eigen_vecs[1]);

    	rect.min_x = std::min(rect.min_x , p_axis1);
    	rect.max_x = std::max(rect.max_x , p_axis1);

    	rect.min_y = std::min(rect.min_y , p_axis2);
    	rect.max_y = std::max(rect.max_y , p_axis2);

    }

    return rect;
}


std::vector<Rectangle> create_rect(Mat &image , const int n_clusters)
{
	cv::Mat grayImage (image.size(), CV_8U);
	cv::cvtColor( image, grayImage , CV_BGR2GRAY );
	cv::threshold(grayImage, grayImage, 100, 255, cv::THRESH_BINARY);
	
	////K Means Clustring

	int count = 0 , iter = 0;

	for (int i = 0; i < grayImage.rows; ++i){
		for (int j = 0; j < grayImage.cols; ++j){
			if (grayImage.at<uchar>(i,j) > 0)
				count ++;
		}
	}

	Mat M(count,2, CV_32F); //rows,cols
	
	for (int i = 0; i < grayImage.rows; ++i){
		for (int j = 0; j < grayImage.cols; ++j){
			if (grayImage.at<uchar>(i,j) > 0){
				M.at<float>(iter,0) = j;
				M.at<float>(iter,1) = i;
				iter ++;				
			}
		}
	}

	Mat labels , centers;
	cv::kmeans( M, n_clusters, labels ,TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0) ,100, KMEANS_PP_CENTERS, centers);
	
	////Create output image
	// Mat output = cv::Mat::zeros( image.size(), CV_8U );
	// for (int i = 0; i < count; ++i){
	// 	output.at<uchar>((int)M.at<float>(i,0), (int)M.at<float>(i,1)) = (uchar)(((labels.at<uchar>(i,0)+1)*25)%199);
	// }
	// std::cout<<centers;
	// imwrite("output.png",output);


	////PCA for all clusters
	std::vector<cv::Point2i> pts_vec[n_clusters];

	for (int i = 0; i < count; ++i){
		int x = (int)M.at<float>(i,0);
		int y = (int)M.at<float>(i,1);
		pts_vec[labels.at<uchar>(i,0)].push_back(cv::Point2i( x, y ));
	}

	std::vector<Rectangle> rect_vec;

	for (int i = 0; i < n_clusters; ++i){
		Point2d center = Point2d( (double)centers.at<float>(i,0) , (double)centers.at<float>(i,1) );
		Rectangle rect = get_orientation( pts_vec[i] , center );
		rect_vec.push_back(rect);
	}

	return rect_vec;

}
