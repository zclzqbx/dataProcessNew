#include "dataClass.h"

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


//TopoNode
bool TopoNode::operator==(const TopoNode& topoNode)
{
	return this->topoNodeName==topoNode.getTopoNodeName();
}

ostream& operator<<(ostream& output,TopoNode& topoNode)
{
	output<<"�ڵ����ƣ�"<<topoNode.getTopoNodeName()<<endl;
	output<<"�ڵ��ѹ��"<<topoNode.getTopoNodeV()<<endl;
	output<<"�ڵ���ǣ�"<<topoNode.getTopoNodeAng()<<endl;
	output<<"�ڵ��ѹ��׼��"<<topoNode.getTopoNodeVbase()<<endl;
	return output;
}


//Unit
bool Unit::operator==(const Unit& unit)
{
	return this->unitTopoNode==unit.getUnitTopoNode();
}

ostream& operator<<(ostream& output,Unit& unit)
{
	output<<"�����ֵ�������־��"<<unit.getUnitEq()<<endl;
	output<<"������ѹ��"<<unit.getUnitV_Rate()<<endl;
	output<<"�������ʣ�"<<unit.getUnitP_Rate()<<endl;
	output<<"�����������˽ڵ㣺"<<unit.getUnitTopoNode()<<endl;
	output<<"�����й�������"<<unit.getUnitP()<<endl;
	output<<"�����޹�������"<<unit.getUnitQ()<<endl;
	output<<"������˵�ѹ��"<<unit.getUnitUe()<<endl;
	output<<"������˵�ѹ��ǣ�"<<unit.getUnitAng()<<endl;
	output<<"����ͣ�˱�־��"<<unit.getUnitOff()<<endl;
	output<<"�����й����ޣ�"<<unit.getUnitP_H()<<endl;
	output<<"�����й����ޣ�"<<unit.getUnitP_L()<<endl;
	output<<"�����޹����ޣ�"<<unit.getUnitQ_H()<<endl;
	output<<"�����޹����ޣ�"<<unit.getUnitQ_L()<<endl;
	output<<"�����ѹ�ȼ���"<<unit.getUnitVolt()<<endl;
	return output;
}


//ACline
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


//Transformer
bool operator==(const Transformer& transformer1,const Transformer& transformer2)//�ж��Ƿ����
{
	return (transformer1.getTransCode()==transformer2.getTransCode());
}

ostream& operator<<(ostream& output,Transformer& transformer)//���
{
	output<<"��ѹ�����:"<<transformer.getTransCode()<<endl;
	output<<"��������:"<<transformer.getTransType()<<endl;
	output<<"��ѹ�˵�ѹ�ȼ�:"<<transformer.getTransI_Vol()<<endl;
	output<<"��ѹ�˵�ѹ�ȼ�:"<<transformer.getTransK_Vol()<<endl;
	output<<"��ѹ�˵�ѹ�ȼ�:"<<transformer.getTransJ_Vol()<<endl;
	output<<"��ѹ�˶����:"<<transformer.getTransI_S()<<endl;
	output<<"��ѹ�˶����:"<<transformer.getTransK_S()<<endl;
	output<<"��ѹ�˶����:"<<transformer.getTransJ_S()<<endl;
	output<<"��ѹ�˷ֽ�ͷ��ߵ�λ:"<<transformer.getTransItap_H()<<endl;
	output<<"��ѹ�˷ֽ�ͷ���е�λ:"<<transformer.getTransItap_L()<<endl;
	output<<"��ѹ�˷ֽ�ͷ��͵�λ:"<<transformer.getTransItap_E()<<endl;
	output<<"��ѹ�˷ֽ�ͷ����:"<<transformer.getTransItap_C()<<endl;
	output<<"��ѹ�˶��ѹ:"<<transformer.getTransItap_V()<<endl;
	output<<"��ѹ�˷ֽ�ͷ��ߵ�λ:"<<transformer.getTransKtap_H()<<endl;
	output<<"��ѹ�˷ֽ�ͷ���е�λ:"<<transformer.getTransKtap_L()<<endl;
	output<<"��ѹ�˷ֽ�ͷ��͵�λ:"<<transformer.getTransKtap_E()<<endl;
	output<<"��ѹ�˷ֽ�ͷ����:"<<transformer.getTransKtap_C()<<endl;	
	output<<"��ѹ�˶��ѹ:"<<transformer.getTransKtap_V()<<endl;
	output<<"��ѹ�˶��ѹ:"<<transformer.getTransJtap_V()<<endl;
	output<<"��ѹ�������:"<<transformer.getTransRi()<<endl;
	output<<"��ѹ����翹:"<<transformer.getTransXi()<<endl;
	output<<"��ѹ�������:"<<transformer.getTransRk()<<endl;
	output<<"��ѹ����翹:"<<transformer.getTransXk()<<endl;
	output<<"��ѹ�������:"<<transformer.getTransRj()<<endl;
	output<<"��ѹ����翹:"<<transformer.getTransXj()<<endl;
	output<<"��ѹ���������˽ڵ�:"<<transformer.getTransI_node()<<endl;
	output<<"��ѹ���������˽ڵ�:"<<transformer.getTransK_node()<<endl;
	output<<"��ѹ���������˽ڵ�:"<<transformer.getTransJ_node()<<endl;
	output<<"��ѹ���й�����:"<<transformer.getTransI_P()<<endl;
	output<<"��ѹ���޹�����:"<<transformer.getTransI_Q()<<endl;
	output<<"��ѹ���й�����:"<<transformer.getTransK_P()<<endl;
	output<<"��ѹ���޹�����:"<<transformer.getTransK_Q()<<endl;
	output<<"��ѹ���й�����:"<<transformer.getTransJ_P()<<endl;
	output<<"��ѹ���޹�����:"<<transformer.getTransJ_Q()<<endl;
	output<<"��ѹ��ֽ�ͷλ��:"<<transformer.getTransI_tap()<<endl;
	output<<"��ѹ��ֽ�ͷλ��:"<<transformer.getTransK_tap()<<endl;
	
	return output;
}
