#include "unit.h"

bool Unit::operator==(const Unit& unit)
{
	return this->unitTopoNode==unit.getUnitTopoNode();
}

ostream& operator<<(ostream& output,Unit& unit)
{
	output<<"�����ֵ�������־��"<<unit.getUnitEq()<<endl;
	output<<"������ѹ��"<<unit.getUnitV_Rate()<<endl;
	output<<"�������ʣ�"<<unit.getUnitP_Rate()<<endl;
	output<<"�����������˽ڵ㣺"<<unit.getUnitTopoNode()<<endl;
	output<<"�����й�������"<<unit.getUnitP()<<endl;
	output<<"�����޹�������"<<unit.getUnitQ()<<endl;
	output<<"������˵�ѹ��"<<unit.getUnitUe()<<endl;
	output<<"������˵�ѹ��ǣ�"<<unit.getUnitAng()<<endl;
	output<<"����ͣ�˱�־��"<<unit.getUnitOff()<<endl;
	output<<"�����й����ޣ�"<<unit.getUnitP_H()<<endl;
	output<<"�����й����ޣ�"<<unit.getUnitP_L()<<endl;
	output<<"�����޹����ޣ�"<<unit.getUnitQ_H()<<endl;
	output<<"�����޹����ޣ�"<<unit.getUnitQ_L()<<endl;
	output<<"�����ѹ�ȼ���"<<unit.getUnitVolt()<<endl;
	return output;
}
