#ifndef SHARE_FUNCTION
#define SHARE_FUNCTION

#include <vector>
#include <fstream>
#include "dataClass.h"

using namespace std;

//类型创建
Bus createBus(int ,string ,int ,double ,double ,bool ,double ,double);
ACline createACline(int,string,int,double,double,double,string,string,
				double,double,double,double,double,string,bool,bool);
TopoNode createTopoNode(string ,double ,double ,double);
Unit createUnit(bool,double,double,string,double,double,
				double,double,bool,double,double,double,double,int);				
Transformer createTransformer(int code,int type,int i_Vol,int k_Vol,
							int j_Vol,int i_S,int k_S,int j_S,int itap_H,
							int itap_L,int itap_E,double itap_C,int itap_V,
							int ktap_H,int ktap_L,int ktap_E,double ktap_C,
							int ktap_V,int jtap_V,double ri,double xi,double rk,
							double xk,double rj,double xj,string i_node,string k_node,
							string j_node,double i_p,double i_q,double k_p,double k_q,
							double j_p,double j_q,int i_tap,int k_tap,bool iOff,bool kOff,bool jOff);
//数据获取			
void getBusData(ifstream& ,vector<Bus>&);
void getAClineData(ifstream& ,vector<ACline>&);
void getTopoNode(ifstream& ,vector<TopoNode>&);
void getUnit(ifstream& ,vector<Unit>&);
void getTransData(ifstream& input,vector<Transformer>& vecTrans);

//获取全部数据
void getData(ifstream&  ,vector<Bus>& ,vector<ACline>& ,vector<TopoNode>& ,
				vector<Unit>& ,vector<Transformer>& );

// 其他函数
//从Bus中获取在线机组的总量
int getNumberOfBusOnline(vector<Bus>& );
//从ACline中获取在线的支路
vector<ACline> getAClineOnline(vector<ACline>& );
//获取在线的机组
int getNumberOfUnitOnline(vector<Unit>& );
//ACline中的节点名称
vector<string> busNameInAcline(vector<ACline>& );
//Transformer中的节点名称
vector<string> busNameInTransformer(vector<Transformer>& );
//Branch中的节点名称
vector<string> busNameInBranchList(vector<Branch>& );
//ACline和Transformer中总的支路数
vector<Branch> totalBranch(vector<ACline>& ,vector<Transformer>& );


#endif //SHARE_FUNCTION