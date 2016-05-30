#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
 
using namespace std;
using namespace cv;
 
 
int main()
{
    CvMat *cvMat = cvLoadImageM("mobil.jpg", CV_LOAD_IMAGE_GRAYSCALE); 
    
    
    CvMat *out = cvCreateMat(cvMat->rows, cvMat -> cols, cvMat->type ); 
    for (int i = 0;i< cvMat->rows; i++)
	{ 
		for (int j=0; j<cvMat->cols; j++)
		{ 
			cvSetReal2D(out, i, j, (255-cvGetReal2D(cvMat, i, j)));
		 } 
	} 
	
	cvShowImage("Hasil", out); 
	cvWaitKey(0); 
	cvReleaseMat(&cvMat); 
	cvReleaseMat(&out); 
	return 0; 
    
    
}
