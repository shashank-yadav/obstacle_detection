#include "unionFind.h"
#include "create_rect.h"

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{

	Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    std::vector<Rectangle>  rect_vec = create_rect(image,8);

    for (int i = 0; i < rect_vec.size(); ++i){
    	rect_vec[i].print();
    }
	// unionFind grid(image);
	// grid.segment();
	// Mat output = grid.getMembership();
	// imwrite("output.png",output);

	// std::cout<<labels;



	return 0;
}