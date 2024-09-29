#include <iostream>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

string windowName = "Resize Image";
string imageWindow = "imageWindow";

int outLower = 0;
int outUpper = 100;
int inLower = 0;
int inUpper = 255;

int rowsOut = 200;
int colsOut = 200;
double insideImageProportion = 0.75;
int rowsIn = rowsOut * insideImageProportion;
int colsIn = colsOut * insideImageProportion;

int size = 200;

cv::Mat outsideImg = cv::Mat::zeros(rowsOut, colsOut, CV_8U);
cv::Mat insideImg = cv::Mat::zeros(rowsIn, colsIn, CV_8U);

void changeImageParams(int, void*);

int main(void)
{
    //namedWindow(windowName, WINDOW_NORMAL);
    namedWindow(windowName, WINDOW_AUTOSIZE);
    createTrackbar("Out min", windowName, &outLower, 255, changeImageParams);
    createTrackbar("Out max", windowName, &outUpper, 255, changeImageParams);
    createTrackbar("In min", windowName, &inLower, 255, changeImageParams);
    createTrackbar("In max", windowName, &inUpper, 255, changeImageParams);
    createTrackbar("size", windowName, &size, 500, changeImageParams);
    changeImageParams(0,0);
    while (true){
	int c;
	c = waitKey(20);
	if (static_cast<char>(c) == 27)
	    break;
    }  
}

void changeImageParams(int, void*)
{
    RNG rng;
    Mat out = cv::Mat::zeros(1, 1, CV_8U);
    Mat empty = cv::Mat::zeros(1, 1, CV_8U);
    rng.fill(insideImg,RNG::UNIFORM,inLower,inUpper);
    rng.fill(outsideImg,RNG::UNIFORM,outLower,outUpper);
    int centerRow=(rowsOut-rowsIn)/2;
    int centerCol=(colsOut-colsIn)/2;
    // insideImg.copyTo(outsideImg(Range(rowsIn/2,rowsIn*1.5),Range(colsIn/2,colsIn*1.5)));
    insideImg.copyTo(outsideImg(Range(centerRow,centerRow+rowsIn),Range(centerCol,centerCol+colsIn)));
    if(size > 0){
	resize(outsideImg, out, Size(size,size), INTER_LINEAR);
	
    }
    imshow(windowName, out);
    //imshow(windowName, empty);
}
