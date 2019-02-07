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
struct vertex
{

	int d;
	struct point p;

}
struct point
{
	int x;
	int y;

}s,d;
main()
{
	imread Mat A=("pic1.png",1);

	Mat B(a.rows,a.cols.CV_8UC1,Scalar(0));
//find source and dest			
//prepare Mat b
	struct vertex a[a.rows][a.cols];
	for (int i=0;i<b.rows;i++)
		for(int j=0;j<b.cols;j++)
		{
			a[i][j].d=10000;
			a[i][j].p.x=-1;
			a[i][j].p.y=-1;
		} 
	s.d=0;
	queue<struct vertex>Q;
	Q.push(s);
	while(!Q.empty())
	{

		u=Q.front();
		if(u.x==d.x&&u.y==d.y)
			break;
		Q.pop;
		if(IsValid(u.x-1,u.y,a.rows,a.cols))
		{
			if(b.at<uchar>(u.x-1,u.y)==0)
			{
				if(a[u.x-1][u.y].d>1+a[u.x][u.y].d)
				{
					a[u.x-1][u.y].d=a[u.x][u.y].d+1;
					a[u.x-1][u.y].p.x=u.x;
					a[u.x-1][u.y].p.y=u.y;
					q.push(a[u.x-1][u.y]);
				}
			}
		}
		if(IsValid(u.x+1,u.y,a.rows,a.cols))
		{
			if(b.at<uchar>(u.x+1,u.y)==0)
			{
				if(a[u.x+1][u.y].d>1+a[u.x][u.y].d)
				{
					a[u.x+1][u.y].d=a[u.x][u.y].d+1;
					a[u.x+1][u.y].p.x=u.x;
					a[u.x+1][u.y].p.y=u.y;
					q.push(a[u.x+1][u.y]);
				}
			}
		}

		if(IsValid(u.x,u.y+1,a.rows,a.cols))
		{
			if(b.at<uchar>(u.x,u.y+1)==0)
			{
				if(a[u.x][u.y+1].d>1+a[u.x][u.y].d)
				{
					a[u.x][u.y+1].d=a[u.x][u.y].d+1;
					a[u.x][u.y+1].p.x=u.x;
					a[u.x][u.y+1].p.y=u.y;
					q.push(a[u.x][u.y+1]);
				}
			}
		}

		if(IsValid(u.x+1,u.y,a.rows,a.cols))
		{
			if(b.at<uchar>(u.x,u.y-1)==0)
			{
				if(a[u.x][u.y-1].d>1+a[u.x][u.y].d)
				{
					a[u.x][u.y-1].d=a[u.x][u.y].d+1;
					a[u.x][u.y-1].p.x=u.x;
					a[u.x][u.y-1].p.y=u.y;
					q.push(a[u.x][u.y-1]);
				}
			}
		}

	}	
	x
	return;
}