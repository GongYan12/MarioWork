#ifndef __FILEREPORT
#define __FILEREPORT

class FILEREPORT
{
public:
	//功能：默认构造函数，创建日志trace.text 	
	FILEREPORT();
	//功能：制定日志文件名称
	//参数：日志文件名称 
	FILEREPORT(char *p);
	//功能:析构函数，关闭文件 
	~FILEREPORT();
	//功能：向文件写入字符串
	//参数：要写入的字符串 
	void put(char *p);
	//功能：向文件写入一个字符串和两个整数
	//参数：字符串 整数a 整数b 
	void put(char *p,int a,int b);
	//功能：计时器计数，并写入一个提示字符串 
	//参数：计时器id 提示字符串 
	void putnum(int i,char *p);
	//功能：判断一个dc是否为null，如果是，写入提示信息
	//参数：dc句柄 提示信息字符串 
	void CheckDC(HDC h,char *p);
	//功能:设置显示跟踪信息的dc和文本坐标 
	//参数：显示dc 横纵坐标 
	void SetDevice(HDC h,int x,int y); 
	//功能:设置要显示的跟踪信息
	//参数：字符串 整数a 整数b 
	void Output(char *p,int a,int b);
	//功能：在屏幕上显示跟踪信息 
	void Show();


private:
	//跟踪文件指针 
	FILE *fp;
	//计数器组
	int num[5];
	//跟踪显示dc 
	HDC hshow;
	//跟踪显示的文本坐标 
	int xpos;
	int ypos;
	//当前跟踪信息 
	char info[50];
};

#endif
