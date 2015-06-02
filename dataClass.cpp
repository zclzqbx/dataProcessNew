#include "dataClass.h"

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


//TopoNode
bool TopoNode::operator==(const TopoNode& topoNode)
{
	return this->topoNodeName==topoNode.getTopoNodeName();
}

ostream& operator<<(ostream& output,TopoNode& topoNode)
{
	output<<"节点名称："<<topoNode.getTopoNodeName()<<endl;
	output<<"节点电压："<<topoNode.getTopoNodeV()<<endl;
	output<<"节点相角："<<topoNode.getTopoNodeAng()<<endl;
	output<<"节点电压基准："<<topoNode.getTopoNodeVbase()<<endl;
	return output;
}


//Unit
bool Unit::operator==(const Unit& unit)
{
	return this->unitTopoNode==unit.getUnitTopoNode();
}

ostream& operator<<(ostream& output,Unit& unit)
{
	output<<"机组等值发电机标志："<<unit.getUnitEq()<<endl;
	output<<"机组额定电压："<<unit.getUnitV_Rate()<<endl;
	output<<"机组额定功率："<<unit.getUnitP_Rate()<<endl;
	output<<"机组所在拓扑节点："<<unit.getUnitTopoNode()<<endl;
	output<<"机组有功出力："<<unit.getUnitP()<<endl;
	output<<"机组无功出力："<<unit.getUnitQ()<<endl;
	output<<"机组机端电压："<<unit.getUnitUe()<<endl;
	output<<"机组机端电压相角："<<unit.getUnitAng()<<endl;
	output<<"机组停运标志："<<unit.getUnitOff()<<endl;
	output<<"机组有功上限："<<unit.getUnitP_H()<<endl;
	output<<"机组有功下限："<<unit.getUnitP_L()<<endl;
	output<<"机组无功上限："<<unit.getUnitQ_H()<<endl;
	output<<"机组无功下限："<<unit.getUnitQ_L()<<endl;
	output<<"机组电压等级："<<unit.getUnitVolt()<<endl;
	return output;
}


//ACline
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


//Transformer
bool operator==(const Transformer& transformer1,const Transformer& transformer2)//判断是否相等
{
	return (transformer1.getTransCode()==transformer2.getTransCode());
}

ostream& operator<<(ostream& output,Transformer& transformer)//输出
{
	output<<"变压器编号:"<<transformer.getTransCode()<<endl;
	output<<"绕组类型:"<<transformer.getTransType()<<endl;
	output<<"高压端电压等级:"<<transformer.getTransI_Vol()<<endl;
	output<<"中压端电压等级:"<<transformer.getTransK_Vol()<<endl;
	output<<"低压端电压等级:"<<transformer.getTransJ_Vol()<<endl;
	output<<"高压端额定容量:"<<transformer.getTransI_S()<<endl;
	output<<"中压端额定容量:"<<transformer.getTransK_S()<<endl;
	output<<"低压端额定容量:"<<transformer.getTransJ_S()<<endl;
	output<<"高压端分接头最高档位:"<<transformer.getTransItap_H()<<endl;
	output<<"高压端分接头最中档位:"<<transformer.getTransItap_L()<<endl;
	output<<"高压端分接头最低档位:"<<transformer.getTransItap_E()<<endl;
	output<<"高压端分接头级差:"<<transformer.getTransItap_C()<<endl;
	output<<"高压端额定电压:"<<transformer.getTransItap_V()<<endl;
	output<<"中压端分接头最高档位:"<<transformer.getTransKtap_H()<<endl;
	output<<"中压端分接头最中档位:"<<transformer.getTransKtap_L()<<endl;
	output<<"中压端分接头最低档位:"<<transformer.getTransKtap_E()<<endl;
	output<<"中压端分接头级差:"<<transformer.getTransKtap_C()<<endl;	
	output<<"中压端额定电压:"<<transformer.getTransKtap_V()<<endl;
	output<<"低压端额定电压:"<<transformer.getTransJtap_V()<<endl;
	output<<"高压绕组电阻:"<<transformer.getTransRi()<<endl;
	output<<"高压绕组电抗:"<<transformer.getTransXi()<<endl;
	output<<"中压绕组电阻:"<<transformer.getTransRk()<<endl;
	output<<"中压绕组电抗:"<<transformer.getTransXk()<<endl;
	output<<"低压绕组电阻:"<<transformer.getTransRj()<<endl;
	output<<"低压绕组电抗:"<<transformer.getTransXj()<<endl;
	output<<"高压端所在拓扑节点:"<<transformer.getTransI_node()<<endl;
	output<<"中压端所在拓扑节点:"<<transformer.getTransK_node()<<endl;
	output<<"低压端所在拓扑节点:"<<transformer.getTransJ_node()<<endl;
	output<<"高压端有功功率:"<<transformer.getTransI_P()<<endl;
	output<<"高压端无功功率:"<<transformer.getTransI_Q()<<endl;
	output<<"中压端有功功率:"<<transformer.getTransK_P()<<endl;
	output<<"中压端无功功率:"<<transformer.getTransK_Q()<<endl;
	output<<"低压端有功功率:"<<transformer.getTransJ_P()<<endl;
	output<<"低压端无功功率:"<<transformer.getTransJ_Q()<<endl;
	output<<"高压侧分接头位置:"<<transformer.getTransI_tap()<<endl;
	output<<"中压侧分接头位置:"<<transformer.getTransK_tap()<<endl;
	
	return output;
}
