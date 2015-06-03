#include "share.h"
#include "fstring.h"

Bus createBus(int code,string name,int volt,double V,
	double ang,bool off,double V_max,double V_min)//创建新节点
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
{//读取所有节点信息
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Bus::nx type=全数>")
		{
			int i=0;
			str.clear();
			getline(input,str);
			vector<string> vecBusHeader=split(str);
			
			int busNameColumn(0);//识别表头
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
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Bus::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据,对数所进行转换
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
	double j_p,double j_q,double imax,string area,bool iOff,bool jOff)//创建新线路
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
{//读取所有ACline
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<ACline::nx type=全数>")
		{//需要先读取很多行无用信息才能找到目标行，检索方法可以考虑改进
			int i=0;
			str.clear();
			getline(input,str);
			vector<string> vecAClineHeader=split(str);
			
			int AClineNameColumn(0);//识别表头
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
			{//考虑用枚举替换，更清晰
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
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</ACline::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据,对数所进行转换
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
				
				//判断ACline两端节点是否都在Bus表内，并找到对应的拓扑节点编号，满足则为有用信息
				/*int i_node=0;
				int j_node=0;//拓扑节点编号
				
				//理论上是不可能存在相同节点的
				if(i_nodename==j_nodename)continue;
				
				for(vector<Bus>::iterator iter=vecBus.begin();iter!=vecBus.end();++iter)
				{
					if(i_nodename==iter->getBusName())
						i_node=iter->getBusCode();
					else if(j_nodename==iter->getBusName())
						j_node=iter->getBusCode();
				}*/

				//在bus表中找到对应的节点才创建ACline对象
			
				ACline acline=createACline(i,name,volt,r,x,b,i_nodename,j_nodename,
						i_p,i_q,j_p,j_q,imax,area,iOff,jOff);
				size_t t=0;
				for(;t<vecACline.size();++t)
				{//判断是否存在相同支路，其实没必要检索整个容器，只需检索前若干个
				//其实没必要判断，不会出现相同支路
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
{//读取所有ACline	
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<TopoNode::nx type=全数>")
		{//需要先读取很多行无用信息才能找到目标行，检索方法可以考虑改进
			str.clear();
			getline(input,str);
			vector<string> vecTopoNodeHeader=split(str);
			
			int TopoNodeNameColumn(0);//识别表头
			int TopoNodeVColumn(0);
			int TopoNodeAngColumn(0);
			int TopoNodeVbaseColumn(0);
			
			for(size_t t=0;t<vecTopoNodeHeader.size();++t)
			{//考虑switch，更清晰
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
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</TopoNode::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据,对数所进行转换
				string name=vec[TopoNodeNameColumnConst];
				double v=stringToDouble(vec[TopoNodeVColumnConst]);
				double ang=stringToDouble(vec[TopoNodeAngColumnConst]);
				double vbase=stringToDouble(vec[TopoNodeVbaseColumnConst]);
				
				//在bus表中找到对应的节点才创建ACline对象			
				TopoNode topoNode=createTopoNode(name,v,ang,vbase);
				
				size_t t=0;
				for(;t<vecTopoNode.size();++t)
				{//判断是否存在相同支路，其实没必要检索整个容器，只需检索前若干个
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
		if(str=="<Unit::nx type=全数>")
		{//需要先读取很多行无用信息才能找到目标行，检索方法可以考虑改进
			str.clear();
			getline(input,str);
			vector<string> vecUnitHeader=split(str);
			
			int UnitEqColumn(0);//识别表头
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
			{//考虑switch，更清晰
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
			
			const int UnitEqColumnConst=UnitEqColumn;//识别表头
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
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Unit::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据,对数所进行转换
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
				
				//在bus表中找到对应的节点才创建ACline对象			
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

Transformer createTransformer(int code,int type,int i_Vol,int k_Vol,int j_Vol,
					int i_S,int k_S,int j_S,int itap_H,int itap_L,int itap_E,
					double itap_C,int itap_V,int ktap_H,int ktap_L,int ktap_E,
					double ktap_C,int ktap_V,int jtap_V,double ri,double xi,double rk,
					double xk,double rj,double xj,string i_node,string k_node,string j_node,
					double i_p,double i_q,double k_p,double k_q,double j_p,double j_q,
					int i_tap,int k_tap,bool iOff,bool kOff,bool jOff)//创建新线路
{
	Transformer trans;
	trans.setTransCode(code);
	trans.setTransType(type);
	trans.setTransI_Vol(i_Vol);
	trans.setTransK_Vol(k_Vol);
	trans.setTransJ_Vol(j_Vol);
	trans.setTransI_S(i_S);
	trans.setTransK_S(k_S);
	trans.setTransJ_S(j_S);
	trans.setTransItap_H(itap_H);
	trans.setTransItap_L(itap_L);
	trans.setTransItap_E(itap_E);
	trans.setTransItap_C(itap_C);
	trans.setTransItap_V(itap_V);
	trans.setTransKtap_H(ktap_H);
	trans.setTransKtap_L(ktap_L);
	trans.setTransKtap_E(ktap_E);
	trans.setTransKtap_C(ktap_C);
	trans.setTransKtap_V(ktap_V);
	trans.setTransJtap_V(jtap_V);
	trans.setTransRi(ri);
	trans.setTransXi(xi);
	trans.setTransRk(rk);
	trans.setTransXk(xk);
	trans.setTransRj(rj);
	trans.setTransXj(xj);
	
	trans.setTransI_node(i_node);
	trans.setTransK_node(k_node);
	trans.setTransJ_node(j_node);
	
	trans.setTransI_P(i_p);
	trans.setTransI_Q(i_q);
	trans.setTransK_P(k_p);
	trans.setTransK_Q(k_q);
	trans.setTransJ_P(j_p);
	trans.setTransJ_Q(j_q);
	trans.setTransI_tap(i_tap);
	trans.setTransK_tap(k_tap);
	
	trans.setTransI_off(iOff);
	trans.setTransK_off(kOff);
	trans.setTransJ_off(jOff);
	
	return trans;
}

void getTransData(ifstream& input,vector<Transformer>& vecTrans)
{//读取所有节点或其他信息函数
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Transformer::nx type=全数>")
		{
			str.clear();
			getline(input,str);
			vector<string> vecTransHeader=split(str);
			
			//识别表头
			int transCodeColumn(0);
			int transTypeColumn(0);
			int transI_VolColumn(0);
			int transK_VolColumn(0);
			int transJ_VolColumn(0);
			int transI_SColumn(0);
			int transK_SColumn(0);
			int transJ_SColumn(0);
			int transItap_HColumn(0);
			int transItap_LColumn(0);
			int transItap_EColumn(0);
			int transItap_CColumn(0);
			int transItap_VColumn(0);
			int transKtap_HColumn(0);
			int transKtap_LColumn(0);
			int transKtap_EColumn(0);
			int transKtap_CColumn(0);
			int transKtap_VColumn(0);
			int transJtap_VColumn(0);
			int transRiColumn(0);
			int transXiColumn(0);
			int transRkColumn(0);
			int transXkColumn(0);
			int transRjColumn(0);
			int transXjColumn(0);
			int transI_nodeColumn(0);
			int transK_nodeColumn(0);
			int transJ_nodeColumn(0);
			int transI_PColumn(0);
			int transI_QColumn(0);
			int transK_PColumn(0);
			int transK_QColumn(0);
			int transJ_PColumn(0);
			int transJ_QColumn(0);
			int transI_tapColumn(0);
			int transK_tapColumn(0);
			int transI_offColumn(0);
			int transK_offColumn(0);
			int transJ_offColumn(0);

			for(size_t t=0;t<vecTransHeader.size();++t)
			{
				if(vecTransHeader[t]=="id")
				{
					transCodeColumn=t;
				}
				else if(vecTransHeader[t]=="type")
				{
					transTypeColumn=t;
				}
				else if(vecTransHeader[t]=="I_Vol")
				{
					transI_VolColumn=t;
				}
				else if(vecTransHeader[t]=="K_Vol")
				{
					transK_VolColumn=t;
				}
				else if(vecTransHeader[t]=="J_Vol")
				{
					transJ_VolColumn=t;
				}
				else if(vecTransHeader[t]=="I_S")
				{
					transI_SColumn=t;
				}
				else if(vecTransHeader[t]=="K_S")
				{
					transK_SColumn=t;
				}
				else if(vecTransHeader[t]=="J_S")
				{
					transJ_SColumn=t;
				}
				else if(vecTransHeader[t]=="Itap_H")
				{
					transItap_HColumn=t;
				}
				else if(vecTransHeader[t]=="Itap_L")
				{
					transItap_LColumn=t;
				}
				else if(vecTransHeader[t]=="Itap_E")
				{
					transItap_EColumn=t;
				}
				else if(vecTransHeader[t]=="Itap_C")
				{
					transItap_CColumn=t;
				}
				else if(vecTransHeader[t]=="Itap_V")
				{
					transItap_VColumn=t;
				}
				else if(vecTransHeader[t]=="Ktap_H")
				{
					transKtap_HColumn=t;
				}
				else if(vecTransHeader[t]=="Ktap_L")
				{
					transKtap_LColumn=t;
				}
				else if(vecTransHeader[t]=="Ktap_E")
				{
					transKtap_EColumn=t;
				}
				else if(vecTransHeader[t]=="Ktap_C")
				{
					transKtap_CColumn=t;
				}
				else if(vecTransHeader[t]=="Ktap_V")
				{
					transKtap_VColumn=t;
				}
				else if(vecTransHeader[t]=="Jtap_V")
				{
					transJtap_VColumn=t;
				}
				else if(vecTransHeader[t]=="Ri")
				{
					transRiColumn=t;
				}
				else if(vecTransHeader[t]=="Xi")
				{
					transXiColumn=t;
				}
				else if(vecTransHeader[t]=="Rk")
				{
					transRkColumn=t;
				}
				else if(vecTransHeader[t]=="Xk")
				{
					transXkColumn=t;
				}
				else if(vecTransHeader[t]=="Rj")
				{
					transRjColumn=t;
				}
				else if(vecTransHeader[t]=="Xj")
				{
					transXjColumn=t;
				}
				else if(vecTransHeader[t]=="I_node")
				{
					transI_nodeColumn=t;
				}
				else if(vecTransHeader[t]=="K_node")
				{
					transK_nodeColumn=t;
				}
				else if(vecTransHeader[t]=="J_node")
				{
					transJ_nodeColumn=t;
				}
				else if(vecTransHeader[t]=="I_P")
				{
					transI_PColumn=t;
				}
				else if(vecTransHeader[t]=="I_Q")
				{
					transI_QColumn=t;
				}
				else if(vecTransHeader[t]=="K_P")
				{
					transK_PColumn=t;
				}
				else if(vecTransHeader[t]=="K_Q")
				{
					transK_QColumn=t;
				}
				else if(vecTransHeader[t]=="J_P")
				{
					transJ_PColumn=t;
				}
				else if(vecTransHeader[t]=="J_Q")
				{
					transJ_QColumn=t;
				}
				else if(vecTransHeader[t]=="I_tap")
				{
					transI_tapColumn=t;
				}
				else if(vecTransHeader[t]=="K_tap")
				{
					transK_tapColumn=t;
				}
				else if(vecTransHeader[t]=="I_off")
				{
					transI_offColumn=t;
				}	
				else if(vecTransHeader[t]=="K_off")
				{
					transK_offColumn=t;
				}	
				else if(vecTransHeader[t]=="J_off")
				{
					transJ_offColumn=t;
				}					
				else
					continue;
			}
			
			const int transCodeColumnConst=transCodeColumn;
			const int transTypeColumnConst=transTypeColumn;
			const int transI_VolColumnConst=transI_VolColumn;
			const int transK_VolColumnConst=transK_VolColumn;
			const int transJ_VolColumnConst=transJ_VolColumn;
			const int transI_SColumnConst=transI_SColumn;
			const int transK_SColumnConst=transK_SColumn;
			const int transJ_SColumnConst=transJ_SColumn;
			const int transItap_HColumnConst=transItap_HColumn;
			const int transItap_LColumnConst=transItap_LColumn;
			const int transItap_EColumnConst=transItap_EColumn;
			const int transItap_CColumnConst=transItap_CColumn;
			const int transItap_VColumnConst=transItap_VColumn;
			const int transKtap_HColumnConst=transKtap_HColumn;
			const int transKtap_LColumnConst=transKtap_LColumn;
			const int transKtap_EColumnConst=transKtap_EColumn;
			const int transKtap_CColumnConst=transKtap_CColumn;
			const int transKtap_VColumnConst=transKtap_VColumn;
			const int transJtap_VColumnConst=transJtap_VColumn;
			const int transRiColumnConst=transRiColumn;
			const int transXiColumnConst=transXiColumn;
			const int transRkColumnConst=transRkColumn;
			const int transXkColumnConst=transXkColumn;
			const int transRjColumnConst=transRjColumn;
			const int transXjColumnConst=transXjColumn;
			const int transI_nodeColumnConst=transI_nodeColumn;
			const int transK_nodeColumnConst=transK_nodeColumn;
			const int transJ_nodeColumnConst=transJ_nodeColumn;
			const int transI_PColumnConst=transI_PColumn;
			const int transI_QColumnConst=transI_QColumn;
			const int transK_PColumnConst=transK_PColumn;
			const int transK_QColumnConst=transK_QColumn;
			const int transJ_PColumnConst=transJ_PColumn;
			const int transJ_QColumnConst=transJ_QColumn;
			const int transI_tapColumnConst=transI_tapColumn;
			const int transK_tapColumnConst=transK_tapColumn;
			const int transI_offColumnConst=transI_offColumn;
			const int transK_offColumnConst=transK_offColumn;
			const int transJ_offColumnConst=transJ_offColumn;
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Transformer::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据,对数所进行转换
				int code=stringToInt(vec[transCodeColumnConst]);
				int type=stringToInt(vec[transTypeColumnConst]);
				int i_vol=stringToInt(vec[transI_VolColumnConst]);
				int k_vol=stringToInt(vec[transK_VolColumnConst]);
				int j_vol=stringToInt(vec[transJ_VolColumnConst]);
				int i_s=stringToInt(vec[transI_SColumnConst]);
				int k_s=stringToInt(vec[transK_SColumnConst]);
				int j_s=stringToInt(vec[transJ_SColumnConst]);
				int itap_h=stringToInt(vec[transItap_HColumnConst]);
				int itap_l=stringToInt(vec[transItap_LColumnConst]);
				int itap_e=stringToInt(vec[transItap_EColumnConst]);
				double itap_c=stringToDouble(vec[transItap_CColumnConst]);
				int itap_v=stringToInt(vec[transItap_VColumnConst]);
				int ktap_h=stringToInt(vec[transKtap_HColumnConst]);
				int ktap_l=stringToInt(vec[transKtap_LColumnConst]);
				int ktap_e=stringToInt(vec[transKtap_EColumnConst]);
				double ktap_c=stringToDouble(vec[transKtap_CColumnConst]);
				int ktap_v=stringToInt(vec[transKtap_VColumnConst]);
				int jtap_v=stringToInt(vec[transJtap_VColumnConst]);
				double ri=stringToDouble(vec[transRiColumnConst]);
				double xi=stringToDouble(vec[transXiColumnConst]);
				double rk=stringToDouble(vec[transRkColumnConst]);
				double xk=stringToDouble(vec[transXkColumnConst]);
				double rj=stringToDouble(vec[transRjColumnConst]);
				double xj=stringToDouble(vec[transXjColumnConst]);
				
				string i_node=vec[transI_nodeColumnConst];
				// string i_node="abcefdfdfaf";
				string k_node=vec[transK_nodeColumnConst];
				string j_node=vec[transJ_nodeColumnConst];
				
				double i_p=stringToDouble(vec[transI_PColumnConst]);
				double i_q=stringToDouble(vec[transI_QColumnConst]);
				double k_p=stringToDouble(vec[transK_PColumnConst]);
				double k_q=stringToDouble(vec[transK_QColumnConst]);
				double j_p=stringToDouble(vec[transJ_PColumnConst]);
				double j_q=stringToDouble(vec[transJ_QColumnConst]);
				int i_tap=stringToInt(vec[transI_tapColumnConst]);
				int k_tap=stringToInt(vec[transK_tapColumnConst]);
				
				bool iOff=stringToBool(vec[transI_offColumnConst]);
				bool kOff=stringToBool(vec[transK_offColumnConst]);
				bool jOff=stringToBool(vec[transJ_offColumnConst]);

				
				//判断Transformer两端节点是否都在Bus表内，并找到对应的拓扑节点编号，满足则为有用信息
				/*int i_node=0;
				int j_node=0;//拓扑节点编号
				for(vector<Bus>::iterator iter=vecBus.begin();iter!=vecBus.end();++iter)
				{
					if( i_nodename==(*iter).getBusName() )
						i_node=(*iter).getBusCode();
					if( j_nodename==(*iter).getBusName() )
						j_node=(*iter).getBusCode();
				}*/				
				
				Transformer trans=createTransformer( code, type, i_vol, k_vol, j_vol, i_s, k_s, j_s,
				itap_h, itap_l, itap_e, itap_c, itap_v, ktap_h, ktap_l, ktap_e, ktap_c, ktap_v, jtap_v,
				ri, xi, rk, xk, rj, xj, i_node, k_node, j_node, i_p, i_q, k_p, k_q, j_p, j_q,
				i_tap, k_tap , iOff, kOff, jOff);
				/*size_t t=0;
				for(;t<vecTrans.size();++t)
				{
					if(vecTrans[t]==trans)
					{
						str.clear();
						getline(input,str);
						break;
					}
				}
				if(t<vecTrans.size())continue;*/
				vecTrans.push_back(trans);
				
				str.clear();
				getline(input,str);
			}
		}
		if(str=="</Transformer::nx>")
			break;
	}
}

Load createLoad(int volt,int eq,string node,double p,double q,bool off)//创建新节点
{
	Load load;
	load.setLoadVolt(volt);
	load.setLoadEq(eq);
	load.setLoadNode(node);
	load.setLoadP(p);
	load.setLoadQ(q);
	load.setLoadOff(off);
	return load;
}

void getLoadData(ifstream& input,vector<Load>& vecLoad)
{//读取所有节点或其他信息函数
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Load::nx type=全数>")
		{
		
			str.clear();
			getline(input,str);
			vector<string> vecLoadHeader=split(str);
			
			int loadVoltColumn(0);//识别表头
			int loadEqColumn(0);
			int loadNodeColumn(0);
			int loadPColumn(0);
			int loadQColumn(0);
			int loadOffColumn(0);
	
			for(size_t t=0;t<vecLoadHeader.size();++t)
			{
				if(vecLoadHeader[t]=="volt")
				{
					loadVoltColumn=t;
				}
				else if(vecLoadHeader[t]=="Eq")
				{
					loadEqColumn=t;
				}
				else if(vecLoadHeader[t]=="node")
				{
					loadNodeColumn=t;
				}
				else if(vecLoadHeader[t]=="P")
				{
					loadPColumn=t;
				}
				else if(vecLoadHeader[t]=="Q")
				{
					loadQColumn=t;
				}
				else if(vecLoadHeader[t]=="off")
				{
					loadOffColumn=t;
				}
		
				else
					continue;
			}
			const int loadVoltColumnConst=loadVoltColumn;
			const int loadEqColumnConst=loadEqColumn;
			const int loadNodeColumnConst=loadNodeColumn;
			const int loadPColumnConst=loadPColumn;
			const int loadQColumnConst=loadQColumn;
			const int loadOffColumnConst=loadOffColumn;
			
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Load::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据,对数所进行转换
				int volt=stringToInt(vec[loadVoltColumnConst]);
				int eq=stringToInt(vec[loadEqColumnConst]);
				string node=vec[loadNodeColumnConst];
				double p=stringToDouble(vec[loadPColumnConst]);
				double q=stringToDouble(vec[loadQColumnConst]);
				bool off=stringToBool(vec[loadOffColumnConst]);
				Load load=createLoad(volt,eq,node,p,q,off);
				/*size_t t=0;
				for(;t<vecLoad.size();++t)
				{
					if(vecLoad[t]==load)
					{
						str.clear();
						getline(input,str);
						break;
					}
				}
				if(t<vecLoad.size())continue;*/
				vecLoad.push_back(load);
				
				str.clear();
				getline(input,str);
			}
		}
		if(str=="</Load::nx>")
			break;
	}
}

void getData(ifstream& input,vector<Bus>& vecBus,vector<ACline>& vecACLine,
				vector<TopoNode>& vecTopoNode,vector<Unit>& vecUnit,
				vector<Transformer>& vecTransformer,vector<Load>& vecLoad)
{//调用其他get函数，一次性读取
//有必要了解input的getline是怎么工作的。
//使用过一次，然后再次使用是有影响的
//所有在使用输入流时应该注意顺序，否则会导致无法跳出
	getBusData(input,vecBus);
	getAClineData(input,vecACLine);	
	getUnit(input,vecUnit);
	getTransData(input,vecTransformer);
	//load函数位置
	getLoadData(input,vecLoad);
	getTopoNode(input,vecTopoNode);	
}



//其他函数
int getNumberOfBusOnline(vector<Bus>& vecBus)
{
	int Num(0);
	for(size_t i=0;i<vecBus.size();++i)
	{
		if(!vecBus[i].getBusOff())
			Num++;
	}
	return Num;
}

vector<ACline> getAClineOnline(vector<ACline>& vecACline)
{
	vector<ACline> aclineOnline;
	for(size_t i=0;i<vecACline.size();++i)
	{
		if(!vecACline[i].getAClineI_off() && !vecACline[i].getAClineJ_off())
			aclineOnline.push_back(vecACline[i]);			
	}
	return aclineOnline;
}

int getNumberOfUnitOnline(vector<Unit>& vecUnit)
{
	int Num(0);
	for(size_t i=0;i<vecUnit.size();++i)
	{
		if(!vecUnit[i].getUnitOff())
		{
			Num++;
		}
	}
	return Num;
}

vector<string> busNameInAcline(vector<ACline>& vecACline)
{
	vector<string> vecString;
	for(size_t i=0;i<vecACline.size();++i)
	{
		string iNodeName,jNodeName;
		iNodeName=vecACline[i].getAClineI_node();
		jNodeName=vecACline[i].getAClineJ_node();
		bool iExist=false,jExist=false;
		for(size_t j=0;j<vecString.size();++j)
		{
			if(vecString[j]==iNodeName)
				iExist=true;
			else if(vecString[j]==jNodeName)
				jExist=true;
			if(iExist && jExist)
				break;
		}
		if(!iExist)vecString.push_back(iNodeName);
		if(!jExist)vecString.push_back(jNodeName);
	}
	return vecString;
}

vector<string> busNameInTransformer(vector<Transformer>& vecTransformer)
{
	vector<string> vecString;
	for(size_t i=0;i<vecTransformer.size();++i)
	{
		string iNodeName,kNodeName,jNodeName;
		iNodeName=vecTransformer[i].getTransI_node();
		kNodeName=vecTransformer[i].getTransK_node();
		jNodeName=vecTransformer[i].getTransJ_node();
		bool iExist=false,kExist=false,jExist=false;
		for(size_t j=0;j<vecString.size();++j)
		{
			if(vecString[j]==iNodeName)
				iExist=true;
			else if(vecString[j]==kNodeName)
				jExist=true;
			else if(vecString[j]==jNodeName)
				kExist=true;
			if(iExist && kExist && jExist)
				break;
		}
		if(!iExist && iNodeName!="0")vecString.push_back(iNodeName);
		if(!kExist && kNodeName!="0")vecString.push_back(kNodeName);
		if(!jExist && jNodeName!="0")vecString.push_back(jNodeName);
	}
	return vecString;
}

vector<Branch> totalBranch(vector<ACline>& vecACline,vector<Transformer>& vecTrans)
{//从ACline和Transformer中获取支路信息，注释部分是重复性校验
	vector<Branch> vecBranch;
	for(size_t i=0;i<vecACline.size();++i)
	{
		if(!vecACline[i].getAClineI_off()  && !vecACline[i].getAClineJ_off())
		{//如果两端都未断开
			Branch branch(vecACline[i].getAClineI_node(),vecACline[i].getAClineJ_node(),
					-1,vecACline[i].getAClineR(),vecACline[i].getAClineX(),100);
			// size_t k=0;
			// for(;k<vecBranch.size();++k)
			// {
				// if(vecBranch[k]==branch)
					// break;
			// }
			// if(k<vecBranch.size())
				// continue;
			vecBranch.push_back(branch);
		}
	}
	
	// const int startPos=vecBranch.size();
	//ACline中的支路和Transformer中的支路是不可能重复的，因为ACline中的
	//支路应该都属于同一电压等级
	for(size_t i=0;i<vecTrans.size();++i)
	{
		if(!vecTrans[i].getTransI_off() && !vecTrans[i].getTransK_off()
			&& vecTrans[i].getTransI_node()!="0" && vecTrans[i].getTransK_node()!="0")
		{//如果两端都未断开
			Branch branch(vecTrans[i].getTransI_node(),vecTrans[i].getTransK_node(),
					i,0,0,100);
			// size_t k=startPos;
			// for(;k<vecBranch.size();++k)
			// {//其实没必要从头开始判断，因为ACline的线路中都不含变压器
				// if(vecBranch[k]==branch)//校验存在性
					// break;
			// }
			// if(k<vecBranch.size())
				// continue;
			vecBranch.push_back(branch);
		}
		
		if(!vecTrans[i].getTransK_off() && !vecTrans[i].getTransJ_off()
			&& vecTrans[i].getTransK_node()!="0" && vecTrans[i].getTransJ_node()!="0")
		{
			Branch branch(vecTrans[i].getTransK_node(),vecTrans[i].getTransJ_node(),
					i,0,0,100);
			// size_t k=startPos;
			// for(;k<vecBranch.size();++k)
			// {//其实没必要从头开始判断，因为ACline的线路中都不含变压器
				// if(vecBranch[k]==branch)
					// break;
			// }
			// if(k<vecBranch.size())
				// continue;
			vecBranch.push_back(branch);
		}
		
		if(vecTrans[i].getTransK_node()=="0" && !vecTrans[i].getTransI_off() && !vecTrans[i].getTransJ_off()
			&& vecTrans[i].getTransI_node()!="0" && vecTrans[i].getTransJ_node()!="0")
		{
			Branch branch(vecTrans[i].getTransI_node(),vecTrans[i].getTransJ_node(),
					i,0,0,100);
			// size_t k=startPos;
			// for(;k<vecBranch.size();++k)
			// {//其实没必要从头开始判断，因为ACline的线路中都不含变压器
				// if(vecBranch[k]==branch)
					// break;
			// }
			// if(k<vecBranch.size())
				// continue;
			vecBranch.push_back(branch);
		}
	}
	return vecBranch;
}
vector<string> busNameInBranchList(vector<Branch>& vecBranch)
{//获取支路中的节点总数
	vector<string> vecString;
	for(size_t i=0;i<vecBranch.size();++i)
	{
		string busNameI,busNameJ;
		busNameI=vecBranch[i].getStartBus();
		busNameJ=vecBranch[i].getEndBus();
		bool busNameIFlag=false,busNameJFlag=false;
		
		for(size_t j=0;j<vecString.size();++j)
		{
			if(vecString[j]==busNameI)
				busNameIFlag=true;
			else if(vecString[j]==busNameJ)
				busNameJFlag=true;
			if(busNameIFlag && busNameJFlag)
				break;
		}
		if(!busNameIFlag)vecString.push_back(busNameI);
		if(!busNameJFlag)vecString.push_back(busNameJ);
	}
	return vecString;
}
