#include "bus.h"

//Bus�ڵ�
bool operator==(const Bus& bus1,const Bus& bus2)//�ж��Ƿ����
{
	return (bus1.getBusName()==bus2.getBusName());
}

ostream& operator<<(ostream& output,Bus& bus)//���
{
	output<<"�ڵ���:"<<bus.getBusCode()<<endl;
	output<<"�ڵ�����:"<<bus.getBusName()<<endl;
	output<<"�ڵ��ѹ�ȼ�:"<<bus.getBusVolt()<<endl;
	output<<"�ڵ��ѹ:"<<bus.getBusV()<<endl;
	output<<"�ڵ����:"<<bus.getBusAng()<<endl;
	output<<"�ڵ�ͣ��״̬:"<<bus.getBusOff()<<endl;
	output<<"�ڵ�����ѹ:"<<bus.getBusV_max()<<endl;
	output<<"�ڵ���С��ѹ:"<<bus.getBusV_min()<<endl;
	return output;
}

bool Bus::printBusOnline(ostream& output)
{
	if(busOff==1)return false;
	output<<"�ڵ���:"<<getBusCode()<<endl;
	output<<"�ڵ�����:"<<getBusName()<<endl;
	output<<"�ڵ��ѹ�ȼ�:"<<getBusVolt()<<endl;
	output<<"�ڵ��ѹ:"<<getBusV()<<endl;
	output<<"�ڵ����:"<<getBusAng()<<endl;
	output<<"�ڵ�����ѹ:"<<getBusV_max()<<endl;
	output<<"�ڵ���С��ѹ:"<<getBusV_min()<<endl;
	return true;
}