#ifndef SHARE_FUNCTION
#define SHARE_FUNCTION

#include <vector>
#include <fstream>
#include "bus.h"
#include "acline.h"
#include "toponode.h"
#include "fstring.h"

using namespace std;

Bus createBus(int ,string ,int ,double ,double ,bool ,double ,double);
ACline createACline(int,string,int,double,double,double,string,string,
				double,double,double,double,double,string,bool,bool);
TopoNode createTopoNode(string ,double ,double ,double);
				
void getBusData(ifstream& ,vector<Bus>&);
void getAClineData(ifstream& ,vector<ACline>&);
void getTopoNode(ifstream& ,vector<TopoNode>&);


void getData(ifstream&  ,vector<Bus>& ,vector<ACline>& ,vector<TopoNode>& );

#endif //SHARE_FUNCTION