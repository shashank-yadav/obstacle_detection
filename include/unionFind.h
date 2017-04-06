#include <opencv2/opencv.hpp>
#include <vector>
#include <utility>
#include <iostream>

class unionFind
{

	cv::Mat occupancy;
	std::vector<int> rank , parent;

public:
	
	unionFind();
	~unionFind();

	unionFind(cv::Mat occupancy);
	
	int oneD(int i, int j);
	
	std::pair<int,int> twoD(int n);

	void readMat(cv::Mat occupancy );
		
	int findSet(int i, int j);
	
	void unionSet(int i1 , int i2 , int j1 , int j2 );

	void segment();

	cv::Mat getMembership();
	
};