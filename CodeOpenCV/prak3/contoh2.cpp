#include <iostream>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp" 
#include "opencv2/highgui/highgui.hpp"
 
using namespace std;
using namespace cv;

Mat img1, img2, img3, hasil;

int main()
{
	//membaca citra bernama citra.tif
    img1 = imread("image.jpg");
    img2 = imread("image2.jpg");
    
    img3 = img2*1.618;
    
    add(img1,img3,hasil);
    
    namedWindow("Original",CV_WINDOW_AUTOSIZE);
    imshow("Original",img1);
    
    namedWindow("Hasil",CV_WINDOW_AUTOSIZE);
    imshow("Hasil",hasil);
    
    waitKey();
    system("cls");
    return 0;
}
