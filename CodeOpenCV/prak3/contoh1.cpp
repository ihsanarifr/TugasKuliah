#include <iostream>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp" 
#include "opencv2/highgui/highgui.hpp"
 
using namespace std;
using namespace cv;

int main()
{
	//membaca citra bernama citra.tif
    IplImage* image1 = cvLoadImage("mobil.jpg");
    IplImage* image2 = cvLoadImage("output_citra.jpg");
    
    
    //IPL_DEPPTH_8U = tipe data integer 8 bit
    //Menggunakan 3 layer (RGB)
    IplImage* result = cvCreateImage(cvGetSize(image1),IPL_DEPTH_8U, 3);
    
    cvAdd(image1, image2, result);
    
    cvNamedWindow("Image Original", CV_WINDOW_AUTOSIZE);
    cvShowImage("Original",result);
    cvWaitKey(0);    

}
