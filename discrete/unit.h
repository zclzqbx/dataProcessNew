#ifndef UNIT
#define UNIT

#include <iostream>
#include <string>

using namespace std;

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

#endif //UNIT