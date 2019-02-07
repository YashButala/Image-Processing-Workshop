#include<iostream>
#include<stdlib.h>
//#include<algorithm>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int IsValid (int x,int y,int rows,int cols)
{
	if(x<0||y<0||x>=rows||y>=cols)
		return 0;
	else return 1;
}
void dfs_visit(int i,int j,int count,Mat b,Mat a)

{
	int k,l;
	b.at<uchar>(i,j)=255/count;
	for( k=i-1;k<i+2;k++)
	{
		for( l=j-1;l<j+2;l++)
		{
			

			if(IsValid(k,l,a.rows,a.cols))
				if(b.at<uchar>(k,l)==0&&a.at<uchar>(k,l)==255)
				{
					imshow("visited",b);
					waitKey(1);
					dfs_visit (k,l,count,b,a);
				}		
		}
	}
}

int main()
{
	Mat a=imread("binary3.jpg",0);

	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	int i,j,count =1;
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)<127)
				a.at<uchar>(i,j)=0;
			else 
				a.at<uchar>(i,j)=255;
		}
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==255&&b.at<uchar>(i,j)==0)
			{
				dfs_visit(i,j,count,b,a);
				count++;

			}
		}
		imshow("image",a);
	imshow("image",b);	
	waitKey(0);
	return 0;
}

