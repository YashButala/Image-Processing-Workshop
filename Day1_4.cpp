#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	int i,j,k;
	Mat a=imread("joker.jpg",1);
	Mat b(a.rows,2*a.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			
			{
				for(k=0;k<3;k++)
				{
					b.at<Vec3b>(i,j)[k]=a.at<Vec3b>(i,j)[k];
					b.at<Vec3b>(i,2*a.cols-j)[k]=a.at<Vec3b>(i,j)[k];	
				}
			}
						
		}

	}
	
	imshow("Image",b);
	imwrite("joke.jpg",b);
	waitKey(0);
	return 0;
}

