#include <stdio.h>

int main()
{

    int project; //������
    for(project = 0;project < 2; project++)
    {
        printf("����%d:\n", project + 1);
	int bank[2][4] = {//�������˼���Ʒ
		{1, 1, 1, 1},
		{0, 0, 0, 0}
	};
	int i;//ѭ������
	int ship = 0;//���ϳ����������Ʒ
	while(bank[1][0] + bank[1][1] + bank[1][2] + bank[1][3] != 4)//ֱ�������԰�
	{
		if(bank[0][0] == 1)//���ũ��������ԭ��
		{
			bank[0][0] = 0;	//ũ�����
			bank[1][0] = 1;
			for(i = 1; i < 4; i++)//����Ҫ��˭
			{
				if(i == ship)//�����ǰҪ�����Ǹոմ������ģ�����
				{
					continue;
				}
				if(bank[0][i] == 0)	//������ڶ԰�������
				{
					continue;
				}
				bank[0][i] = 0;//������Ӻ󱾵ػ᲻�ᷢ���������ײ˹������������������
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
		else//���ũ���ڶ԰�
		{
			bank[1][0] = 0;
			bank[0][0] = 1;
			if(bank[1][1] + bank[1][2] != 2 && bank[1][2] + bank[1][3] != 2)//����԰�û�г�ͻ��ũ���Լ�����
			{
				i = 4;
			}
			else//����г�ͻ���������䣨��ԭ�����ƣ�
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
		ship = i;//�����ϵ�����䶯������б䶯
		printf("ũ��");//������
		switch(ship)
		{
		case 4:
			printf("�Լ�");
			break;
		case 1:{
		    if(project == 0)
			printf("���Űײ�");
			else
			printf("������");
            }
			break;
		case 2:
			printf("������");
			break;
		case 3:{
		    if(project == 0)
		    printf("������");
		    else
			printf("���Űײ�");
		}
			break;
		}
		switch(bank[0][0])
		{
		case 0:
			printf("���Ӷ԰�\n");
			break;
		case 1:
			printf("����\n");
		}
	}
	printf("\n");
    }
	return 0;
}
