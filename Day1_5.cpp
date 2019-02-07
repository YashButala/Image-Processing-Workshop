#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	
	Mat orig=imread("joker.jpg",1);
	Mat gorig=imread("joker.jpg",0);
	Mat grey(orig.rows,orig.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<orig.rows;i++)
	{
		for(int j=0;j<orig.cols;j++)
		{
			grey.at<uchar>(i,j)=(.114*orig.at<Vec3b>(i,j)[0]+.587*orig.at<Vec3b>(i,j)[1]+.299*orig.at<Vec3b>(i,j)[2]);
		}
	}
	imshow("image",grey);
	imshow("img",gorig);
	waitKey(0);
	return 0;
}
