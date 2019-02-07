#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main()
{
    int i, j, t, r, x=65;
    Mat a = imread("A3.png", 0);
//   namedWindow("OUT", WINDOW_NORMAL);
//  createTrackbar("Threshold", "OUT", &x, 100);
    Canny(a,a,15,50);
    int diag = sqrt(a.rows*a.rows+a.cols*a.cols);
 //   while(1){
    Mat f(2*diag+1, 180, CV_8UC1, Scalar(0));
    vector<Point> p;
    for(i=0;i<a.rows;i++)
        for(j=0;j<a.cols;j++)
            for(t=0;t<180;t++)
            if(a.at<uchar>(i,j)>200)
            {
                r=j*cos(CV_PI*t/180)+i*sin(CV_PI*t/180);
                f.at<uchar>(r+diag,t)++;
            }
    for(i=2;i<2*diag-1;i++)
        for(j=2;j<180-2;j++)
        {
            int max=0;
            for(int l=-2;l<3;l++)
                for(int m=-2;m<3;m++)
                    if(f.at<uchar>(i-l,j-m)>max) max=f.at<uchar>(i-l,j-m);
            if(f.at<uchar>(i,j)!=0 && f.at<uchar>(i,j)==max && f.at<uchar>(i,j)>x)
            {
                Point temp;
                temp.x=j; temp.y=i;
                p.push_back(temp);
            }
        }
 //   imshow("OUT", f);
    cout<<p.size()<<endl;
  //  waitKey(50);
    int k;
    Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
    for(i=0;i<p.size();i++)
        for(j=0;j<a.rows;j++)
        {
            k=(p[i].y-i*sin(CV_PI*p[i].x/180.0))/cos(CV_PI*p[i].x/180.0);
            if(k<b.cols&&k>0)
                b.at<uchar>(j,k)=255;
        }
    imshow("image",b);
    waitKey(0);
//}
    return 0;
}