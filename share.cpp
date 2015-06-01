#include "share.h"

Bus createBus(int code,string name,int volt,double V,
	double ang,bool off,double V_max,double V_min)//�����½ڵ�
{
	Bus bus;
	bus.setBusCode(code);
	bus.setBusName(name);
	bus.setBusVolt(volt);
	bus.setBusV(V);
	bus.setBusAng(ang);
	bus.setBusOff(off);
	bus.setBusV_max(V_max);
	bus.setBusV_min(V_min);
	return bus;
}

void getBusData(ifstream& input,vector<Bus>& vecBus)
{//��ȡ���нڵ���Ϣ
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Bus::nx type=ȫ��>")
		{
			int i=0;
			str.clear();
			getline(input,str);
			vector<string> vecBusHeader=split(str);
			
			int busNameColumn(0);//ʶ���ͷ
			int busVoltColumn(0);
			int busVColumn(0);
			int busAngColumn(0);
			int busOffColumn(0);
			int busV_maxColumn(0);
			int busV_minColumn(0);
			for(size_t t=0;t<vecBusHeader.size();++t)
			{
				if(vecBusHeader[t]=="node")
				{
					busNameColumn=t;
				}
				else if(vecBusHeader[t]=="volt")
				{
					busVoltColumn=t;
				}
				else if(vecBusHeader[t]=="V")
				{
					busVColumn=t;
				}
				else if(vecBusHeader[t]=="Ang")
				{
					busAngColumn=t;
				}
				else if(vecBusHeader[t]=="off")
				{
					busOffColumn=t;
				}
				else if(vecBusHeader[t]=="v_max")
				{
					busV_maxColumn=t;
				}
				else if(vecBusHeader[t]=="v_min")
				{
					busV_minColumn=t;
				}
				else
					continue;
			}
			const int busNameColumnConst=busNameColumn;
			const int busVoltColumnConst=busVoltColumn;
			const int busVColumnConst=busVColumn;
			const int busAngColumnConst=busAngColumn;
			const int busOffColumnConst=busOffColumn;
			const int busV_maxColumnConst=busV_maxColumn;
			const int busV_minColumnConst=busV_minColumn;
			//��¼����Ҫ���е�λ��

			str.clear();//����һ�������ǲ���Ҫ�ģ������һ������
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Bus::nx>")
			{
				vector<string> vec=split(str);
				//�������ݶ��Ѿ������vec�У���������ѡ����������,����������ת��
				int volt=stringToInt(vec[busVoltColumnConst]);
				double v=stringToDouble(vec[busVColumnConst]);
				double ang=stringToDouble(vec[busAngColumnConst]);
				bool off=stringToBool(vec[busOffColumnConst]);
				double V_max=stringToDouble(vec[busV_maxColumnConst]);
				double V_min=stringToDouble(vec[busV_minColumnConst]);
				Bus bus=createBus(i,vec[busNameColumnConst],volt,v,ang,off,V_max,V_min);
				size_t t=0;
				for(;t<vecBus.size();++t)
				{
					if(vecBus[t]==bus)
					{
						str.clear();
						getline(input,str);
						break;
					}
				}
				if(t<vecBus.size())continue;
				vecBus.push_back(bus);
				i++;
				str.clear();
				getline(input,str);
			}
		}
		if(str=="</Bus::nx>")
			break;
	}
}

ACline createACline(int code,string name,int volt,double r,
	double x,double b, string i_node,string j_node,double i_p,double i_q,
	double j_p,double j_q,double imax,string area,bool iOff,bool jOff)//��������·
{
	ACline acLine;
	acLine.setAClineCode(code);
	acLine.setAClineName(name);
	acLine.setAClineVolt(volt);
	acLine.setAClineR(r);
	acLine.setAClineX(x);
	acLine.setAClineB(b);
	acLine.setAClineI_node(i_node);
	acLine.setAClineJ_node(j_node);
	acLine.setAClineI_P(i_p);
	acLine.setAClineI_Q(i_q);
	acLine.setAClineJ_P(j_p);
	acLine.setAClineJ_Q(j_q);
	acLine.setAClineImax(imax);
	acLine.setAClineArea(area);
	acLine.setAClineI_off(iOff);
	acLine.setAClineJ_off(jOff);
	return acLine;
}

