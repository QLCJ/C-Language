#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c,x,y,w;
	char s[100];
	int word=0,space=0,out=0,zifu=0,TAB=0,paragraph=1;
	FILE*fp;
	printf("请输入磁盘文件名：\n");
	scanf("%s",s);
	if((fp=fopen(s,"r"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		putchar(c);
		if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>=' '&&c<='@')
			zifu++;
		if(c==' ')
			space++;
		if(c=='\t')
			TAB++;
		if(c==' '||c=='\n'||c=='\t')  //统计单词
			w=0;
		if(w==0)
		{
			w=1;
			word++;
		}
		if(c=='-')
			word++;
		if(c=='\n')  //判断段落
		{
			x=fgetc(fp);
			y=fgetc(fp);
			if(x==' '&&y==' ')
			{ 
				paragraph++;
				putchar(x);
				putchar(y);
			}
		}


		c=fgetc(fp);

	}
	word--;
	word--;
	printf("\n");
	printf("单词有：%d个\n字符有：%d个\n空格有：%d个\nTAB有：%d个\n段落有：%d个\n",word,zifu,space,TAB,paragraph);
	fclose(fp);

}


