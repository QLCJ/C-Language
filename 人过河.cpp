#include "iostream"
using namespace std;
#define MAX_STEP 20
#include"cstring"

//index: 0 - 狼，1－羊，2－菜，3－农夫，value：0－本岸，1－对岸
int a[MAX_STEP][4];
int b[MAX_STEP];

char *name[] =
{
"空手",
"带狼",
"带羊",
"带菜"
};

void search(int iStep)
{
int i;
if (a[iStep][0] + a[iStep][1] + a[iStep][2] + a[iStep][3] == 4)
{
for (i = 0; i < iStep; i++)
{
if (a[i][3] == 0)
{
printf("%s到对岸\n", name[b[i] + 1]);
}
else
{
printf("%s回本岸\n", name[b[i] + 1]);
}
}
printf("\n");
return;
}
for (i = 0; i < iStep; i++)
{
if (memcmp(a[i], a[iStep], sizeof(a[i])) == 0)
{
return;
}
}
if (a[iStep][1] != a[iStep][3] && (a[iStep][2] == a[iStep][1] || a[iStep][0] == a[iStep][1]))
{
return;//羊是关键，如果羊不和农夫在一起，羊就不能和菜在一起，羊也不能和狼在一起，
//所以，某一步iStep只要羊不和农夫在一起，有下列情况之一，就退出：
//1.羊就和菜在一起 2.羊和狼在一起
}
for (i = -1; i <= 2; i++)
{
b[iStep] = i;
memcpy(a[iStep + 1], a[iStep], sizeof(a[iStep + 1]));
a[iStep + 1][3] = 1 - a[iStep + 1][3];
if (i == -1)
{
search(iStep + 1);
}							
else if (a[iStep][i] == a[iStep][3])
{
a[iStep + 1][i] = a[iStep + 1][3];
search(iStep + 1);
}
}
}

int main()
{
search(0);
return 0;
}
