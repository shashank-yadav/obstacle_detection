#include <opencv2/opencv.hpp>
#include <vector>
#include <utility>

class unionFind
{

	cv::Mat occupancy;
	std::vector<int> rank , parent;

public:
	
	unionFind(cv::Mat occupancy);
	
	unionFind();
	~unionFind();

	int oneD(int i, int j);
	
	std::pair<int,int> twoD(int n);

	void readMat(cv::Mat occupancy );
		
	int findSet(int i, int j);
	
	void unionSet(int i1 , int i2 , int j1 , int j2 );
	
};