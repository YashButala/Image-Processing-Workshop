#include<iostream>
#include<bits/stdc++.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{
	Mat a=imread("A3.png",0);
	int diag=sqrt(a.rows*a.rows+a.cols*a.cols);
	Mat b(2*diag+1,180,CV_8UC1,Scalar(0));
	int th=252;
	namedWindow("OUT", WINDOW_NORMAL);
   	createTrackbar("Threshold", "OUT", &th, 1000);
    int i,j,k,r;
	Canny(a,a,15,45);
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			for(k=0;k<180;k++)
				if(a.at<uchar>(i,j))
				{
					r=i*sin(CV_PI*k/180)+j*cos(CV_PI*k/180);
					if(b.at<uchar>(r+diag,k)<255)
						b.at<uchar>(r+diag,k)+=10;

				}
		}
	imshow("image",b);
	waitKey(0);
 	
	
	while(9)
	{
		Vector<Point>p;
		for(i=3;i<b.rows-3;i++)
			for(j=3;j<b.cols-3;j++)
			{
				if(b.at<uchar>(i,j)>0)
				{
					int flag=1;
					for(k=i-3;k<i+4;k++)
						for(r=j-3;r<j+4;r++)
						{
						
							if(b.at<uchar>(k,r)>b.at<uchar>(i,j))
							{
								flag=0;
							}
						}
					if(b.at<uchar>(i,j)>th && flag==1)
						{
							Point temp;
							temp.x=j;temp.y=i;
							p.push_back(temp); 
						}	

				}
		}
    	imshow("OUT", b);
    	cout<<p.size()<<endl;
    	waitKey(100);	
	
	}
/*	int g=0;
	Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
	int z=0;
	while(z<9)
	{
		p[g].x=k;
		p[g].y=r;
		for(i=0;i<a.rows;i++)
		{

			j=(r-i*sin(CV_PI*k/180))/cos(CV_PI*k/180);
			if(j<c.cols&&j>0)
				c.at<uchar>(i,j)=255;
		}
		z++;	
	}
	imshow("line",c);*/
	return 0;	

}
