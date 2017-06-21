#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
char* find(char **data, int n)			//匹配算法
{
	char *p = data[0];//记录返回值
	int timesMax = 1;//记录最大次数
	int timesTemp = 1;//记录临时次数，初始化为1
	for (int i = 0; i < n; ++i)
	{
		if (data[i] != "")//找过的，就不遍历再找了
		{
			timesTemp = 1;//进入循环，重置为1，因为次数至少为1次
			for (int j = i + 1; j < n; ++j)//内层循环从i+1开始
			{
				if (strcmp(data[i],data[j])==0)//找到了
				{
					data[j] = "";//算法的关键，说明前面已经统计过这个字符串了。
					++timesTemp;
					if (timesTemp > timesMax)//更新最大次数
					{
						timesMax = timesTemp;//重置最大次数
						p = data[i];//修改p的新指向
					}
				}
			}
		}

	}
	//cout << timesMax << endl;//测试，查看最大次数
	return p;
}
int file_open(char *file_name)		//file_name：文件名
{
	ifstream fp;
	fp.open(file_name,ios::in);
	int i=0;
	if(!fp)
	{
		return -1;
	}
	char *data[50000];				//数据缓冲区，一次性读入内存
	for(int j=0;j<50000;j++)
	{
		data[j]=new char[12];
	}
	while(!fp.eof())
	{
		fp.getline(data[i++],11);
	}
	cout << find(data, 73534) << endl;		//输出最高频地址
	return 0;
}
bool generate_file_name(char *file_name)
{
	//此处为文件名生成函数
	return true;
}
int main()
{
	int file_num=1;					//要处理的文件数量，默认为1
	char file_name[40];				//文件名缓冲区
	cout<<"enter file num"<<endl;	//此处在之后可以设置为从其他位置传参传过来
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
