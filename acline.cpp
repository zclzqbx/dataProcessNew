//ACline
#include "acline.h"

bool operator==(const ACline& acline1,const ACline& acline2)//�ж��Ƿ����
{
	return (acline1.getAClineName()==acline2.getAClineName());
}

ostream& operator<<(ostream& output,ACline& acline)//���
{
	output<<"��·���:"<<acline.getAClineCode()<<endl;
	output<<"��·����:"<<acline.getAClineName()<<endl;
	output<<"��·��ѹ�ȼ�:"<<acline.getAClineVolt()<<endl;
	output<<"��·����:"<<acline.getAClineR()<<endl;
	output<<"��·�翹:"<<acline.getAClineX()<<endl;
	output<<"��·���˵���:"<<acline.getAClineB()<<endl;
	output<<"��·I���������˽ڵ�:"<<acline.getAClineI_node()<<endl;
	output<<"��·J���������˽ڵ�:"<<acline.getAClineJ_node()<<endl;
	output<<"��·I���й�����:"<<acline.getAClineI_P()<<endl;
	output<<"��·I���޹�����:"<<acline.getAClineI_Q()<<endl;
	output<<"��·J���й�����:"<<acline.getAClineJ_P()<<endl;
	output<<"��·J���޹�����:"<<acline.getAClineJ_Q()<<endl;
	output<<"��·������ֵ:"<<acline.getAClineImax()<<endl;
	output<<"��·��������:"<<acline.getAClineArea()<<endl;
	output<<"��·I�˶Ͽ���־:"<<acline.getAClineI_off()<<endl;
	output<<"��·J�˶Ͽ���־:"<<acline.getAClineJ_off()<<endl;
	return output;
}

bool ACline::printAClineOnline(ostream& output)
{
	if(AClineI_off==1 || AClineJ_off==1)return false;
	output<<"��·���:"<<getAClineCode()<<endl;
	output<<"��·����:"<<getAClineName()<<endl;
	output<<"��·��ѹ�ȼ�:"<<getAClineVolt()<<endl;
	output<<"��·����:"<<getAClineR()<<endl;
	output<<"��·�翹:"<<getAClineX()<<endl;
	output<<"��·���˵���:"<<getAClineB()<<endl;
	output<<"��·I���������˽ڵ�:"<<getAClineI_node()<<endl;
	output<<"��·J���������˽ڵ�:"<<getAClineJ_node()<<endl;
	output<<"��·I���й�����:"<<getAClineI_P()<<endl;
	output<<"��·I���޹�����:"<<getAClineI_Q()<<endl;
	output<<"��·J���й�����:"<<getAClineJ_P()<<endl;
	output<<"��·J���޹�����:"<<getAClineJ_Q()<<endl;
	output<<"��·������ֵ:"<<getAClineImax()<<endl;
	output<<"��·��������:"<<getAClineArea()<<endl;
	output<<"��·I�˶Ͽ���־:"<<getAClineI_off()<<endl;
	output<<"��·J�˶Ͽ���־:"<<getAClineJ_off()<<endl;
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