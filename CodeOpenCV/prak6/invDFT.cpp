#include "opencv2/highgui/highhui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	// read image from file
	// make sure that the image is in grayscale
	Mat img = imread("...",0);
	
	Mat planes[] = {Mat_<float>(img),
			Mat::zeros(img.size(),CV_32F)};
	Mat complexI; // complex plane to contain the
	merge(planes,2,complexI);
	dft(complexI,complexI); // applying DFT
	
	// reconstructing original imae from the DFT
	Mat invDFT, invDFTcvt;
	idft(complexI, invDFT, DFT_SCALE | DFT_REAL_OUTPUT
	invDFT.convertTo(invDFTcvt,CV_8U);
	imshow("output",invDFTcvt);
	
	// show the image
	imshow("Original Image",img);
	
	// wait until user press some key
	waitKey(0);
	return 0;
}
