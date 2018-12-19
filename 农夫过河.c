#include <stdio.h>

int main()
{

    int project; //方案数
    for(project = 0;project < 2; project++)
    {
        printf("方案%d:\n", project + 1);
	int bank[2][4] = {//两岸的人及物品
		{1, 1, 1, 1},
		{0, 0, 0, 0}
	};
	int i;//循环变量
	int ship = 0;//船上除人以外的物品
	while(bank[1][0] + bank[1][1] + bank[1][2] + bank[1][3] != 4)//直到都到对岸
	{
		if(bank[0][0] == 1)//如果农夫现在在原岸
		{
			bank[0][0] = 0;	//农夫过河
			bank[1][0] = 1;
			for(i = 1; i < 4; i++)//计算要带谁
			{
				if(i == ship)//如果当前要带的是刚刚带过来的，跳过
				{
					continue;
				}
				if(bank[0][i] == 0)	//如果它在对岸，跳过
				{
					continue;
				}
				bank[0][i] = 0;//计算过河后本地会不会发生狼羊或羊白菜共处，如果发生，跳过
				bank[1][i] = 1;
				if(bank[0][1] + bank[0][2] == 2 || bank[0][2] + bank[0][3] == 2)
				{
					bank[1][i] = 0;
					bank[0][i] = 1;
					continue;
				}
				break;
			}
		}
		else//如果农夫在对岸
		{
			bank[1][0] = 0;
			bank[0][0] = 1;
			if(bank[1][1] + bank[1][2] != 2 && bank[1][2] + bank[1][3] != 2)//如果对岸没有冲突，农夫自己过河
			{
				i = 4;
			}
			else//如果有冲突，计算运输（与原岸类似）
			{
				for(i = 1; i < 4; i++)
				{
					if(i == ship)
					{
						continue;
					}
					if(bank[1][i] == 0)
					{
						continue;
					}
					bank[1][i] = 0;
					bank[0][i] = 1;
					if(bank[1][1] + bank[1][2] == 2 || bank[1][2] + bank[1][3] == 2)
					{
						bank[0][i] = 0;
						bank[1][i] = 1;
						continue;
					}
					break;
				}
			}
		}
		ship = i;//将船上的物与变动的物进行变动
		printf("农夫");//输出结果
		switch(ship)
		{
		case 4:
			printf("自己");
			break;
		case 1:{
		    if(project == 0)
			printf("带着白菜");
			else
			printf("带着狼");
            }
			break;
		case 2:
			printf("带着羊");
			break;
		case 3:{
		    if(project == 0)
		    printf("带着狼");
		    else
			printf("带着白菜");
		}
			break;
		}
		switch(bank[0][0])
		{
		case 0:
			printf("到河对岸\n");
			break;
		case 1:
			printf("回来\n");
		}
	}
	printf("\n");
    }
	return 0;
}
