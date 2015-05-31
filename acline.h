#ifndef ACLINE
#define ACLINE

#include <iostream>
#include <string>

using namespace std;

class ACline{//֧·��
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

	int getAClineCode()const{return AClineCode;}//�޸���·���
	string getAClineName()const{return AClineName;}//�޸���·����
	int getAClineVolt()const{return AClineVolt;}//�޸���·��ѹ�ȼ�
	double getAClineR()const{return AClineR;}//�޸���·����
	double getAClineX()const{return AClineX;}//�޸���·�翹
	double getAClineB()const{return AClineB;}//�޸���·���˵���
	string getAClineI_node()const{return AClineI_nodeName;}//�޸���·I���������˽ڵ�
	string getAClineJ_node()const{return AClineJ_nodeName;}//�޸���·J���������˽ڵ�
	double getAClineI_P()const{return AClineI_P;}//�޸�I���й�
	double getAClineI_Q()const{return AClineI_Q;}//�޸�I���޹�
	double getAClineJ_P()const{return AClineJ_P;}//�޸�J���й�
	double getAClineJ_Q()const{return AClineJ_Q;}//�޸�J���޹�
	double getAClineImax()const{return AClineImax;}//�޸���·������ֵ
	string getAClineArea()const{return AClineArea;}//�޸���·����
	bool getAClineI_off()const{return AClineI_off;}
	bool getAClineJ_off()const{return AClineJ_off;}

	// bool operator==(const Bus&);
	friend bool operator==(const ACline&,const ACline&);
	friend ostream& operator<<(ostream& ,ACline&);
	bool printAClineOnline(ostream& );
	bool printAClineOfflineBus(ostream& );

private:
	int AClineCode;//��·���
	string AClineName;//��·����
	int AClineVolt;//��ѹ�ȼ�
	double AClineR;//��·����
	double AClineX;//��·�翹
	double AClineB;//��·���˵���
	string AClineI_nodeName;//��·I���������˽ڵ���
	string AClineJ_nodeName;//��·J���������˽ڵ���
	double AClineI_P;//I���й�
	double AClineI_Q;//I���޹�
	double AClineJ_P;//J���й�
	double AClineJ_Q;//J���޹�
	double AClineImax;//��·������ֵ
	string AClineArea;//��·����
	bool AClineI_off;//I�˶Ͽ���־
	bool AClineJ_off;//J�˶Ͽ���־
};

#endif //ACLINE