#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;


int main()
{

	Mat a=imread("lena.png",0);
	int c[9],i,j,k,l,m=0;
	for(i=1;i<a.rows-1;i++)
		for(j=1;j<a.cols-1;j++)
		{
			for(k=0;k<3;k++)
				for(l=0;l<3;l++)	
				{	
					c[m]=a.at<uchar>(i+1-l,j+1-k);
					m++;
				}
			sort(c,c+9);
			a.at<uchar>(i,j)=c[4];			
		}
	imshow("image",a);
	waitKey(0);
	return 0;

}	
