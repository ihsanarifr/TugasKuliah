#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

double alpha; /**< Simple contrast control */
int beta;  /**< Simple brightness control */

int main( int argc, char** argv )
{
 /// Read image given by user
 Mat image = imread("image.jpg", CV_LOAD_IMAGE_COLOR);
 Mat new_image = Mat::zeros( image.size(), image.type() );

 /// Initialize values
 std::cout<<"* Alpha value [1.0-3.0]: ";std::cin>>alpha;
 std::cout<<"* Beta value [0-100]: "; std::cin>>beta;

 /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
 for( int y = 0; y < image.rows; y++ )
    { for( int x = 0; x < image.cols; x++ )
         { for( int c = 0; c < 3; c++ )
              {
      new_image.at<Vec3b>(y,x)[c] =
         saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
             }
    }
    }

 /// Create Windows
 namedWindow("Original Image", 1);
 namedWindow("Contrast Image", 1);

 /// Show stuff
 imshow("Original Image", image);
 imshow("Contrast Image", new_image);

 /// Wait until user press some key
 waitKey();
 return 0;
}
