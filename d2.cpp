#include<stdio.h>


int num=0;//定义全局变量n用来存储众数

int sum=0;//定义一个全局变量sum用来存储重数

int count(int a[],int p,int q)

{//定义一个统计数组中间数出现的次数，a为待统计的集合，参数p为待递归数组第一个数的索引，q为带递归数组最后一个数的索引

  int n= a[(p+q)/2];

  int counts=0;

  for(int i=p;i<q;i++)

  { //从待统计数组的第一个数的索引开始统计，直到q结束

  if(a[i]==n){
  counts++;
  }

  }

  return counts;

}

int start(int a[],int p,int q)

{//定义一个方法，用于返回当前数组的中间数第一次出现位置的索引,参数p为当前数组第一个数的位置索引，q为最后一个索引

  int x=0;

   //从当前数组的第一个数开始，当第第一次找到与当前数组的中间数相等的数，跳出循环，并返回i
   for(int i=p;i<q;i++)

{

  if(a[i]==a[(p+q)/2])

  {

     x=i;

     break;

  }

}

return x;

}

void mode( int a[],int p,int q)//刚开始第一步时p=0,q=n

{

    int  tnum=(p+q)/2;//tnum为当前数组中间数的索引

    int  tsum=count(a,p,q);//统计中间数的重数

    int left=start(a,p,q);//找到当前数组中间数第一次出现的位置，记录下来

    if(tsum>sum)//如果中间数的重数大于sum，将中间数赋给num

	{

       sum=tsum;

       num=a[tnum];

	}

    if(q-(left+tsum)>sum)//如果当前数组右边元素的个数大于重数sum,那么右边可能出现众数，向右递归寻找

	{

         mode(a,left+tsum,q);

	}

     if(left>sum)//如果当前数组左边元素的个数大于重数sum，那么左边可能出现众数，向左递归寻找

	 { 

          mode(a,0,left);

	 }

}

//主函数

void main()

{

      //int a[]={6,1,2,2,2,3,5};

	int a[100];
	int count1=0;
	int i=0;
	char y;

do{	
	scanf("%d",&a[i++]);
	count1++;
	}while((y=getchar())!='\n');

      printf("个数：%d\n",count1);
      printf("输出结果：\n");
     // count<<"众数="<<num<<"    "<<"重数="<<sum;
	 
	  
	  for(int j=0;j<i;j++){
		  
		  printf("%d\n",a[j]);
		 
	  }
	  
	  mode(a,0,count1+1);
	  printf("众数：%d\n",num);
	  printf("重数：%d\n",sum);


}