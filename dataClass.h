#ifndef DATACLASS
#define DATACLASS

#include <iostream>
#include <string>

using namespace std;

//节点类
class Bus{
public:	
	void setBusCode(int code){busCode=code;}
	void setBusName(string name){busName=name;}
	void setBusVolt(int volt){busVolt=volt;}
	void setBusV(double v){busV=v;}
	void setBusAng(double ang){busAng=ang;}
	void setBusOff(bool off){busOff=off;}
	void setBusV_max(double V_max){busV_max=V_max;}
	void setBusV_min(double V_min){busV_min=V_min;}
	
	int getBusCode()const{return busCode;}//后面const的必要性
	string getBusName()const{return busName;}
	int getBusVolt()const{return busVolt;}
	double getBusV()const{return busV;}
	double getBusAng()const{return busAng;}
	bool getBusOff()const{return busOff;}
	double getBusV_max()const{return busV_max;}
	double getBusV_min()const{return busV_min;}
	
	// bool operator==(const Bus&);
	friend bool operator==(const Bus&,const Bus&);
	friend ostream& operator<<(ostream& ,Bus&);//输出所有信息
	
	bool printBusOnline(ostream& );//打印所有在线机组
	

private:
	int busCode;//节点编号
	string busName;//节点名称
	int busVolt;//节点电压等级
	double busV;//节点电压
	double busAng;//节点相角
	bool busOff;//节点停运状态
	double busV_max;//节点最大电压
	double busV_min;//节点最小电压
	
};

//支路类
class ACline{
public:
	void setAClineCode(int code){AClineCode=code;}
	void setAClineName(string name){AClineName=name;}
	void setAClineVolt(int volt){AClineVolt=volt;}
    void setAClineR(double r){AClineR=r;}
	void setAClineX(double x){AClineX=x;}
	void setAClineB(double b){AClineB=b;}
	void setAClineI_node(string i_nodeName){AClineI_nodeName=i_nodeName;}
	void setAClineJ_node(string j_nodeName){AClineJ_nodeName=j_nodeName;}
	void setAClineI_P(double i_p){AClineI_P=i_p;}
	void setAClineI_Q(double i_q){AClineI_Q=i_q;}
	void setAClineJ_P(double j_p){AClineJ_P=j_p;}
	void setAClineJ_Q(double j_q){AClineJ_Q=j_q;}
	void setAClineImax(double imax){AClineImax=imax;}
	void setAClineArea(string area){AClineArea=area;}
	void setAClineI_off(bool iOff){AClineI_off=iOff;}
	void setAClineJ_off(bool jOff){AClineJ_off=jOff;}

	int getAClineCode()const{return AClineCode;}//修改线路编号
	string getAClineName()const{return AClineName;}//修改线路名称
	int getAClineVolt()const{return AClineVolt;}//修改线路电压等级
	double getAClineR()const{return AClineR;}//修改线路电阻
	double getAClineX()const{return AClineX;}//修改线路电抗
	double getAClineB()const{return AClineB;}//修改线路单端电纳
	string getAClineI_node()const{return AClineI_nodeName;}//修改线路I端所在拓扑节点
	string getAClineJ_node()const{return AClineJ_nodeName;}//修改线路J端所在拓扑节点
	double getAClineI_P()const{return AClineI_P;}//修改I端有功
	double getAClineI_Q()const{return AClineI_Q;}//修改I端无功
	double getAClineJ_P()const{return AClineJ_P;}//修改J端有功
	double getAClineJ_Q()const{return AClineJ_Q;}//修改J端无功
	double getAClineImax()const{return AClineImax;}//修改线路电流限值
	string getAClineArea()const{return AClineArea;}//修改线路区域
	bool getAClineI_off()const{return AClineI_off;}
	bool getAClineJ_off()const{return AClineJ_off;}

	// bool operator==(const Bus&);
	friend bool operator==(const ACline&,const ACline&);
	friend ostream& operator<<(ostream& ,ACline&);
	bool printAClineOnline(ostream& );
	bool printAClineOfflineBus(ostream& );

private:
	int AClineCode;//线路编号
	string AClineName;//线路名称
	int AClineVolt;//电压等级
	double AClineR;//线路电阻
	double AClineX;//线路电抗
	double AClineB;//线路单端电纳
	string AClineI_nodeName;//线路I端所在拓扑节点编号
	string AClineJ_nodeName;//线路J端所在拓扑节点编号
	double AClineI_P;//I端有功
	double AClineI_Q;//I端无功
	double AClineJ_P;//J端有功
	double AClineJ_Q;//J端无功
	double AClineImax;//线路电流限值
	string AClineArea;//线路区域
	bool AClineI_off;//I端断开标志
	bool AClineJ_off;//J端断开标志
};


