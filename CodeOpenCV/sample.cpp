#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>

using namespace std;
using namespace cv;

int main()
{
    Mat image;// new blank image
    image = imread("ipb.png");// read the file
    namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// create a window for display.
    imshow( "Display window", image );// show our image inside it.
    waitKey(0);// wait for a keystroke in the window
    return 0;
}
