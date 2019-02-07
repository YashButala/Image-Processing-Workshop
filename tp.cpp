    #include<stdio.h>
    #include<string.h>
    void fun(int n,char s[])
    {
    	int k;
    	int a[7];
     
    	if(strcmp(s,"mon")==0)
    	k=0;
    	if(strcmp(s,"tues")==0)
    	 k=1;
    	if(strcmp(s,"wed")==0)
    	k=2;
    	if(strcmp(s,"thur")==0)
    	k=3;
    	if(strcmp(s,"fri")==0)
    	k=4;
    	if(strcmp(s,"sat")==0)
    	k=5;
    	if(strcmp(s,"sun")==0)
    	k=6;
     
    	for (int i = 0; i < 7; ++i)
    	{
    		a[i]=4;
    	}
    	for (int i = 0; i < n-28; ++i)
    	{
    		a[(i+k)%7]=5;
    	}
    	for (int i = 0; i < 7; ++i)
    	{
    		printf("%d ",a[i]);
     
    	}
    	printf("\n");
    }
    int main()
    {
    	int t;
    	scanf("%d",&t);
    	for (int i = 0; i < t; ++i)
    	{
    		int k;
    		char c[5];
    		scanf("%d ",&k);
    		scanf("%s",c);
    		fun(k,c);
    	}
    	return 0;
     
    } 