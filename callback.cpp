#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include<stdio.h>

using namespace cv;
using namespace std;

Mat img = imread("joker.jpg", 1);

void Callbackfunc(int Event, int y, int x, int flags, void* userdata)
{
	if (Event == EVENT_RBUTTONDOWN)
	{
		printf("B=%d\n", img.at<Vec3b>(x, y)[0]);
		printf("G=%d\n", img.at<Vec3b>(x, y)[1]);
		printf("R=%d\n\n", img.at<Vec3b>(x, y)[2]);
		

	}
}



int main()
{
	
    namedWindow("original", WINDOW_AUTOSIZE);

	imshow("original", img);
	setMouseCallback("original", Callbackfunc, NULL);

	waitKey(0);
}
