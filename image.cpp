#include<iostream>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat a(1000,600,CV_8SC3,Scalar(-100,0,0));

	imshow("Image",a);
	waitKey(0);
	return 0;
}
