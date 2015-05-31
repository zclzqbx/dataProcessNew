#ifndef ACLINE
#define ACLINE

#include <iostream>
#include <string>

using namespace std;

class ACline{//支路类
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

#endif //ACLINE