// dari : http://stackoverflow.com/questions/32952577/calculating-cumulative-histogram
#include "opencv2/core/core.hpp"
#include "iostream"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

void histogramcalculation(const Mat &Image, Mat &histoImage)
{  
  int histSize = 255;
   // Set the ranges ( for B,G,R) )

  float range[] = { 0, 256 } ;
  const float* histRange = { range };
  bool uniform = true; bool accumulate = false;
  Mat b_hist, g_hist, r_hist;
  vector<Mat> bgr_planes;
  split(Image, bgr_planes );

 // Compute the histograms:

  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize,  &histRange, uniform, accumulate );


// Draw the histogram

  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );
  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  // Normalize the result to [ 0, histImage.rows ]

  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());


  // Draw 

  for( int i = 1; i < histSize; i++ )

  {
    line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>   (i-1)) ) , Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),   Scalar( 255, 0, 0), 2, 8, 0 );



  }
  histoImage= histImage;

}

int main( )
{

 Mat src, imageq,ycbcr;
 Mat histImage;

 // Read original image

 src = imread( "image.jpg");
 if(! src.data )
  { printf("Error imagen\n"); exit(1); }

cvtColor(src, ycbcr, CV_RGB2YCrCb);
vector <Mat> planes;
split(ycbcr,planes);

   // Separate the image in 3 places ( B, G and R )



    // Display results

imshow( "Source image", src );

   // Calculate the histogram to each channel of the source image

histogramcalculation(planes[0], histImage);

   // Display the histogram for each colour channel

imshow("Colour Image Histogram", histImage );

   // Wait until user exits the program
waitKey();
return 0;
}
