#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
char* find(char **data, int n)			//ƥ���㷨
{
	char *p = data[0];//��¼����ֵ
	int timesMax = 1;//��¼������
	int timesTemp = 1;//��¼��ʱ��������ʼ��Ϊ1
	for (int i = 0; i < n; ++i)
	{
		if (data[i] != "")//�ҹ��ģ��Ͳ�����������
		{
			timesTemp = 1;//����ѭ��������Ϊ1����Ϊ��������Ϊ1��
			for (int j = i + 1; j < n; ++j)//�ڲ�ѭ����i+1��ʼ
			{
				if (strcmp(data[i],data[j])==0)//�ҵ���
				{
					data[j] = "";//�㷨�Ĺؼ���˵��ǰ���Ѿ�ͳ�ƹ�����ַ����ˡ�
					++timesTemp;
					if (timesTemp > timesMax)//����������
					{
						timesMax = timesTemp;//����������
						p = data[i];//�޸�p����ָ��
					}
				}
			}
		}

	}
	//cout << timesMax << endl;//���ԣ��鿴������
	return p;
}
int file_open(char *file_name)		//file_name���ļ���
{
	ifstream fp;
	fp.open(file_name,ios::in);
	int i=0;
	if(!fp)
	{
		return -1;
	}
	char *data[50000];				//���ݻ�������һ���Զ����ڴ�
	for(int j=0;j<50000;j++)
	{
		data[j]=new char[12];
	}
	while(!fp.eof())
	{
		fp.getline(data[i++],11);
	}
	cout << find(data, 73534) << endl;		//������Ƶ��ַ
	return 0;
}
bool generate_file_name(char *file_name)
{
	//�˴�Ϊ�ļ������ɺ���
	return true;
}
int main()
{
	int file_num=1;					//Ҫ������ļ�������Ĭ��Ϊ1
	char file_name[40];				//�ļ���������
	cout<<"enter file num"<<endl;	//�˴���֮���������Ϊ������λ�ô��δ�����
	cin>>file_num;
	try
	{
		for(int i=0;i<file_num;i++)
		{
			if(!generate_file_name(file_name))
			{
				throw -i;
			}
			if(file_open(file_name)!=0)
			{
				throw i;
			}
		}
	}
	catch (int &value)
	{
		if(value<0)
		{
			cout<<"generate_file_name "<<value<<" failed!"<<endl;
		}
		if(value>0)
		{
			cout<<"file_open "<<value<<" failed!"<<endl;
		}
	}
	return 0;
}