#include "fstring.h"

vector<string> split(string str)//分割字符串函数
{
	vector<string> vec;
	size_t i=0;
	string subStr;
	subStr.clear();
	while(i<str.size())
	{
		if(str[i]==' ')
		{
			if(!subStr.empty())
				vec.push_back(subStr);
			subStr.clear();
		}
		else
		{
			subStr+=str[i];
		}
		++i;
	}
	vec.push_back(subStr);
	return vec;
}

int stringToInt(string& str)//转化成整数
{
	int returnInt(0);
	bool flagPlusMinus=0;
	size_t i=0;
	if(str[0]=='-')
	{
		i++;
		flagPlusMinus=1;
	}
	for(;i<str.size();++i)
		returnInt=returnInt*10+str[i]-'0';
	if(flagPlusMinus)
		returnInt*=(-1);
	return returnInt;
}

double stringToDouble(string& str)//转化成浮点数
{
	double returnDouble(0);
	size_t i=0;
	size_t flag=200;
	int decimalNum(0);
	bool flagPlusMinus=0;
	if(str[0]=='-')
	{
		i++;
		flagPlusMinus=1;
	}
	for(;i<str.size();++i)
	{
		if(str[i]=='.')
		{
			flag=i;
			continue;
		}
		if(i>flag)
		{
			decimalNum++;
		}
		returnDouble=returnDouble*10+str[i]-'0';
	}
	for(int t=0;t<decimalNum;++t)
		returnDouble/=10;
	
	if(flagPlusMinus)
		returnDouble*=(-1);
	return returnDouble;
}

bool stringToBool(string& str)//转化成布尔型
{
	if(str=="1")
		return 1;
	else
		return 0;	
}