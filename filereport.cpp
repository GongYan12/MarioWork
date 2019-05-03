#include "stdafx.h"
#include "filereport.h"

#include "stdio.h"
#include "stdlib.h"


FILEREPORT::FILEREPORT()
{	//������д"w"�ķ�ʽ���ı�trace 
	fp=fopen("trace.txt","w");
	//������num��ʼ��Ϊ0 
	memset(num,0,sizeof(num));
}

FILEREPORT::FILEREPORT(char *p)
{	//���ļ�p 
	fp=fopen(p,"w");
	//�����ʼ�� 
	memset(num,0,sizeof(num));

}

FILEREPORT::~FILEREPORT()
{	//�ر��ļ�p 
	fclose(fp);
}

void FILEREPORT::put(char *p)
{	//���ַ���pд���ļ�p	
	fwrite(p,sizeof(char),strlen(p),fp);
	//������� 
	fwrite("\n",1,1,fp);
}

//���������ĸ���

void FILEREPORT::putnum(int i,char *p)
{
	char temp[50]; 
	sprintf(temp,"(%d) ",num[i]);//��num����������ִ�ӡ���ַ����洢��temp 
	fwrite(temp,sizeof(char),strlen(temp),fp);//��tempд���ļ�p
	num[i]++;

	fwrite(p,sizeof(char),strlen(p),fp);//���ַ���pд���ļ�p 
	fwrite("\n",1,1,fp);//���з� 
}

void FILEREPORT::put(char *p,int a,int b)
{
	char temp[50];
	sprintf(temp,"%s : %d , %d",p,a,b); 
	fwrite(temp,sizeof(char),strlen(temp),fp);
	fwrite("\n",1,1,fp);
}

void FILEREPORT::CheckDC(HDC h,char *p)// �����Windows������־Ӧ�ó����н����Ļ���ʹ�õ�Ψһ������Ӧ�ó����ܹ�ͨ�����������Ӧ�Ķ������Ϣ�����Ǿ������ָ�룬���������þ����ֱ���Ķ��ļ��е���Ϣ�� 
{
	if(h==NULL)
	{
		fwrite(p,sizeof(char),strlen(p),fp);
		fwrite("\n",1,1,fp);
	}
}


void FILEREPORT::SetDevice(HDC h,int x,int y)HDC��windowsϵͳAPI�ж����һ���������ͣ�����һ���豸�����ĵľ�� 
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
	TextOut(hshow,xpos,ypos,info,strlen(info));//��������ַ�����ʼλ��x,�ַ�����ʼλ��y���ַ������ַ������ַ������� 

}
