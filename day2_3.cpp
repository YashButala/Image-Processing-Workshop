#include<iostream>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("dice.png",0);
	namedWindow("apple",WINDOW_AUTOSIZE);
	int x=1;
	createTrackbar("enlarge","apple",&x,10);
	
	while(9)
	{	
		Mat b(a.rows/x,a.cols/x,CV_8UC1,Scalar(250));
		int i,j;
		for(i=0;i<a.rows/x;i++)
			for(j=0;j<a.cols/x;j++)
			{
				b.at<uchar>(i,j)=a.at<uchar>(i/x,j/x);	
			}
		imshow("image",b);
		//imshow("img",a);
		waitKey(1);
		
	}	
	return 0;
}