//拓扑节点
class TopoNode{
public:
	void setTopoNodeName(string name){topoNodeName=name;}
	void setTopoNodeV(double V){topoNodeV=V;}
	void setTopoNodeAng(double ang){topoNodeAng=ang;}
	void setTopoNodeVbase(double vBase){topoNodeVbase=vBase;}
	
	string getTopoNodeName()const{return topoNodeName;}
	double getTopoNodeV()const{return topoNodeV;}
	double getTopoNodeAng()const{return topoNodeAng;}
	double getTopoNodeVbase()const{return topoNodeVbase;}
	
	bool operator==(const TopoNode&);//жиди
	friend ostream& operator<<(ostream& ,TopoNode&);
	
private:
	string topoNodeName;
	double topoNodeV;
	double topoNodeAng;
	double topoNodeVbase;

};

//机组
class Unit{
public:
	void setUnitEq(bool eq){unitEq=eq;}
	void setUnitV_Rate(double v_Rate){unitV_Rate=v_Rate;}
	void setUnitP_Rate(double p_Rate){unitP_Rate=p_Rate;}
	void setUnitTopoNode(string topoNode){unitTopoNode=topoNode;}
	void setUnitP(double p){unitP=p;}
	void setUnitQ(double q){unitQ=q;}
	void setUnitUe(double ue){unitUe=ue;}
	void setUnitAng(double ang){unitAng=ang;}
	void setUnitOff(bool off){unitOff=off;}
	void setUnitP_H(double p_H){unitP_H=p_H;}
	void setUnitP_L(double p_L){unitP_L=p_L;}
	void setUnitQ_H(double q_H){unitQ_H=q_H;}
	void setUnitQ_L(double q_L){unitQ_L=q_L;}
	void setUnitVolt(int volt){unitVolt=volt;}
	
	bool getUnitEq()const{return unitEq;}
	double getUnitV_Rate()const{return unitV_Rate;}
	double getUnitP_Rate()const{return unitP_Rate;}
	string getUnitTopoNode()const{return unitTopoNode;}
	double getUnitP()const{return unitP;}
	double getUnitQ()const{return unitQ;}
	double getUnitUe()const{return unitUe;}
	double getUnitAng()const{return unitAng;}
	bool getUnitOff()const{return unitOff;}
	double getUnitP_H()const{return unitP_H;}
	double getUnitP_L()const{return unitP_L;}
	double getUnitQ_H()const{return unitQ_H;}
	double getUnitQ_L()const{return unitQ_L;}
	int getUnitVolt()const{return unitVolt;}
	
	bool operator==(const Unit&);//жиди
	friend ostream& operator<<(ostream& ,Unit&);
	
private:
	bool unitEq;//等值发电机标志
	double unitV_Rate;//额定电压
	double unitP_Rate;//额定功率
	string unitTopoNode;//所在拓扑节点
	double unitP;//有功出力
	double unitQ;//无功出力
	double unitUe;//机端电压
	double unitAng;//机端电压相角
	bool unitOff;//停运标志
	double unitP_H;//有功上限
	double unitP_L;//有功下限
	double unitQ_H;//无功上限
	double unitQ_L;//无功下限
	int unitVolt;//电压等级
};

//变压器类
class Transformer{
public:
	//设置变压器参数值
	void setTransCode(int code){transCode=code;}
	void setTransType(int type){transType=type;}
	void setTransI_Vol(int vol){transI_Vol=vol;}
	void setTransK_Vol(int vol){transK_Vol=vol;}
	void setTransJ_Vol(int vol){transJ_Vol=vol;}
	void setTransI_S(int s){transI_S=s;}
	void setTransK_S(int s){transK_S=s;}
	void setTransJ_S(int s){transJ_S=s;}
	void setTransItap_H(int tap){transItap_H=tap;}
	void setTransItap_L(int tap){transItap_L=tap;}
	void setTransItap_E(int tap){transItap_E=tap;}
	void setTransItap_C(double tap){transItap_C=tap;}
	void setTransItap_V(int tap){transItap_V=tap;}
	void setTransKtap_H(int tap){transKtap_H=tap;}
	void setTransKtap_L(int tap){transKtap_L=tap;}
	void setTransKtap_E(int tap){transKtap_E=tap;}
	void setTransKtap_C(double tap){transKtap_C=tap;}
	void setTransKtap_V(int tap){transKtap_V=tap;}
	void setTransJtap_V(int tap){transJtap_V=tap;}
	void setTransRi(double r){transRi=r;}
	void setTransXi(double r){transXi=r;}
	void setTransRk(double r){transRk=r;}
	void setTransXk(double r){transXk=r;}
	void setTransRj(double r){transRj=r;}
	void setTransXj(double r){transXj=r;}
	void setTransI_node(int node){transI_node=node;}
	void setTransK_node(int node){transK_node=node;}
	void setTransJ_node(int node){transJ_node=node;}
	void setTransI_P(double p){transI_P=p;}
	void setTransI_Q(double p){transI_Q=p;}
	void setTransK_P(double p){transK_P=p;}
	void setTransK_Q(double p){transK_Q=p;}
	void setTransJ_P(double p){transJ_P=p;}
	void setTransJ_Q(double p){transJ_Q=p;}
	void setTransI_tap(int tap){transI_tap=tap;}
	void setTransK_tap(int tap){transK_tap=tap;}
	
