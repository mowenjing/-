#include<stdio.h>


int num=0;//����ȫ�ֱ���n�����洢����

int sum=0;//����һ��ȫ�ֱ���sum�����洢����

int count(int a[],int p,int q)

{//����һ��ͳ�������м������ֵĴ�����aΪ��ͳ�Ƶļ��ϣ�����pΪ���ݹ������һ������������qΪ���ݹ��������һ����������

  int n= a[(p+q)/2];

  int counts=0;

  for(int i=p;i<q;i++)

  { //�Ӵ�ͳ������ĵ�һ������������ʼͳ�ƣ�ֱ��q����

  if(a[i]==n){
  counts++;
  }

  }

  return counts;

}

int start(int a[],int p,int q)

{//����һ�����������ڷ��ص�ǰ������м�����һ�γ���λ�õ�����,����pΪ��ǰ�����һ������λ��������qΪ���һ������

  int x=0;

   //�ӵ�ǰ����ĵ�һ������ʼ�����ڵ�һ���ҵ��뵱ǰ������м�����ȵ���������ѭ����������i
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

void mode( int a[],int p,int q)//�տ�ʼ��һ��ʱp=0,q=n

{

    int  tnum=(p+q)/2;//tnumΪ��ǰ�����м���������

    int  tsum=count(a,p,q);//ͳ���м���������

    int left=start(a,p,q);//�ҵ���ǰ�����м�����һ�γ��ֵ�λ�ã���¼����

    if(tsum>sum)//����м�������������sum�����м�������num

	{

       sum=tsum;

       num=a[tnum];

	}

    if(q-(left+tsum)>sum)//�����ǰ�����ұ�Ԫ�صĸ�����������sum,��ô�ұ߿��ܳ������������ҵݹ�Ѱ��

	{

         mode(a,left+tsum,q);

	}

     if(left>sum)//�����ǰ�������Ԫ�صĸ�����������sum����ô��߿��ܳ�������������ݹ�Ѱ��

	 { 

          mode(a,0,left);

	 }

}

//������

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

      printf("������%d\n",count1);
      printf("��������\n");
     // count<<"����="<<num<<"    "<<"����="<<sum;
	 
	  
	  for(int j=0;j<i;j++){
		  
		  printf("%d\n",a[j]);
		 
	  }
	  
	  mode(a,0,count1+1);
	  printf("������%d\n",num);
	  printf("������%d\n",sum);


}