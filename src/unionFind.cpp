#include "unionFind.h"

unionFind::unionFind(){}
unionFind::~unionFind(){}


unionFind::unionFind(cv::Mat occupancy){
	readMat(occupancy);
}


int unionFind::oneD(int i, int j){
return i + occupancy.rows*j;
}

std::pair<int,int> unionFind::twoD(int n){
	return std::make_pair(n%occupancy.rows , n/occupancy.cols);
}

void unionFind::readMat(cv::Mat occupancy){
	cv::Mat grayscaleMat (occupancy.size(), CV_8U);
	cv::cvtColor( occupancy, grayscaleMat, CV_BGR2GRAY );
	cv::threshold(grayscaleMat, grayscaleMat, 100, 255, cv::THRESH_BINARY);

	this->occupancy = grayscaleMat;
	this->rank.resize(occupancy.cols*occupancy.rows);
	this->parent.resize(occupancy.cols*occupancy.rows);

	for(int i=0 ; i < parent.size() ; i++){
		rank[i] = 0;
		parent[i] = i;
	}
	// cv:imwrite("binaryImage.png",grayscaleMat); 
}

int unionFind::findSet(int i, int j){
	int n = oneD(i,j);
	std::pair<int,int> p = twoD(parent[n]);
	return (parent[n] == n) ? n : parent[n] = findSet(p.first,p.second); 
}


void unionFind::unionSet(int i1, int j1, int i2 , int j2 ){
	int x = findSet(i1,j1), y = findSet(i2,j2);

	if ( x != y ){
		if (rank[x] > rank[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}

		if (rank[x] == rank[y]){
			rank[y]++;
		}
	}
}

void unionFind::segment(){
	
	const int dx8[8] = {-1,-1,-1, 0, 0, 1, 1, 1 };
	const int dy8[8] = {-1, 0, 1,-1, 1,-1, 0, 1 };

	for (int i = 0; i < occupancy.rows; i+=2){
		for (int j = 0; j < occupancy.cols; j+=2){
			for (int k = 0; k < 8; ++k){
				
				int x = i+dx8[k] , y = j+dy8[k];
				if (x >= 0 && x < occupancy.rows && y >= 0 && y< occupancy.cols){
					// if (  (oneD(x,y) < oneD(i,j)) && (occupancy.at<uchar>(i,j) == occupancy.at<uchar>(x,y)) )
					if (  occupancy.at<uchar>(i,j) == occupancy.at<uchar>(x,y) )
					{
						unionSet(x,y,i,j);
					}
				}
			}
		}
	}
}


cv::Mat unionFind::getMembership(){
	
	cv::Mat newMat = occupancy.clone();
	
	for (int i = 0; i < occupancy.rows; ++i){
		for (int j = 0; j < occupancy.cols; ++j){
			newMat.at<uchar>(i,j) = (uchar)(findSet(i,j)%199);
			// std::cout<<parent[oneD(i,j)]<<std::endl;
		}
	}

	return newMat;
}