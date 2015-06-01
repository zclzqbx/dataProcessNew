#ifndef SHARE_FUNCTION
#define SHARE_FUNCTION

#include <vector>
#include <fstream>
#include "bus.h"
#include "acline.h"
#include "toponode.h"
#include "fstring.h"
#include "unit.h"

using namespace std;

//类型创建
Bus createBus(int ,string ,int ,double ,double ,bool ,double ,double);
ACline createACline(int,string,int,double,double,double,string,string,
				double,double,double,double,double,string,bool,bool);
TopoNode createTopoNode(string ,double ,double ,double);
Unit createUnit(bool,double,double,string,double,double,
				double,double,bool,double,double,double,double,int);		
//数据获取			
void getBusData(ifstream& ,vector<Bus>&);
void getAClineData(ifstream& ,vector<ACline>&);
void getTopoNode(ifstream& ,vector<TopoNode>&);
void getUnit(ifstream& ,vector<Unit>&);

//获取全部数据
void getData(ifstream&  ,vector<Bus>& ,vector<ACline>& ,vector<TopoNode>& ,
				vector<Unit>& );


#endif //SHARE_FUNCTION