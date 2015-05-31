#include "bus.h"

//Bus节点
bool operator==(const Bus& bus1,const Bus& bus2)//判断是否相等
{
	return (bus1.getBusName()==bus2.getBusName());
}

ostream& operator<<(ostream& output,Bus& bus)//输出
{
	output<<"节点编号:"<<bus.getBusCode()<<endl;
	output<<"节点名称:"<<bus.getBusName()<<endl;
	output<<"节点电压等级:"<<bus.getBusVolt()<<endl;
	output<<"节点电压:"<<bus.getBusV()<<endl;
	output<<"节点相角:"<<bus.getBusAng()<<endl;
	output<<"节点停运状态:"<<bus.getBusOff()<<endl;
	output<<"节点最大电压:"<<bus.getBusV_max()<<endl;
	output<<"节点最小电压:"<<bus.getBusV_min()<<endl;
	return output;
}

bool Bus::printBusOnline(ostream& output)
{
	if(busOff==1)return false;
	output<<"节点编号:"<<getBusCode()<<endl;
	output<<"节点名称:"<<getBusName()<<endl;
	output<<"节点电压等级:"<<getBusVolt()<<endl;
	output<<"节点电压:"<<getBusV()<<endl;
	output<<"节点相角:"<<getBusAng()<<endl;
	output<<"节点最大电压:"<<getBusV_max()<<endl;
	output<<"节点最小电压:"<<getBusV_min()<<endl;
	return true;
}