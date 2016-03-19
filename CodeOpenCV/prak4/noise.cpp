// some includes that we'll be making use of
// #include <stdafx.h>
//#include <cv.h>
//#include <highgui.h>
//#include <math.h>
//#include <float.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define human readable names please!
#define NOISE_UNIFORM 0
#define NOISE_GAUSSIAN 1
#define NOISE_EXPONENTIAL 2
#define NOISE_RAYLEIGH 3
#define NOISE_GAMMA 4
#define NOISE_IMPULSE 5 //a.k.a salt n pepper

// Generates and returns the histogram of a GRAYSCALE image
IplImage* DrawHistogram(IplImage* img)
{
    CvSize imgSize = cvGetSize(img);
    int as = imgSize.width*imgSize.height;

    // Holds the actual histogram image
    IplImage* ret = cvCreateImage(cvSize(257, 100), 8, 1);
    cvZero(ret);

    int freq[256] = {0};
    int max = 0;

    // Loop through each pixel of the image
    for(int x=0; x<imgSize.height; x++)
    {
        for(int y=0; y<imgSize.height; y++)
        {
            // Increment the frequency
            int curr = (int)cvGetReal2D(img, y, x);
            freq[curr]++;
            if(freq[curr]>max)
                max = freq[curr];
        }
    }

    // Finally, draw the actual histogram
    for(int k=0; k<256; k++)
    {
        int value = ((float)(100*freq[k])/(float)max);
        cvLine(ret, cvPoint(k, 100), cvPoint(k, 100-value),
               cvScalar(255,255,255));
    }

    cvNot(ret, ret);
    return ret;
}

// Returns a uniformly distributed random number
double uniform()
{
    return (rand()/(float)0x7fff);
}

// Returns a gaussian random number (using uniform random numbers)
double gaussian(void)
{
    static double v, fac;
    static int phase = 0;
    double s, z, U1, U2, u;

    if(phase)
        z = v*fac;
    else
    {
        do
        {
            U1 = uniform();
            U2 = uniform();

            u = 2.*U1-1.;
            v = 2.*U2-1.;
            s = u*u + v*v;
        } while (s>=1);

        fac = sqrt(-2.*log(s)/s);
        z = u*fac;
    }

    phase = 1 - phase;
    return z;
}

// Generates an exponential random number using a uniform random number
double exponential(float lambda=1)
{
    return -lambda*log(uniform());
}

// Generates a rayleigh random number using a uniform random number
double rayleigh(float sigma=1)
{
    return sigma*sqrt(-1*log(uniform()));
}

// Generates a gamma random number using a uniform random number
double gamma(int k=2)
{
    double ret=0;
    while(k>0)
    {
        ret+= (-(log(uniform())));
        k--;
    }
    return ret;
}

// Generates an impulse using a uniform random number
// thousands of other possibilities
double impulse(float amount)
{
    if(uniform()>1-amount)
        return 100;
    if(uniform()<amount)
        return -100;

    return 0;
}

// This function actually applies the specified noise to the given
// in the given amounts
IplImage* GenerateNoise(IplImage* img, int noiseType, float amount=255)
{
    CvSize imgSize = cvGetSize(img);
    IplImage* imgTemp = cvCloneImage(img); // This will hold the n

    // Go through each pixel
    for(int y=0; y<imgSize.height; y++)
    {
        for(int x=0; x<imgSize.width; x++)
        {
            int randomValue=0; // our noise is additivwe
            switch(noiseType) // the amount to add/substract
            {
            case NOISE_UNIFORM:
                randomValue = (char)(uniform()*amount);
                break;

            case NOISE_EXPONENTIAL:
                randomValue = (int)(exponential()*amount);
                break;

            case NOISE_GAUSSIAN:
                randomValue = (int)(gaussian()*amount);
                break;

            case NOISE_RAYLEIGH:
                randomValue = (int)(rayleigh()*amount);
                break;

            case NOISE_GAMMA:
                break;

            case NOISE_IMPULSE:
                randomValue = (int)(impulse((float)amount/256)*amount);
            }

            int pixelValue = cvGetReal2D(imgTemp, y, x)+randomValue;

            // And set this value in our noisy image
            cvSetReal2D(imgTemp, y, x, pixelValue);
        }
    }

    // return
    return imgTemp;
}

// the main function!!
int main()
{
    // Load the image with no noise
    IplImage* img = cvLoadImage("image.jpg", 0);
    IplImage* imgTemp;
    IplImage* imgHist;

    // The default choice
    int noiseType=NOISE_IMPULSE;

    // Initialize the window systems
    int trackPos = 20;
    cvNamedWindow("NOISE_IMPULSE");
    //cvNamedWindow("Histogram");

    imgTemp = GenerateNoise(img, noiseType, trackPos);
    imgHist = DrawHistogram(imgTemp);

    // Display it all
    cvShowImage("NOISE_IMPULSE", imgTemp);
    //cvShowImage("Histogram", imgHist);

    // filter blur
    IplImage *blur = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    IplImage *gaussian = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    IplImage *median = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
    cvSmooth(imgTemp, blur, CV_BLUR, 3);
    cvSmooth(imgTemp, gaussian, CV_GAUSSIAN, 3);
    cvSmooth(imgTemp, median, CV_MEDIAN, 3);
    cvShowImage("original", img);
    cvShowImage("blur", blur);
    cvShowImage("gaussian", gaussian);
    cvShowImage("median", median);

    // And release the images. We don't want memory leaks
    //cvReleaseImage(&imgHist);
    cvReleaseImage(&imgTemp);
    cvWaitKey(0);

    // Finaly, exit
    cvReleaseImage(&img);
    return 0;
}
