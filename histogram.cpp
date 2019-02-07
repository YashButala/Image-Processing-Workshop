#include<iostream>
#include<stdlib.h>
//#include<algorithm>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("joker.jpg",0);
	int c[256];
	int i,j,k;
	for(i=0;i<256;i++)
		c[i]=0;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			k=a.at<uchar>(i,j);
			c[k]++;
		}
	int max=c[0];	
	for(i=0;i<256;i++)
	{
		if(c[i]>max)
		max=c[i];	
	}	
	Mat b(max/20,256,CV_8UC1,Scalar(0));
	for(i=0;i<b.rows;i++)
		for ( j= 0; j<b.cols; j++)
		{
			if(i<c[j]/20)
				b.at<uchar>(i,j)=0;
			else
				b.at<uchar>(i,j)=255;
		}
	int temp;
	for(i=0;i<b.rows/2;i++)
		for(j=0;j<b.cols;j++)
		{
			temp=b.at<uchar>(i,j);
			b.at<uchar>(i,j)=b.at<uchar>(b.rows-1-i,j);
			b.at<uchar>(b.rows-1-i,j)=temp;
		}

	imshow("image",b);
	waitKey(0);
	return 0;		
}			
