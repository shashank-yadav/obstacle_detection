#include "unionFind.h"

unionFind::unionFind()
{}
unionFind::~unionFind()
{}

unionFind::unionFind(cv::Mat occupancy)
{
	this->occupancy = occupancy;
	this->rank.resize(occupancy.cols*occupancy.rows);
	this->parent.resize(occupancy.cols*occupancy.rows);

	for(int i=0 ; i < parent.size() ; i++){
		rank[i] = 0;
		parent[i] = i;
	} 
}



int unionFind::oneD(int i, int j)
{
return i + occupancy.rows*j;
}

std::pair<int,int> unionFind::twoD(int n)
{
	return std::make_pair(n%occupancy.rows , n/occupancy.cols);
}

void unionFind::readMat(cv::Mat occupancy)
{
	this->occupancy = occupancy;
	this->rank.resize(occupancy.cols*occupancy.rows);
	this->parent.resize(occupancy.cols*occupancy.rows);

	for(int i=0 ; i < parent.size() ; i++){
		rank[i] = 0;
		parent[i] = i;
	} 

}

int unionFind::findSet(int i, int j)
{
	int n = oneD(i,j);
	std::pair<int,int> p = twoD(parent[n]);
	return (parent[n] == n) ? n : parent[n] = findSet(p.first,p.second); 
}


void unionFind::unionSet(int i1, int j1, int i2 , int j2 )
{
	int x = findSet(i1,j1);
	int y = findSet(i2,j2);

	if ( x != y )
	{
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