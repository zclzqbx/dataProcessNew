//ACline
#include "acline.h"

bool operator==(const ACline& acline1,const ACline& acline2)//判断是否相等
{
	return (acline1.getAClineName()==acline2.getAClineName());
}

ostream& operator<<(ostream& output,ACline& acline)//输出
{
	output<<"线路编号:"<<acline.getAClineCode()<<endl;
	output<<"线路名称:"<<acline.getAClineName()<<endl;
	output<<"线路电压等级:"<<acline.getAClineVolt()<<endl;
	output<<"线路电阻:"<<acline.getAClineR()<<endl;
	output<<"线路电抗:"<<acline.getAClineX()<<endl;
	output<<"线路单端电纳:"<<acline.getAClineB()<<endl;
	output<<"线路I端所在拓扑节点:"<<acline.getAClineI_node()<<endl;
	output<<"线路J端所在拓扑节点:"<<acline.getAClineJ_node()<<endl;
	output<<"线路I端有功功率:"<<acline.getAClineI_P()<<endl;
	output<<"线路I端无功功率:"<<acline.getAClineI_Q()<<endl;
	output<<"线路J端有功功率:"<<acline.getAClineJ_P()<<endl;
	output<<"线路J端无功功率:"<<acline.getAClineJ_Q()<<endl;
	output<<"线路电流限值:"<<acline.getAClineImax()<<endl;
	output<<"线路所在区域:"<<acline.getAClineArea()<<endl;
	output<<"线路I端断开标志:"<<acline.getAClineI_off()<<endl;
	output<<"线路J端断开标志:"<<acline.getAClineJ_off()<<endl;
	return output;
}

bool ACline::printAClineOnline(ostream& output)
{
	if(AClineI_off==1 || AClineJ_off==1)return false;
	output<<"线路编号:"<<getAClineCode()<<endl;
	output<<"线路名称:"<<getAClineName()<<endl;
	output<<"线路电压等级:"<<getAClineVolt()<<endl;
	output<<"线路电阻:"<<getAClineR()<<endl;
	output<<"线路电抗:"<<getAClineX()<<endl;
	output<<"线路单端电纳:"<<getAClineB()<<endl;
	output<<"线路I端所在拓扑节点:"<<getAClineI_node()<<endl;
	output<<"线路J端所在拓扑节点:"<<getAClineJ_node()<<endl;
	output<<"线路I端有功功率:"<<getAClineI_P()<<endl;
	output<<"线路I端无功功率:"<<getAClineI_Q()<<endl;
	output<<"线路J端有功功率:"<<getAClineJ_P()<<endl;
	output<<"线路J端无功功率:"<<getAClineJ_Q()<<endl;
	output<<"线路电流限值:"<<getAClineImax()<<endl;
	output<<"线路所在区域:"<<getAClineArea()<<endl;
	output<<"线路I端断开标志:"<<getAClineI_off()<<endl;
	output<<"线路J端断开标志:"<<getAClineJ_off()<<endl;
	return true;
}

bool ACline::printAClineOfflineBus(ostream& output)
{
	if(AClineI_off || AClineJ_off)
	{
		if(AClineI_off)
		{
			output<<getAClineI_node()<<endl;			
		}
		else
		{
			output<<getAClineJ_off()<<endl;
		}
		return true;
	}
	return false;
		
}