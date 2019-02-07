#include<iostream>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("scenery.jpg",0);
	namedWindow("scenery",WINDOW_AUTOSIZE);
	int g;
	createTrackbar("gray","scenery",&g,255);
	while(9)
	{
		int i,j;
		Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
		for(i=0;i<a.rows;i++)
			for(j=0;j<a.cols;j++)
			{
				if(a.at<uchar>(i,j)>g)
				{
					b.at<uchar>(i,j)=255;	
				}
				else
					b.at<uchar>(i,j)=0;		
			}	
		imshow("scenery",b);
		waitKey(10);	
	}
}