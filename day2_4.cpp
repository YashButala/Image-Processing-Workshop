#include<iostream>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("scenery.jpg");
	//Mat b(,256,CV_8UC1,Scalar(255));
	int c[256],i,j,k;
	for(i=0;i<256;i++)
		c[i]=0;
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			k=a.at<uchar>(i,j);
			c[k]++;
		}
	int max=0;	
	for(i=0;i<256;i++)
	{
		if(c[i]>max)
			max=c[i];	
	}
	Mat b(max,256,CV_8UC1,Scalar(255));		
	for(i=0;i<max;i++)
		for(j=0;j<256;j++)
		{
			if(c[i]>j)
				b.at<uchar>(i,j)=0;
			else 
				b.at<uchar>(i,j)=255;	
		}	
	imshow("image",b);
	waitKey(0);
	return 0;
}
