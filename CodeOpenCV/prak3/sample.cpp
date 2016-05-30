#include <iostream> 
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp" 
#include "opencv2/highgui/highgui.hpp" 

using namespace std; 
using namespace cv; 

int main() { 
	Mat image;// new blank 
	image image = imread("image.jpg");// read the file 
	namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// create a window for display. 
	imshow( "Display window", image );// show our image inside it. 
	waitKey(0);// wait for a keystroke in the window 
	return 0; 
}
