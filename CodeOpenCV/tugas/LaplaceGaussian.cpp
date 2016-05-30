//#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
    Mat src, gray, dst, abs_dst;
    src = imread( "fokus.jpg" );
    imshow( "original", src );

    GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    cvtColor( src, gray, CV_RGB2GRAY );

    Laplacian( gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs( dst, abs_dst );
    imshow( "laplace gaussian", abs_dst );

    waitKey(0);
    return 0;
}
