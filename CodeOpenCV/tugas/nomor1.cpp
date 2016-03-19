#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
 
using namespace std;
using namespace cv;
 
 
int main()
{
    // Read image
	Mat src = imread("image.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	 
	// Set threshold and maxValue
	double thresh = 0;
	double maxValue = 255; 
	 
	// Binary Threshold
	threshold(src,dst, thresh, maxValue, THRESH_BINARY);
	
	//cvShowImage("Hasil", dst); 
	imshow("Hasil",dst);
	cvWaitKey(0); 
	return 0;  
}
