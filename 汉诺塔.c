//����Ҫ�ƶ����������� ͨ��C�����Ӵ�A�ƶ���B��

#include<stdio.h>

void fun(int n,char A,char B,char C)
{
	if(n==1)   //���ֻ��һ��ֱ�Ӵ�A�ƶ���B
	{
		printf("Move %d:from %c to %c\n",n,A,B);
	}
	else
	{fun(n-1,A,C,B);
	printf("Move %d:from %c to %c\n",n,A,B);
	fun(n-1,C,B,A);
	}
}
int main()
{
	int n;
	char A='A';
	char B='B';
	char C='C';
	printf("Input the number of disks:");
	scanf("%d",&n);
	printf("Steps of moving %d disks from A to B by means of C:\n",n);
	fun(n,A,B,C);
	return 0;
}