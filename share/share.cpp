#include "share.h"

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

void getData(ifstream& input,vector<Bus>& vecBus,vector<ACline>& vecACLine ,
				vector<TopoNode>& vecTopoNode)
{//调用其他get函数，一次性读取
//有必要了解input的getline是怎么工作的。
//使用过一次，然后再次使用难道没有影响吗？
	getBusData(input,vecBus);
	getAClineData(input,vecACLine);
	getTopoNode(input,vecTopoNode);
}