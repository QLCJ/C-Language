#include <stdio.h>
#include <string.h>

int a[20][4];
int b[20];
char *P[]=
{
	"空手",
    "狼",
    "羊",
    "白菜"
};
int fun(int x)
{
    int i;
    if(a[x][0]+a[x][1]+a[x][2]+a[x][3] == 4)
    {
         for(i=0; i<=x; i++)  
        {
            printf("原岸: ");
            if(a[i][0] == 0)
                printf("狼  ");
            if(a[i][1] == 0)
                printf("羊  ");
            if(a[i][2] == 0)
                printf("白菜  ");
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
                printf("白菜  ");
            if(a[i][3] == 1)
                printf("农民  ");
            if(!(a[i][0] || a[i][1] || a[i][2] || a[i][3]))
                printf("对岸没有物品");
            printf("\n");
            
            if(i>0 && i<x)
            {
                if(a[i][3] == 0)
                {
                    printf("农夫带%s去\n",P[b[i] + 1]);
                }
                else    
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
        if(memcmp(a[i],a[x],16) == 0)  
        {
            return 0;
        }
    }
    if(a[x][1]!=a[x][3] && (a[x][2] == a[x][1] || a[x][0] == a[x][1]))   //判断羊和狼，羊和菜是否在同岸
    {
        return 0;
    }
    for(i=-1; i<=2; i++)
    {
        b[x]=i;
        memcpy(a[x+1], a[x], 16);  
        a[x+1][3]=1-a[x+1][3]; 
        if(i == -1)
        {
            fun(x+1);  
        }
        else
            if(a[x][i] == a[x][3]) 
            {
                a[x+1][i]=a[x+1][3];  
                fun(x+1);  
            }
    }
    return 0;
}
int main()
{
    fun(0);
    return 0;
}