	//获取变压器参数值
	int getTransCode()const{return transCode;}
	int getTransType()const{return transType;}
	int getTransI_Vol()const{return transI_Vol;}
	int getTransK_Vol()const{return transK_Vol;}
	int getTransJ_Vol()const{return transJ_Vol;}
	int getTransI_S()const{return transI_S;}
	int getTransK_S()const{return transK_S;}
	int getTransJ_S()const{return transJ_S;}
	int getTransItap_H()const{return transItap_H;}
	int getTransItap_L()const{return transItap_L;}
	int getTransItap_E()const{return transItap_E;}
	double getTransItap_C()const{return transItap_C;}
	int getTransItap_V()const{return transItap_V;}
	int getTransKtap_H()const{return transKtap_H;}
	int getTransKtap_L()const{return transKtap_L;}
	int getTransKtap_E()const{return transKtap_E;}
	double getTransKtap_C()const{return transKtap_C;}
	int getTransKtap_V()const{return transKtap_V;}
	int getTransJtap_V()const{return transJtap_V;}
	double getTransRi()const{return transRi;}
	double getTransXi()const{return transXi;}
	double getTransRk()const{return transRk;}
	double getTransXk()const{return transXk;}
	double getTransRj()const{return transRj;}
	double getTransXj()const{return transXj;}
	int getTransI_node()const{return transI_node;}
	int getTransK_node()const{return transK_node;}
	int getTransJ_node()const{return transJ_node;}
	double getTransI_P()const{return transI_P;}
	double getTransI_Q()const{return transI_Q;}
	double getTransK_P()const{return transK_P;}
	double getTransK_Q()const{return transK_Q;}
	double getTransJ_P()const{return transJ_P;}
	double getTransJ_Q()const{return transJ_Q;}
	int getTransI_tap()const{return transI_tap;}
	int getTransK_tap()const{return transK_tap;}

private:
	int transCode;//变压器编号
	int transType;//绕组类型
	int transI_Vol;//高压端电压等级
	int transK_Vol;//中压端电压等级
	int transJ_Vol;//低压端电压等级
	int transI_S;//高压端额定容量
	int transK_S;//中压端额定容量
	int transJ_S;//低压端额定容量
	int transItap_H;//高压端分接头最高档位
	int transItap_L;//高压端分接头最低档位
	int transItap_E;//高压端分接头额定档位
	double transItap_C;//高压端分接头级差
	int transItap_V;//高压端额定电压
	int transKtap_H;//中压端分接头最高档位
	int transKtap_L;//中压端分接头最低档位
	int transKtap_E;//中压端分接头额定档位
	double transKtap_C;//中压端分接头级差
	int transKtap_V;//中压端额定电压
	int transJtap_V;//低压端额定电压
	double transRi;//高压绕组电阻
	double transXi;//高压绕组电抗
	double transRk;//中压绕组电阻
	double transXk;//中压绕组电抗
	double transRj;//低压绕组电阻
	double transXj;//低压绕组电抗
	int transI_node;//高压端所在拓扑节点
	int transK_node;//中压端所在拓扑节点
	int transJ_node;//低压端所在拓扑节点
	double transI_P;//高压端有功功率
	double transI_Q;//高压端无功功率
	double transK_P;//中压端有功功率
	double transK_Q;//中压端无功功率
	double transJ_P;//低压端有功功率
	double transJ_Q;//低压端无功功率
	int transI_tap;//高压侧分接头位置
	int transK_tap;//中压侧分接头位置
	
// bool operator==(const Bus&);
friend bool operator==(const Transformer&,const Transformer&);
friend ostream& operator<<(ostream& ,Transformer&);	
};

#endif //DATACLASS