#include<iostream>
#include<stdlib.h>
#include<math.h>
//#include<algorithm>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat a=imread("joker.jpg",1);
	namedWindow("Canny",WINDOW_AUTOSIZE);
	int low=50,high=100;
	createTrackbar("low","Canny",&low,200);
	createTrackbar("high","Canny",&high,1000);
	while(9)
	{	
		Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
		Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
		GaussianBlur(a,b,Size(5,5),1.5,1.5);
		Canny(b,c,low,high);
		imshow("Canny",c);
		waitKey(100);
	}	
	return 0;

}