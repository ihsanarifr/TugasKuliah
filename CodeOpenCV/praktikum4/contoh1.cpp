#include <cv.h>
#include <highgui.h>
#include <cxcore.h>

using namespace std;
using namespace cv;

int main()
{
    // source -> gambar sumber
    Mat src = imread("image.png",CV_LOAD_IMAGE_COLOR);

    Mat dst; // destination -> untuk menampung gambar

    // untuk mengecek ketersediaan gambar
    if(! src.data)
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // Blur filter
    blur(src,dst, Size(3,3),Point(-1,-1));
    imshow("source",src);
    imshow("media",dst);

    //gaussian filter
    GaussianBlur(src,dst,Size(5,5),0,0);
    imshow("source",src);
    imshow("gaussian",dst);

    waitKey(0);
}
