#ifndef __FILEREPORT
#define __FILEREPORT

class FILEREPORT
{
public:
	//���ܣ�Ĭ�Ϲ��캯����������־trace.text 	
	FILEREPORT();
	//���ܣ��ƶ���־�ļ�����
	//��������־�ļ����� 
	FILEREPORT(char *p);
	//����:�����������ر��ļ� 
	~FILEREPORT();
	//���ܣ����ļ�д���ַ���
	//������Ҫд����ַ��� 
	void put(char *p);
	//���ܣ����ļ�д��һ���ַ�������������
	//�������ַ��� ����a ����b 
	void put(char *p,int a,int b);
	//���ܣ���ʱ����������д��һ����ʾ�ַ��� 
	//��������ʱ��id ��ʾ�ַ��� 
	void putnum(int i,char *p);
	//���ܣ��ж�һ��dc�Ƿ�Ϊnull������ǣ�д����ʾ��Ϣ
	//������dc��� ��ʾ��Ϣ�ַ��� 
	void CheckDC(HDC h,char *p);
	//����:������ʾ������Ϣ��dc���ı����� 
	//��������ʾdc �������� 
	void SetDevice(HDC h,int x,int y); 
	//����:����Ҫ��ʾ�ĸ�����Ϣ
	//�������ַ��� ����a ����b 
	void Output(char *p,int a,int b);
	//���ܣ�����Ļ����ʾ������Ϣ 
	void Show();


private:
	//�����ļ�ָ�� 
	FILE *fp;
	//��������
	int num[5];
	//������ʾdc 
	HDC hshow;
	//������ʾ���ı����� 
	int xpos;
	int ypos;
	//��ǰ������Ϣ 
	char info[50];
};

#endif
