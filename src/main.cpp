#include "unionFind.h"

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{

	Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);


	unionFind grid(image);
	grid.segment();

	Mat output = grid.getMembership();

	imwrite("output.png",output);

	return 0;
}