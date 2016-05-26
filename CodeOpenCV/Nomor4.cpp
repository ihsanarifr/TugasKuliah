#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main(){

   int height, width;
   
    cout << "Height : ";
    cin >> height;
    cout << "Width : ";
    cin >> width;

    Size size(height, width);

    Mat image = imread("image.jpg");
    Mat new_image;
    resize(image, new_image, size);

    namedWindow("Original Image", 1);
    imshow("Original Image", image);

    namedWindow("Cropping Result", 1);
    imshow("Cropping Result", new_image);

    waitKey();
    system("cls");
    return 1;
}

