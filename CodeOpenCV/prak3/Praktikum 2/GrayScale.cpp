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
 
    //membuat citra dengan ukuran yg sama dengan citra.tif
    IplImage* imGray = cvCreateImage(cvGetSize(image1),IPL_DEPTH_8U, 1);
 
    //konversi warna dari RGb ke Grayscale
    cvCvtColor(image1, imGray, CV_RGB2GRAY);
    //menyimpan citra
    cvSaveImage("output_citra.jpg", imGray);
 
    return 0;
}
