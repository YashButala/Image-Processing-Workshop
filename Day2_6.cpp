#include<iostream>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	int i,j;
	Mat a=imread("lena.png",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	for(i=1;i<a.rows-1;i++)
	{
		for(j=0;j<a.cols-1;j++)
		{
			b.at<uchar>(i,j)=0.25(a.at<uchar(i,j)+0.5((a.at<uchar>(i-1,j)+a.at<uchar>(i+1,j)+a.at<uchar>(i,j+1)+a.at<uchar>(i,j-1) )+));
			b.at<uchar>(i,j)+=0.0625*(a.at<uchar>(i+1,j+1)+a.at<uchar>(i+1,j-1)+a.at<uchar>(i-1,j-1)+a.at<uchar>(i-1,j+1));
		}
	}
	imshow("image",b);
	return 0;
}