void getAClineData(ifstream& input,vector<ACline>& vecACline)
{//��ȡ����ACline
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<ACline::nx type=ȫ��>")
		{//��Ҫ�ȶ�ȡ�ܶ���������Ϣ�����ҵ�Ŀ���У������������Կ��ǸĽ�
			int i=0;
			str.clear();
			getline(input,str);
			vector<string> vecAClineHeader=split(str);
			
			int AClineNameColumn(0);//ʶ���ͷ
			int AClineVoltColumn(0);
			int AClineRColumn(0);
			int AClineXColumn(0);
			int AClineBColumn(0);
			int AClineI_nodeColumn(0);
			int AClineJ_nodeColumn(0);
			int AClineI_PColumn(0);
			int AClineI_QColumn(0);
			int AClineJ_PColumn(0);
			int AClineJ_QColumn(0);
			int AClineImaxColumn(0);
			int AClineAreaColumn(0);
			int AClineI_offColumn(0);
			int AClineJ_offColumn(0);

			for(size_t t=0;t<vecAClineHeader.size();++t)
			{//������ö���滻��������
				if(vecAClineHeader[t]=="name")
				{
					AClineNameColumn=t;
				}
				else if(vecAClineHeader[t]=="volt")
				{
					AClineVoltColumn=t;
				}
				else if(vecAClineHeader[t]=="R")
				{
					AClineRColumn=t;
				}
				else if(vecAClineHeader[t]=="X")
				{
					AClineXColumn=t;
				}
				else if(vecAClineHeader[t]=="B")
				{
					AClineBColumn=t;
				}
				else if(vecAClineHeader[t]=="I_node")
				{
					AClineI_nodeColumn=t;
				}
				else if(vecAClineHeader[t]=="J_node")
				{
					AClineJ_nodeColumn=t;
				}
				else if(vecAClineHeader[t]=="I_P")
				{
					AClineI_PColumn=t;
				}
				else if(vecAClineHeader[t]=="I_Q")
				{
					AClineI_QColumn=t;
				}
				else if(vecAClineHeader[t]=="J_P")
				{
					AClineJ_PColumn=t;
				}
				else if(vecAClineHeader[t]=="J_Q")
				{
					AClineJ_QColumn=t;
				}
				else if(vecAClineHeader[t]=="Imax")
				{
					AClineImaxColumn=t;
				}
				else if(vecAClineHeader[t]=="area")
				{
					AClineAreaColumn=t;
				}
				else if(vecAClineHeader[t]=="I_off")
				{
					AClineI_offColumn=t;
				}
				else if(vecAClineHeader[t]=="J_off")
				{
					AClineJ_offColumn=t;
				}
				else
					continue;
			}
			
			const int AClineNameColumnConst=AClineNameColumn;
			const int AClineVoltColumnConst=AClineVoltColumn;
			const int AClineRColumnConst=AClineRColumn;
			const int AClineXColumnConst=AClineXColumn;
			const int AClineBColumnConst=AClineBColumn;
			const int AClineI_nodeColumnConst=AClineI_nodeColumn;
			const int AClineJ_nodeColumnConst=AClineJ_nodeColumn;
			const int AClineI_PColumnConst=AClineI_PColumn;
			const int AClineI_QColumnConst=AClineI_QColumn;
			const int AClineJ_PColumnConst=AClineJ_PColumn;
			const int AClineJ_QColumnConst=AClineJ_QColumn;
			const int AClineImaxColumnConst=AClineImaxColumn;
			const int AClineAreaColumnConst=AClineAreaColumn;
			const int AClineI_offColumnConst=AClineI_offColumn;
			const int AClineJ_offColumnConst=AClineJ_offColumn;
			//��¼����Ҫ���е�λ��

			str.clear();//����һ�������ǲ���Ҫ�ģ������һ������
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</ACline::nx>")
			{
				vector<string> vec=split(str);
				//�������ݶ��Ѿ������vec�У���������ѡ����������,����������ת��
				int volt=stringToInt(vec[AClineVoltColumnConst]);
				string name=vec[AClineNameColumnConst];
				double r=stringToDouble(vec[AClineRColumnConst]);
				double x=stringToDouble(vec[AClineXColumnConst]);
				double b=stringToDouble(vec[AClineBColumnConst]);
				string i_nodename=vec[AClineI_nodeColumnConst];
				string j_nodename=vec[AClineJ_nodeColumnConst];
				double i_p=stringToDouble(vec[AClineI_PColumnConst]);
				double i_q=stringToDouble(vec[AClineI_QColumnConst]);
				double j_p=stringToDouble(vec[AClineJ_PColumnConst]);
				double j_q=stringToDouble(vec[AClineJ_QColumnConst]);
				double imax=stringToDouble(vec[AClineImaxColumnConst]);				
				string area=vec[AClineAreaColumnConst];
				bool iOff=stringToBool(vec[AClineI_offColumnConst]);
				bool jOff=stringToBool(vec[AClineJ_offColumnConst]);
				
				//�ж�ACline���˽ڵ��Ƿ���Bus���ڣ����ҵ���Ӧ�����˽ڵ��ţ�������Ϊ������Ϣ
				/*int i_node=0;
				int j_node=0;//���˽ڵ���
				
				//�������ǲ����ܴ�����ͬ�ڵ��
				if(i_nodename==j_nodename)continue;
				
				for(vector<Bus>::iterator iter=vecBus.begin();iter!=vecBus.end();++iter)
				{
					if(i_nodename==iter->getBusName())
						i_node=iter->getBusCode();
					else if(j_nodename==iter->getBusName())
						j_node=iter->getBusCode();
				}*/

				//��bus�����ҵ���Ӧ�Ľڵ�Ŵ���ACline����
			
				ACline acline=createACline(i,name,volt,r,x,b,i_nodename,j_nodename,
						i_p,i_q,j_p,j_q,imax,area,iOff,jOff);
				size_t t=0;
				for(;t<vecACline.size();++t)
				{//�ж��Ƿ������֧ͬ·����ʵû��Ҫ��������������ֻ�����ǰ���ɸ�
					if(vecACline[t]==acline)
					{
						str.clear();
						getline(input,str);
						break;
					}
				}
				if(t<vecACline.size())continue;
				vecACline.push_back(acline);
				i++;
				
				str.clear();
				getline(input,str);
			}
		}
		if(str=="</ACline::nx>")
			break;
	}
}

