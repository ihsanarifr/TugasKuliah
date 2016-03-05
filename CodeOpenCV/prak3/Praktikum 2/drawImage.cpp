#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp" 
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;


int main()
{
	IplImage* DrawHistogram(CvHistogram *hist, float scaleX=5, float scaleY=5)
	
    float histMax = 0;
    cvGetMinMaxHistValue(hist, 0, &histMax, 0, 0);

    IplImage* imgHist = cvCreateImage(cvSize(256*scaleX,64*scaleY), 8 ,1);
    cvZero(imgHist);

    for(int i=0; i<255; i++)
    {
        float histValue = cvQueryHistValue_1D(hist, i);
        float nextValue = cvQueryHistValue_1D(hist, i+1);

        CvPoint pt1 = cvPoint(i*scaleX, 64*scaleY);
        CvPoint pt2 = cvPoint(i*scaleX+scaleX, 64*scaleY);
        CvPoint pt3 = cvPoint(i*scaleX+scaleX, (64-nextValue*64/histMax)*scaleY);
        CvPoint pt4 = cvPoint(i*scaleX, (64-histValue*64/histMax)*scaleY);

        int numPts = 5;
        CvPoint pts[] = {pt1, pt2, pt3, pt4, pt1};

        cvFillConvexPoly(imgHist, pts, numPts, cvScalar(255));
    }

    return imgHist;
}
