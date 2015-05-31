#ifndef BUS
#define BUS

#include <iostream>
#include <string>

using namespace std;

class Bus{//�ڵ���

public:	
	void setBusCode(int code){busCode=code;}
	void setBusName(string name){busName=name;}
	void setBusVolt(int volt){busVolt=volt;}
	void setBusV(double v){busV=v;}
	void setBusAng(double ang){busAng=ang;}
	void setBusOff(bool off){busOff=off;}
	void setBusV_max(double V_max){busV_max=V_max;}
	void setBusV_min(double V_min){busV_min=V_min;}
	
	int getBusCode()const{return busCode;}//����const�ı�Ҫ��
	string getBusName()const{return busName;}
	int getBusVolt()const{return busVolt;}
	double getBusV()const{return busV;}
	double getBusAng()const{return busAng;}
	bool getBusOff()const{return busOff;}
	double getBusV_max()const{return busV_max;}
	double getBusV_min()const{return busV_min;}
	
	// bool operator==(const Bus&);
	friend bool operator==(const Bus&,const Bus&);
	friend ostream& operator<<(ostream& ,Bus&);//���������Ϣ
	
	bool printBusOnline(ostream& );//��ӡ���з�ͣ�˻���

private:
	int busCode;//�ڵ���
	string busName;//�ڵ�����
	int busVolt;//�ڵ��ѹ�ȼ�
	double busV;//�ڵ��ѹ
	double busAng;//�ڵ����
	bool busOff;//�ڵ�ͣ��״̬
	double busV_max;//�ڵ�����ѹ
	double busV_min;//�ڵ���С��ѹ
	
};

#endif //BUS
