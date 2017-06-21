//Cellular Automaton
//author:GK
//date:2017.6.21
#include<iostream>
#include<string>
#include<windows.h>
#include<time.h>
using namespace std;
class Cell
{
public:
	int state;
	int x,y;
	void InitEnvir();
	void PutSeed(int a,int b);
	void simulation(int InitLifeNum);
	bool Judge(int x,int y);
protected:
private:
	static int n;
	char **environment;
};
int Cell::n=20;
void Cell::InitEnvir()
{
	int i=0,j=0;
	environment=new char *[n];
	for(i=0;i<n;i++)
	{
		environment[i]=new char[n];
		for(j=0;j<n;j++)
		{
			environment[i][j]=' ';
		}
	}
}
void Cell::PutSeed(int a,int b)
{
	environment[a][b]='3';
}
bool Cell::Judge(int x,int y)
{
	int a;
	int i,j,lifenum=0;
	int left=x-3>0?x-3:0;
	int right=x+3<n?x+3:n-1;
	int up=y-3>0?y-3:0;
	int down=y+3<n?y+3:n-1;
	for(i=up,a=2;i<down;i++)
	{	
		for(j=left+a;j<right-a;j++)
		{
			if(environment[i][j]!=' ')
			{
				lifenum++;
			}
		}
		if(a>0)
		{
			a--;
		}
		else
		{
			a++;
		}
	}
	if(environment[x][y]==' '&&lifenum>=3)				//繁殖
	{
		environment[x][y]='3';
	}
	else if(environment[x][y]!=' '&&lifenum<2)			//人口过度稀少
	{
		environment[x][y]--;
	}
	else if (environment[x][y]!=' '&&lifenum>3)			//过度拥挤
	{
		environment[x][y]--;
	}
	else if(environment[x][y]!=' '&&(lifenum==2||lifenum==3))		//适宜环境
	{
		environment[x][y]++;
	}
	else
	{
		environment[x][y]=' ';
	}
	if(environment[x][y]=='0')
	{
		environment[x][y]=' ';
	}
	if(environment[x][y]!=' ')
		return true;
	else
		return false;
}
void Cell::simulation(int InitLifeNum)
{
	bool sign;
	int x,y,add;
	int lifenum=0;
	int i=0,j=0;
	srand((int)time(NULL));
	sign=true;
	while(1)
	{
		cout<<"Cellular Automaton"<<endl;
		add=rand()%20;
		if(add>2&&add<15)
		{
			for(i=0;i<InitLifeNum;i++)
			{
				x=rand()%20;
				y=rand()%20;
				PutSeed(x,y);
			}
		}
		for(i=0;i<n;i++)		//遍历环境进行判决
		{
			for(j=0;j<n;j++)
			{
				if(Judge(i,j))
					lifenum++;
				cout<<environment[i][j];
				cout<<' ';
			}
			cout<<endl;
		}
		cout<<"life num： "<<lifenum;
		if(lifenum==400)
		{
			break;
		}
		lifenum=0;
		Sleep(100);
		system("cls");
	}
}
int main()
{
	int n;
	Cell test;
	cout<<"Cellular Automaton"<<endl;
	cout<<"please input Initial life quantity"<<endl;
	cin>>n;
	test.InitEnvir();
	test.simulation(n);
	return 0;
}
