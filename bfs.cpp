#include<iostream>
#include<stdlib.h>
#include<queue>
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
void bfs(int i,int j,Mat a,Mat b)
{
	queue<int>q;
	int k,l;
	enqueue(a.at<uchar>(i,j))

	for(k=i-1;k<i=2;k++)
		for(l=j-1;l<j+2;j++)
		{
			if(IsValid(k,l,a.rows,a.cols))
			{	
				if(a.at<uchar>(i,j)==0&&b.at<uchar>(i,j)==0)	;
				enqueue(a.at<uchar>(k,l));
				
			}		
		}
}

int main()
{
	Mat a=imread("",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	
	int i,j;
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==0&&b.at<uchar>(i,j)==0)
			bfs(i,j, a,b);

		}