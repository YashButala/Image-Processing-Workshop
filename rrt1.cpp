#include<iostream>
#include<stdlib.h>
#include<math.h>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace std;
using namespace cv;
#define delta 20
#include <math.h>  
using namespace std;
using namespace cv;
struct pt
{
	int x;
	int y;
};
struct rrt
{
	pt t;
	rrt* parent;
};
pt source()
{
	pt p;
	p.x=rand()%400;
	p.y=rand()%400;
	return p;
}
pt dest()
{
	pt p;
	p.x=rand()%400;
	p.y=rand()%400;
	return p;
}
pt create()
{
	pt p;	
	p.x=rand()%400;
	p.y=rand()%400;
	return p;
}
double dist(pt q,pt r)
{
	return sqrt((q.x-r.x)*(q.x-r.x)+(q.y-r.y)*(q.y-r.y));
}
int main()
{

	Mat A(400,400,CV_8UC3,Scalar(255,255,255));
	rrt s;
	s.t=source();
	s.parent=NULL;
	A.at<Vec3b>(s.t.x,s.t.y)[1]=0;
	rrt d;
	d.t=dest();
	A.at<Vec3b>(d.t.x,d.t.y)[2]=0;
	pt p;
	p.x=-1;
	p.y=-1;
	int k=1; 
	rrt tree[A.rows*A.cols];	
	int n=1;
	while(p.x!=d.t.x||p.y!=d.t.y)
	{

		pt p=create();
		int temp;
		double dis=A.rows+A.cols;
		for(int i=0;i<n;i++)
		{
			if(dist(tree[i].t,p)<dis)
			{
				dis=dist(tree[i].t,p);
				temp=i;
			}
		}

		if(dis<delta)
		{
			line( A, Point (tree[temp].t.x,tree[temp].t.y),Point (p.x,p.y), Scalar(255,0,255), 1,8,0);
			tree[n].t=p;
			tree[n].parent=&tree[temp];
			imshow("img",A);
			waitKey(.001);

		}		
		else
			break;

		n++;

	}
	tree[n].t=d.t;
	tree[n].parent=&tree[n-1];
	imshow("img",A);
			waitKey(0);
	
	return 0;
}