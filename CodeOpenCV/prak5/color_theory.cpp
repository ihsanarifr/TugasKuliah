/**
    Programmed by Nino Tannio - G64134046
    Ilmu Komputer IPB
**/

#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace std;

int main()
{
    CvMat* img = 
        cvLoadImageM("...", CV_LOAD_IMAGE_UNCHANGED);
    CvMat* imgHSV = 
        cvCreateMat(img->height, img->width,CV_8UC3);
    CvMat* imgCieLab = 
        cvCreateMat(img->height, img->width,CV_8UC3);
    CvMat* imgYCbCr = 
        cvCreateMat(img->height, img->width,CV_8UC3);


    awal:
    cout << "Pilihan Color: \n";
    cout << "1. RGB(Original)\n"
         << "2. HSV\n"
         << "3. CieLab\n"
         << "4. YCbCr\n"
         << "5. Quit\n";
    int pilihan;
    cin >> pilihan;
    switch(pilihan){
        case 1:
            cvShowImage("RGB", img);
            cvWaitKey();
            system("cls");
            goto awal;
        case 2:
            cvCvtColor(img, imgHSV, CV_BGR2HSV);
            cvShowImage("HSV OpenCV", imgHSV);
            cvWaitKey();
            system("cls");
            goto awal;
        case 3:
            cvCvtColor(img, imgCieLab, CV_BGR2Lab);
            cvShowImage("Cie Lab OpenCV", imgCieLab);
            cvWaitKey();
            system("cls");
            goto awal;
        case 4:
            cvCvtColor(img, imgYCbCr, CV_BGR2YCrCb);
            cvShowImage("YCbCr OpenCV", imgYCbCr);
            cvWaitKey();
            system("cls");
            goto awal;
        case 5:
            system("exit");
        default: break;
            goto awal;
    }

    return 0;
}
