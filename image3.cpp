#include<iostream>

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
Mat erosion(Mat a)
{
	int i,j,k,l;
	

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==255)
			{
				for(k=0;k<3;k++)
					for(l=0;l<3;l++)
					{
						if(IsValid(i+k,j+l,a.rows,a.cols))
						{
							if(a.at<uchar>(i+k,j+l)==0)
								a.at<uchar>(i,j)=0;
						
							
						}
					}
			}
		}
	return a;	
}  
Mat dilution(Mat a)

{
	int i,j,k,l;
	

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==0)
			{
				for(k=0;k<3;k++)
					for(l=0;l<3;l++)
					{
						if(IsValid(i+k,j+l,a.rows,a.cols))
						{
							if(a.at<uchar>(i+k,j+l)==255)
								a.at<uchar>(i,j)=255;
						
							
						}
					}
			}
		}
	return a;	
}	
     

int main()
{

	Mat a=imread("erosion4.png",0);
	imshow("img",a);
	Mat b=a.clone();
	imshow("image",erosion (b));
	imshow("imag",dilution(b));
	imshow("imag",dilution(b));
	imshow("image",erosion (b));
	waitKey(0);
	return 0;
}