#include <stdio.h>
#include <string.h>

int a[20][4];
int b[20];
char *P[]=
{
	"空手",
    "狼",
    "羊",
    "蔬菜"
};
int fun(int x)
{
    int i;
    /*若该种步骤能使各值均为1，则输出结果，进入回归步骤*/
    if(a[x][0]+a[x][1]+a[x][2]+a[x][3] == 4)
    {
         for(i=0; i<=x; i++)  /*能够依次输出不同的方案*/
        {
            printf("原岸: ");
            if(a[i][0] == 0)
                printf("狼  ");
            if(a[i][1] == 0)
                printf("羊  ");
            if(a[i][2] == 0)
                printf("蔬菜  ");
            if(a[i][3] == 0)
                printf("农民  ");
            if(a[i][0] && a[i][1] && a[i][2] && a[i][3])
                printf("原岸无物品");
            printf("     ");
            printf("对岸: ");
            if(a[i][0] == 1)
                printf("狼  ");
            if(a[i][1] == 1)
                printf("羊  ");
            if(a[i][2] == 1)
                printf("蔬菜  ");
            if(a[i][3] == 1)
                printf("农民  ");
            if(!(a[i][0] || a[i][1] || a[i][2] || a[i][3]))
                printf("对岸没有物品");
            printf("\n");
            
            if(i>0 && i<x)
            {
                if(a[i][3] == 0)  /*农夫在本岸*/
                {
                    printf("农夫带%s去\n",P[b[i] + 1]);
                }
                else      /*农夫在对岸*/
                {
                    printf("农夫带%s回\n", P[b[i] + 1]);
                }
            }
		 
        }
        printf("\n\n");
        return 0;
    }
    for(i=0; i<x; i++)
    {
        if(memcmp(a[i],a[x],16) == 0)  /*若该步与以前步骤相同，取消操作*/
        {
            return 0;
        }
    }
    /*若羊和农夫不在一块而狼和羊或者羊和白菜在一块，则取消操作*/
    if(a[x][1]!=a[x][3] && (a[x][2] == a[x][1] || a[x][0] == a[x][1]))
    {
        return 0;
    }
    /*递归，从带第一种动物开始依次向下循环，同时限定递归的界限*/
    for(i=-1; i<=2; i++)
    {
        b[x]=i;
        memcpy(a[x+1], a[x], 16);  /*复制上一步状态，进行下一步移动*/
        a[x+1][3]=1-a[x+1][3];  /*农夫过去或者回来*/
        if(i == -1)
        {
            fun(x+1);  /*进行第一步*/
        }
        else
            if(a[x][i] == a[x][3])  /*若该物与农夫同岸，带回*/
            {
                a[x+1][i]=a[x+1][3];  /*带回该物*/
                fun(x+1);  /*进行下一步*/
            }
    }
    return 0;
}
int main()
{
   // printf("\n\n             农夫过河问题，解决方案如下：\n\n\n");
    fun(0);
    return 0;
}

