#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	int i,j;
	Mat a(400,400,CV_8UC3,Scalar(0,100,0));
	for(i=0;i<400;i++)
	{
		for(j=0;j<400;j++)
		{
			if(i+j>400)
			{
				a.at<Vec3b>(i,j)[0]=0;
				a.at<Vec3b>(i,j)[1]=200;
				a.at<Vec3b>(i,j)[2]=0;
			}
			else
			{
				a.at<Vec3b>(i,j)[0]=0;
				a.at<Vec3b>(i,j)[1]=0;
				a.at<Vec3b>(i,j)[2]=200;
			}


		}
	}

	imshow("Image",a);
	waitKey(0);
	return 0;
}
