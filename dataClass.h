#ifndef DATACLASS
#define DATACLASS

#include <iostream>
#include <string>

using namespace std;

//�ڵ���
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
	
	bool printBusOnline(ostream& );//��ӡ�������߻���
	

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

//֧·��
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


//���˽ڵ�
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
	
	bool operator==(const TopoNode&);//�اڧէ�
	friend ostream& operator<<(ostream& ,TopoNode&);
	
private:
	string topoNodeName;
	double topoNodeV;
	double topoNodeAng;
	double topoNodeVbase;

};

//����
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
	
	bool operator==(const Unit&);//�اڧէ�
	friend ostream& operator<<(ostream& ,Unit&);
	
private:
	bool unitEq;//��ֵ�������־
	double unitV_Rate;//���ѹ
	double unitP_Rate;//�����
	string unitTopoNode;//�������˽ڵ�
	double unitP;//�й�����
	double unitQ;//�޹�����
	double unitUe;//���˵�ѹ
	double unitAng;//���˵�ѹ���
	bool unitOff;//ͣ�˱�־
	double unitP_H;//�й�����
	double unitP_L;//�й�����
	double unitQ_H;//�޹�����
	double unitQ_L;//�޹�����
	int unitVolt;//��ѹ�ȼ�
};

//��ѹ����
class Transformer{
public:
	//���ñ�ѹ������ֵ
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
	
	void setTransI_node(string node){transI_node=node;}
	void setTransK_node(string node){transK_node=node;}
	void setTransJ_node(string node){transJ_node=node;}
	
	void setTransI_P(double p){transI_P=p;}
	void setTransI_Q(double p){transI_Q=p;}
	void setTransK_P(double p){transK_P=p;}
	void setTransK_Q(double p){transK_Q=p;}
	void setTransJ_P(double p){transJ_P=p;}
	void setTransJ_Q(double p){transJ_Q=p;}
	void setTransI_tap(int tap){transI_tap=tap;}
	void setTransK_tap(int tap){transK_tap=tap;}
	void setTransI_off(bool iOff){transI_off=iOff;}
	void setTransK_off(bool kOff){transK_off=kOff;}
	void setTransJ_off(bool jOff){transJ_off=jOff;}
	
	//��ȡ��ѹ������ֵ
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
	string getTransI_node()const{return transI_node;}
	string getTransK_node()const{return transK_node;}
	string getTransJ_node()const{return transJ_node;}
	double getTransI_P()const{return transI_P;}
	double getTransI_Q()const{return transI_Q;}
	double getTransK_P()const{return transK_P;}
	double getTransK_Q()const{return transK_Q;}
	double getTransJ_P()const{return transJ_P;}
	double getTransJ_Q()const{return transJ_Q;}
	int getTransI_tap()const{return transI_tap;}
	int getTransK_tap()const{return transK_tap;}
	bool getTransI_off()const{return transI_off;}
	bool getTransK_off()const{return transK_off;}
	bool getTransJ_off()const{return transJ_off;}

private:
	int transCode;//��ѹ�����
	int transType;//��������
	int transI_Vol;//��ѹ�˵�ѹ�ȼ�
	int transK_Vol;//��ѹ�˵�ѹ�ȼ�
	int transJ_Vol;//��ѹ�˵�ѹ�ȼ�
	int transI_S;//��ѹ�˶����
	int transK_S;//��ѹ�˶����
	int transJ_S;//��ѹ�˶����
	int transItap_H;//��ѹ�˷ֽ�ͷ��ߵ�λ
	int transItap_L;//��ѹ�˷ֽ�ͷ��͵�λ
	int transItap_E;//��ѹ�˷ֽ�ͷ���λ
	double transItap_C;//��ѹ�˷ֽ�ͷ����
	int transItap_V;//��ѹ�˶��ѹ
	int transKtap_H;//��ѹ�˷ֽ�ͷ��ߵ�λ
	int transKtap_L;//��ѹ�˷ֽ�ͷ��͵�λ
	int transKtap_E;//��ѹ�˷ֽ�ͷ���λ
	double transKtap_C;//��ѹ�˷ֽ�ͷ����
	int transKtap_V;//��ѹ�˶��ѹ
	int transJtap_V;//��ѹ�˶��ѹ
	double transRi;//��ѹ�������
	double transXi;//��ѹ����翹
	double transRk;//��ѹ�������
	double transXk;//��ѹ����翹
	double transRj;//��ѹ�������
	double transXj;//��ѹ����翹
	string transI_node;//��ѹ���������˽ڵ�
	string transK_node;//��ѹ���������˽ڵ�
	string transJ_node;//��ѹ���������˽ڵ�
	double transI_P;//��ѹ���й�����
	double transI_Q;//��ѹ���޹�����
	double transK_P;//��ѹ���й�����
	double transK_Q;//��ѹ���޹�����
	double transJ_P;//��ѹ���й�����
	double transJ_Q;//��ѹ���޹�����
	int transI_tap;//��ѹ��ֽ�ͷλ��
	int transK_tap;//��ѹ��ֽ�ͷλ��
	bool transI_off;//�Ͽ���־
	bool transK_off;
	bool transJ_off;
	
// bool operator==(const Bus&);
	friend bool operator==(const Transformer&,const Transformer&);
	friend ostream& operator<<(ostream& ,Transformer&);	
};


//֧·
class Branch{
public:
	Branch(string ,string ,int ,double ,double ,double );
	void setStartBus(string bus){startBus=bus;}
	void setEndBus(string bus){endBus=bus;}
	void setTransFlag(int flag){transFlag=flag;}
	void setResistance(double R){resistance=R;}
	void setReactance(double X){reactance=X;}
	void setPowerLimit(double limit){powerLimit=limit;}
	
	string getStartBus()const{return startBus;}
	string getEndBus()const{return endBus;}
	int getTransFlag()const{return transFlag;}
	double getResistance()const{return resistance;}
	double getReactance()const{return reactance;}
	double getPowerLimit()const{return powerLimit;}
	
	bool operator==(const Branch&);
	friend ostream& operator<<(ostream& ,Branch&);
	void printUnitStyle(ostream& );
private:
	string startBus;//���
	string endBus;//�յ�
	int transFlag;//��ѹ�����
	double resistance;//����
	double reactance;//�翹
	double powerLimit;//��������
};

//������
class Load{
public:
//���ò���
	void setLoadVolt(int volt){loadVolt=volt;}
	void setLoadEq(int eq){loadEq=eq;}
	void setLoadNode(string node){loadNode=node;}
	void setLoadP(double p){loadP=p;}
	void setLoadQ(double q){loadQ=q;}
	void setLoadOff(bool off){loadOff=off;}
	
//��ȡ����
	int getLoadVolt()const{return loadVolt;}
	int getLoadEq()const{return loadEq;}
	string getLoadNode()const{return loadNode;}
	double getLoadP()const{return loadP;}
	double getLoadQ()const{return loadQ;}
	bool getLoadOff()const{return loadOff;}
	
	// bool operator==(const Bus&);
//friend bool operator==(const Load&,const Load&);
friend ostream& operator<<(ostream& ,Load&);	
	
private:
	int loadVolt;//��ѹ�ȼ�
	int loadEq;//��ֵ���ɱ�־
	string loadNode; //�������˽ڵ�
	double loadP;//�й�����
	double loadQ;//�޹�����
	bool loadOff;//ͣ�˱�־

};

#endif //DATACLASS