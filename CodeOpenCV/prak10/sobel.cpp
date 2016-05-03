#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int xGradient(Mat image, int x, int y)
{
    return
            image.at<uchar>(y-1,x-1)
            + 0*image.at<uchar>(y,x-1)
                    + 0*image.at<uchar>(y-1,x)
                        - image.at<uchar>(y, x);
}

int yGradient(Mat image, int x, int y)
{
    return
            0*image.at<uchar>(y-1,x-1)
            + image.at<uchar>(y-1,x)
                    - image.at<uchar>(y-1,x)
                        + 0*image.at<uchar>(y, x);
}

int xGradientPreewit(Mat image, int x, int y)
{
    return
            image.at<uchar>(y-1,x-1)
            + image.at<uchar>(y,x-1)
                + image.at<uchar>(y+1,x-1)
                    - image.at<uchar>(y-1,x+1)
                        - image.at<uchar>(y, x+1)
                            - image.at<uchar>(y+1,x+1);
}

int yGradientPreewit(Mat image, int x, int y)
{
    return
            image.at<uchar>(y-1,x-1)
            + image.at<uchar>(y-1,x)
                + image.at<uchar>(y-1,x+1)
                    - image.at<uchar>(y+1,x-1)
                        - image.at<uchar>(y+1, x)
                            - image.at<uchar>(y+1,x+1);
}

int xGradientSobel(Mat image, int x, int y)
{
    return
            image.at<uchar>(y-1,x-1)
            + 2*image.at<uchar>(y,x-1)
                + image.at<uchar>(y+1,x-1)
                    - image.at<uchar>(y-1,x+1)
                        - 2*image.at<uchar>(y, x+1)
                            - image.at<uchar>(y+1,x+1);
}

int yGradientSobel(Mat image, int x, int y)
{
    return
            image.at<uchar>(y-1,x-1)
            + 2*image.at<uchar>(y-1,x)
                + image.at<uchar>(y-1,x+1)
                    - image.at<uchar>(y+1,x-1)
                        - 2*image.at<uchar>(y+1, x)
                            - image.at<uchar>(y+1,x+1);
}
int main()
{
    Mat src, dst;
    int gx, gy, sum;

    //load an image
    src = imread("contoh.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    dst = src.clone();

    if(!src.data)
    {
        return -1;
    }

        for(int y=0; y<src.rows; y++)
            for(int x=0; x<src.cols; x++)
                dst.at<uchar>(y,x) = 0.0;
        
        for(int y=1;y<src.rows-1;y++){
			for(int x=1;x<src.cols-1;x++){
				gx = xGradient(src,x,y);
				gy = yGradient(src,x,y);
				
				sum = abs(gx) + abs(gy);
				
				sum = sum > 255 ? 255:sum;
				sum = sum < 0 ? 0 : sum;
				/* bentuk diatas sama dengan
				 * if(sum>255){
				 * 	sum = 255;
				 * }else{
				 *  sum = sum;
				 * }
				 */
				dst.at<uchar>(y,x) = sum;
			}
		}
		
		namedWindow("final");
		imshow("final",dst);
		
		namedWindow("initial");
		imshow("initial",src);
	
	waitKey();
    return 0;
    
}
