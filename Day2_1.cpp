#include<iostream>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("fruits.png",1);
	namedWindow("fruits",WINDOW_AUTOSIZE);
	int B,g,r;
	createTrackbar("blue","fruits",&B,255);
	createTrackbar("green","fruits",&g,255);
	createTrackbar("red","fruits",&r,255);
	while(8)
	{	
		int i,j;
		Mat b(a.rows,a.cols,CV_8UC3,Scalar(250,250,250));
		for(i=0;i<a.rows;i++)
			for(j=0;j<a.cols;j++)
			{
				if((a.at<Vec3b>(i,j)[0]<B)&&(a.at<Vec3b>(i,j)[1]<g)&&(a.at<Vec3b>(i,j)[2]<r))
				{

					b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
					b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,j)[1];
					b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,j)[2];
				}	
				else
				{
					b.at<Vec3b>(i,j)[0]=255;
					b.at<Vec3b>(i,j)[1]=255;
					b.at<Vec3b>(i,j)[2]=255;
				}
			}
		imshow("fruits",b);
		waitKey(50);
	}
	return 0;
}