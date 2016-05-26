#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;


Mat ProcessHoughLines(Mat src)
{
    Mat dst, cdst;

    Canny(src, dst, 50, 200, 3);
    cvtColor(dst, cdst, CV_GRAY2BGR);

    vector<Vec2f> lines, lines2;
    //detect lines
    HoughLines(dst, lines, 1, CV_PI/180, 150, 0, 0);

    //draw lines
    for(size_t i = 0; i<lines.size();i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
            pt1.x = cvRound(x0 + 1000*(-b));
            pt1.y = cvRound(y0 + 1000*(a));
            pt2.x = cvRound(x0 - 1000*(-b));
            pt2.y = cvRound(y0 - 1000*(a));
        line(cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
    }
    return cdst;
}

Mat ProcessHoughCircle(Mat src)
{
    Mat dst, cdst;
    //reduce the noise so we avoid false circle detection
    GaussianBlur(src, dst, Size(9,9), 2,2);
    cvtColor(dst, cdst, CV_GRAY2BGR);

    vector<Vec3f> circles;

    //Apply the hough transform to find the circles
    HoughCircles(dst, circles, CV_HOUGH_GRADIENT, 1, 30, 200, 50, 0, 0);

    //draw the circles detected
    for(size_t i = 0; i< circles.size(); i++)
    {
        Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(src, center, 3, Scalar(0,255,0), -1, 8, 0);
        circle(src, center, radius, Scalar(0,0,255), 3, 8, 0);
        cout << "center :" << center << "\nradius :" << radius <<endl;
    }
    return src;
}

int main()
{
    Mat src = imread("contoh2.jpg", 0);
    if(!src.data){
        return -1;
    }

    cout << "Pilihan transform:\n"
         << "1. Hough Transform Line\n"
         << "2. Hough Transform Circle\n";

    int pilihan;
    cin >> pilihan;

    Mat resultHoughLine, resultHoughCircle;

    switch(pilihan){
    case 1:
        resultHoughLine = ProcessHoughLines(src);
        imshow("Original", src);
        imshow("Hough Line", resultHoughLine);
        break;
    case 2:
        resultHoughCircle = ProcessHoughCircle(src);
        imshow("Original", src);
        imshow("Hough Circle", resultHoughCircle);
        break;

    }
    waitKey();
    return 0;
}
