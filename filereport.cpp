#include "stdafx.h"
#include "filereport.h"

#include "stdio.h"
#include "stdlib.h"


FILEREPORT::FILEREPORT()
{	//以允许写"w"的方式打开文本trace 
	fp=fopen("trace.txt","w");
	//将数组num初始化为0 
	memset(num,0,sizeof(num));
}

FILEREPORT::FILEREPORT(char *p)
{	//打开文件p 
	fp=fopen(p,"w");
	//数组初始化 
	memset(num,0,sizeof(num));

}

FILEREPORT::~FILEREPORT()
{	//关闭文件p 
	fclose(fp);
}

void FILEREPORT::put(char *p)
{	//将字符串p写入文件p	
	fwrite(p,sizeof(char),strlen(p),fp);
	//数据项换行 
	fwrite("\n",1,1,fp);
}

//带计数器的跟踪

void FILEREPORT::putnum(int i,char *p)
{
	char temp[50]; 
	sprintf(temp,"(%d) ",num[i]);//将num数组里的数字打印成字符串存储到temp 
	fwrite(temp,sizeof(char),strlen(temp),fp);//将temp写入文件p
	num[i]++;

	fwrite(p,sizeof(char),strlen(p),fp);//将字符串p写入文件p 
	fwrite("\n",1,1,fp);//换行符 
}

void FILEREPORT::put(char *p,int a,int b)
{
	char temp[50];
	sprintf(temp,"%s : %d , %d",p,a,b); 
	fwrite(temp,sizeof(char),strlen(temp),fp);
	fwrite("\n",1,1,fp);
}

void FILEREPORT::CheckDC(HDC h,char *p)// 句柄是Windows用来标志应用程序中建立的或是使用的唯一整数，应用程序能够通过句柄访问相应的对象的信息，但是句柄不是指针，程序不能利用句柄来直接阅读文件中的信息。 
{
	if(h==NULL)
	{
		fwrite(p,sizeof(char),strlen(p),fp);
		fwrite("\n",1,1,fp);
	}
}


void FILEREPORT::SetDevice(HDC h,int x,int y)HDC是windows系统API中定义的一个数据类型，定义一个设备上下文的句柄 
{
	hshow=h;
	xpos=x;
	ypos=y;
}

void FILEREPORT::Output(char *p,int a,int b)
{
	sprintf(info,"%s:%d,%d",p,a,b);

	
}

void FILEREPORT::Show()
{
	TextOut(hshow,xpos,ypos,info,strlen(info));//（句柄，字符串开始位置x,字符串开始位置y，字符串，字符串中字符个数） 

}