TopoNode createTopoNode(string name,double v,double ang,double vbase)
{
	TopoNode topoNode;
	topoNode.setTopoNodeName(name);
	topoNode.setTopoNodeV(v);
	topoNode.setTopoNodeAng(ang);
	topoNode.setTopoNodeVbase(vbase);
	return topoNode;
}

void getTopoNode(ifstream& input,vector<TopoNode>& vecTopoNode)
{//��ȡ����ACline	
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<TopoNode::nx type=ȫ��>")
		{//��Ҫ�ȶ�ȡ�ܶ���������Ϣ�����ҵ�Ŀ���У������������Կ��ǸĽ�
			str.clear();
			getline(input,str);
			vector<string> vecTopoNodeHeader=split(str);
			
			int TopoNodeNameColumn(0);//ʶ���ͷ
			int TopoNodeVColumn(0);
			int TopoNodeAngColumn(0);
			int TopoNodeVbaseColumn(0);
			
			for(size_t t=0;t<vecTopoNodeHeader.size();++t)
			{//����switch��������
				if(vecTopoNodeHeader[t]=="name")
				{
					TopoNodeNameColumn=t;
				}
				else if(vecTopoNodeHeader[t]=="v")
				{
					TopoNodeVColumn=t;
				}
				else if(vecTopoNodeHeader[t]=="ang")
				{
					TopoNodeAngColumn=t;
				}
				else if(vecTopoNodeHeader[t]=="vbase")
				{
					TopoNodeVbaseColumn=t;
				}
				else
					continue;	
			}
			
			const int TopoNodeNameColumnConst=TopoNodeNameColumn;
			const int TopoNodeVColumnConst=TopoNodeVColumn;
			const int TopoNodeAngColumnConst=TopoNodeAngColumn;
			const int TopoNodeVbaseColumnConst=TopoNodeVbaseColumn;
			//��¼����Ҫ���е�λ��

			str.clear();//����һ�������ǲ���Ҫ�ģ������һ������
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</TopoNode::nx>")
			{
				vector<string> vec=split(str);
				//�������ݶ��Ѿ������vec�У���������ѡ����������,����������ת��
				string name=vec[TopoNodeNameColumnConst];
				double v=stringToDouble(vec[TopoNodeVColumnConst]);
				double ang=stringToDouble(vec[TopoNodeAngColumnConst]);
				double vbase=stringToDouble(vec[TopoNodeVbaseColumnConst]);
				
				//��bus�����ҵ���Ӧ�Ľڵ�Ŵ���ACline����			
				TopoNode topoNode=createTopoNode(name,v,ang,vbase);
				
				size_t t=0;
				for(;t<vecTopoNode.size();++t)
				{//�ж��Ƿ������֧ͬ·����ʵû��Ҫ��������������ֻ�����ǰ���ɸ�
					if(vecTopoNode[t]==topoNode)
					{
						str.clear();
						getline(input,str);
						break;
					}
				}
				if(t<vecTopoNode.size())continue;				
				vecTopoNode.push_back(topoNode);

				str.clear();
				getline(input,str);
			}
		}
		if(str=="</TopoNode::nx>")
			break;
	}
}

