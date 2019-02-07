#include<iostream>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("lena.png",0);
	int i,j,k,l;
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
//	Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
	namedWindow("lena",WINDOW_AUTOSIZE);
	int g=1;
	createTrackbar("blur","lena",&g,100);
	while(9)
	{
		for(i=g/2;i<a.rows-g/2;i++)
			for(j=g/2;j<a.cols-g/2;j++)
			{

				for(k=0;k<g;k++)
					for(l=0;l<g;l++)
					{	
						b.at<uchar>(i,j)+=a.at<uchar>(i-g/2+k,j-g/2+l);	
					}	
				b.at<uchar>(i,j)=b.at<uchar>(i,j)/(g*g);		
			}
	//	imshow("image",a);	
		imshow("ima",b);
		waitKey(200);
	}
	return 0;
}