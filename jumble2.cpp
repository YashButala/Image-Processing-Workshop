#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace cv;
using namespace std;
void change(Mat a,int x,int y)
{
	int i,j,k,temp;
	for(i=0;i<a.rows/2;i++)
		for (j=0; j < a.cols/4; ++j)
			for(k=0;k<3;k++)
			{	
				temp=a.at<Vec3b>(i+(x/4)*(a.rows/2),j+(x%4)*(a.cols/4))[k];
				a.at<Vec3b>(i+(x/4)*(a.rows/2),j+(x%4)*(a.cols/4))[k]=a.at<Vec3b>(i+(y/4)*(a.rows/2),j+(a.cols/4)*(y%4))[k];
				a.at<Vec3b>(i+(y/4)*(a.rows/2),j+(y%4)*(a.cols/4))[k]=temp;	
			}

}
void construct(Mat a)
{
	int x,temp;
	for(int y=1;y<4;y++)
	{
		
		for ( x = 0; x< 8; ++x)
		
		{
			temp=0;	 
			for(int i=0;i<a.rows/2;i++)
			{	
				for (int k = 0; k < 3; ++k)
				{
					if(a.at<Vec3b>(i,(a.cols/4)*y-1)[k]-a.at<Vec3b>(i+(x/4)*(a.rows/2),(x%4)*(a.cols/4))[k]<10)
						temp++;
				}

			}
		if(temp>500)
		{
			change(a,x,y);
		}	
			
		}
	
	}
	imshow("!",a);
	waitKey(0);
}
int main()
{
	Mat a=imread("img1.jpg",1);
	Mat b=a.clone();
	for (int i = 0; i<4; ++i)
	{
		change(b,i,7-i);

	}
	Mat c=b.clone();
	change(c,0,7);
	change(c,7,4);
	imshow("img1",a);	
	waitKey(0);
	imshow("img2",b);	
	waitKey(0);
	imshow("img3",c);	
	waitKey(0);
	construct(c);


	return 0;
}