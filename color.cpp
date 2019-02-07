#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main(){

	Mat a(400,400,CV_8UC3,Scalar(0,255,0));
	imshow("image",a);
	waitKey(0);
	return 0;
}