Unit createUnit(bool eq,double v_Rate,double p_Rate,string topoNode,
				double p,double q,double ue,double ang,bool off,
				double p_H,double p_L,double q_H,double q_L,int volt)
{
	Unit unit;	
	unit.setUnitEq(eq);
	unit.setUnitV_Rate(v_Rate);
	unit.setUnitP_Rate(p_Rate);
	unit.setUnitTopoNode(topoNode);
	unit.setUnitP(p);
	unit.setUnitQ(q);
	unit.setUnitUe(ue);
	unit.setUnitAng(ang);
	unit.setUnitOff(off);
	unit.setUnitP_H(p_H);
	unit.setUnitP_L(p_L);
	unit.setUnitQ_H(q_H);
	unit.setUnitQ_L(q_L);
	unit.setUnitVolt(volt);
	return unit;
}

void getUnit(ifstream& input,vector<Unit>& vecUnit)
{
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Unit::nx type=ȫ��>")
		{//��Ҫ�ȶ�ȡ�ܶ���������Ϣ�����ҵ�Ŀ���У������������Կ��ǸĽ�
			str.clear();
			getline(input,str);
			vector<string> vecUnitHeader=split(str);
			
			int UnitEqColumn(0);//ʶ���ͷ
			int UnitV_RateColumn(0);
			int UnitP_RateColumn(0);
			int UnitTopoNodeColumn(0);
			int UnitPColumn(0);
			int UnitQColumn(0);
			int UnitUeColumn(0);
			int UnitAngColumn(0);
			int UnitOffColumn(0);
			int UnitP_HColumn(0);
			int UnitP_LColumn(0);
			int UnitQ_HColumn(0);
			int UnitQ_LColumn(0);
			int UnitVoltColumn(0);
			
			for(size_t t=0;t<vecUnitHeader.size();++t)
			{//����switch��������
				if(vecUnitHeader[t]=="Eq")
				{
					UnitEqColumn=t;
				}
				else if(vecUnitHeader[t]=="V_Rate")
				{
					UnitV_RateColumn=t;
				}
				else if(vecUnitHeader[t]=="P_Rate")
				{
					UnitP_RateColumn=t;
				}
				else if(vecUnitHeader[t]=="node")
				{
					UnitTopoNodeColumn=t;
				}
				else if(vecUnitHeader[t]=="P")
				{
					UnitPColumn=t;
				}
				else if(vecUnitHeader[t]=="Q")
				{
					UnitQColumn=t;
				}
				else if(vecUnitHeader[t]=="Ue")
				{
					UnitUeColumn=t;
				}
				else if(vecUnitHeader[t]=="Ang")
				{
					UnitAngColumn=t;
				}
				else if(vecUnitHeader[t]=="off")
				{
					UnitOffColumn=t;
				}
				else if(vecUnitHeader[t]=="P_H")
				{
					UnitP_HColumn=t;
				}
				else if(vecUnitHeader[t]=="P_L")
				{
					UnitP_LColumn=t;
				}
				else if(vecUnitHeader[t]=="Q_H")
				{
					UnitQ_HColumn=t;
				}
				else if(vecUnitHeader[t]=="Q_L")
				{
					UnitQ_LColumn=t;
				}
				else if(vecUnitHeader[t]=="Volt")
				{
					UnitVoltColumn=t;
				}
				else
					continue;
			}
			
			const int UnitEqColumnConst=UnitEqColumn;//ʶ���ͷ
			const int UnitV_RateColumnConst=UnitV_RateColumn;
			const int UnitP_RateColumnConst=UnitP_RateColumn;
			const int UnitTopoNodeColumnConst=UnitTopoNodeColumn;
			const int UnitPColumnConst=UnitPColumn;
			const int UnitQColumnConst=UnitQColumn;
			const int UnitUeColumnConst=UnitUeColumn;
			const int UnitAngColumnConst=UnitAngColumn;
			const int UnitOffColumnConst=UnitOffColumn;
			const int UnitP_HColumnConst=UnitP_HColumn;
			const int UnitP_LColumnConst=UnitP_LColumn;
			const int UnitQ_HColumnConst=UnitQ_HColumn;
			const int UnitQ_LColumnConst=UnitQ_LColumn;
			const int UnitVoltColumnConst=UnitVoltColumn;
			//��¼����Ҫ���е�λ��

			str.clear();//����һ�������ǲ���Ҫ�ģ������һ������
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Unit::nx>")
			{
				vector<string> vec=split(str);
				//�������ݶ��Ѿ������vec�У���������ѡ����������,����������ת��
				bool eq=stringToBool(vec[UnitEqColumnConst]);
				double v_Rate=stringToDouble(vec[UnitV_RateColumnConst]);
				double p_Rate=stringToDouble(vec[UnitP_RateColumnConst]);
				string topoNode=vec[UnitTopoNodeColumnConst];
				double p=stringToDouble(vec[UnitPColumnConst]);
				double q=stringToDouble(vec[UnitQColumnConst]);
				double ue=stringToDouble(vec[UnitUeColumnConst]);
				double ang=stringToDouble(vec[UnitAngColumnConst]);
				bool off=stringToBool(vec[UnitOffColumnConst]);
				double p_H=stringToDouble(vec[UnitP_HColumnConst]);
				double p_L=stringToDouble(vec[UnitP_LColumnConst]);
				double q_H=stringToDouble(vec[UnitQ_HColumnConst]);
				double q_L=stringToDouble(vec[UnitQ_LColumnConst]);
				int volt=stringToInt(vec[UnitVoltColumnConst]);
				
				//��bus�����ҵ���Ӧ�Ľڵ�Ŵ���ACline����			
				Unit unit=createUnit(eq,v_Rate,p_Rate,topoNode,p,q,ue,ang,off,
										p_H,p_L,q_H,q_L,volt);

				vecUnit.push_back(unit);

				str.clear();
				getline(input,str);
			}
		}
		if(str=="</Unit::nx>")
			break;
	}
}

void getData(ifstream& input,vector<Bus>& vecBus,vector<ACline>& vecACLine,
				vector<TopoNode>& vecTopoNode,vector<Unit>& vecUnit)
{//��������get������һ���Զ�ȡ
//�б�Ҫ�˽�input��getline����ô�����ġ�
//ʹ�ù�һ�Σ�Ȼ���ٴ�ʹ���ѵ�û��Ӱ����
	getBusData(input,vecBus);
	getAClineData(input,vecACLine);	
	getUnit(input,vecUnit);
	getTopoNode(input,vecTopoNode);
}