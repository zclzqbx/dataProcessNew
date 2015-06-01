#ifndef BUS
#define BUS

#include <iostream>
#include <string>

using namespace std;

class Bus{//节点类

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
	
	bool printBusOnline(ostream& );//打印所有非停运机组

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

#endif //BUS
