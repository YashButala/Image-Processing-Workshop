#include<iostream>
#include<stdlib.h>
#include<math.h>
//#include<algorithm>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int Gx(Mat a,int i,int j)
{
	int k=0;
	k+=-1*(a.at<uchar>(i-1,j-1)+a.at<uchar>(i-1,j+1));
	k+=(a.at<uchar>(i+1,j-1)+a.at<uchar>(i+1,j+1));
	k+=2*(a.at<uchar>(i+1,j));
	k+=-2*(a.at<uchar>(i-1,j));
	return abs(k/4);	
}
int Gy(Mat a,int i,int j)
{
	int k=0;
	k+=-1*(a.at<uchar>(i-1,j+1)+a.at<uchar>(i+1,j+1));
	k+=(a.at<uchar>(i+1,j-1)+a.at<uchar>(i-1,j-1));
	k+=2*(a.at<uchar>(i,j-1));
	k+=-2*(a.at<uchar>(i,j+1));
	return abs(k/4);	
}
int g(Mat a,int i,int j)
{
	return sqrt(Gx(a,i,j)*Gx(a,i,j)+Gy(a,i,j)*Gy(a,i,j));
}
int main()
{

	
	Mat a=imread("fruits.png",0);
	namedWindow("sobel",WINDOW_AUTOSIZE);
	int x=1;
	createTrackbar("edge","sobel",&x,255);
	
	
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
//	Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
	while(9)
	{
		int i,j,k;
		for(i=1;i<a.rows-1;i++)
			for(j=1;j<a.cols-1;j++)
			{
			
				if(g(a,i,j)>x)
					b.at<uchar>(i,j)=255;
				else
					b.at<uchar>(i,j)=0;


			}
		imshow("image ",a);	
		imshow("sobel",b);
		waitKey(10);
	}	
	return 0;
}
