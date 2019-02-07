#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;
void DFS (int,int,int,Mat,Mat);
int isvalid(int,int,Mat);
int main()
{
	int count=1;
	Mat a;
	a=imread("binary3.jpg",0);
	Mat object(a.rows,a.cols,CV_8UC1,Scalar(0));
	int i,j;
	for (i=0;i<a.rows;i++)
	{
		for (j=0;j<a.cols;j++)
		{
			if (a.at<uchar>(i,j)>127)
				a.at<uchar>(i,j)=255;
			else
				a.at<uchar>(i,j)=0;

		}
	}
	for (i=0;i<a.rows;i++)
	{
		for (j=0;j<a.cols;j++)
		{
			if (object.at<uchar>(i,j)==0&&a.at<uchar>(i,j)==255)
				{
					DFS(i,j,count,a,object);
					count++;
				}
		}
	}

imshow("image1",a);
imshow("image",object);
waitKey(0);
}
void DFS (int i,int j, int count, Mat a, Mat object)
{
	object.at<uchar>(i,j)=255/count;
	int k,l;
	for (k=i-1;k<=i+1;k++)
	{
		for (l=j-1;l<=j+1;l++)
		{
			if (isvalid(k,l,a)==1)
			{
				if (object.at<uchar>(k,l)==0&&a.at<uchar>(k,l)==255)
				{
					imshow("new",object);
					waitKey(3);
					DFS(k,l,count,a,object);
				}	
			}
		}
	}
}

int isvalid(int i, int j,Mat img)
{

	if (i < 0 || j < 0 || i >= img.rows || j >= img.cols)
		return 0;
	else return 1;
}
