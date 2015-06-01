#include "unit.h"

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
