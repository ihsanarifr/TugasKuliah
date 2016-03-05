#include <iostream>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp" 
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main()
{
    //membaca citra bernama
    IplImage*image1 = cvLoadImage("mobil.jpg");
    IplImage*imGray = cvCreateImage(cvGetSize(image1), IPL_DEPTH_8U, 1);

    cvCvtColor(image1,imGray,CV_RGB2GRAY);
    IplImage*im_bw = cvCreateImage(cvGetSize(imGray), IPL_DEPTH_8U, 1);

    cvThreshold(imGray,im_bw, 100, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    cvNamedWindow("image grayscale", CV_WINDOW_AUTOSIZE);
    cvShowImage("image graysclae",im_bw);
    cvWaitKey(0);

    return 0;
}
