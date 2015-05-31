#include "share.h"
#include <fstream>

using namespace std;

ifstream input("nx_20150427_1355.txt",ios::in);
//指明数据所在位置
ofstream output1("busdata.txt",ios::ate);
ofstream output2("aclinedata.txt",ios::ate);
ofstream output3("topnode.txt",ios::ate);
ofstream output4("topnoexist.txt",ios::ate);
// ofstream output5("aclineBreakBus.txt",ios::ate);

int main()
{
	vector<Bus> busList;//存放了所有节点
	vector<ACline> aclineList;//存放了所有ACline
	vector<TopoNode> topoNodeList;
	
	getData(input,busList,aclineList,topoNodeList);
	
	int printNum=0;
	for(size_t i=0;i!=busList.size();++i)
	{
		output1<<busList[i]<<endl;//无差别输出
		// if(busList[i].printBusOnline(output1))//输出在线节点
		// {
			// printNum++;
			// output1<<endl;
		// }
		
	}
	output1<<endl<<"结点总数:"<<printNum<<endl;
	
	printNum=0;
	for(size_t j=0;j!=aclineList.size();++j)
	{
		// output2<<aclineList[j]<<endl;
		if(aclineList[j].printAClineOnline(output2))
		{
			printNum++;
			output2<<endl;
		}
	}
	output2<<endl<<"支路总数:"<<printNum<<endl;
	
	printNum=0;
	for(size_t j=0;j!=topoNodeList.size();++j)
	{
		output3<<topoNodeList[j]<<endl;
	}
	
	vector<Bus> noExistInTopoNodeList;
	for(size_t t=0;t<busList.size();++t)
	{
		size_t k=0;
		for(;k<topoNodeList.size();++k)
		{
			if(busList[t].getBusName()==topoNodeList[k].getTopoNodeName())
				break;
		}
		if(k>=topoNodeList.size())
			noExistInTopoNodeList.push_back(busList[t]);
	}
	output4<<"在Bus中存在，但在Toponode中不存在的节点："<<noExistInTopoNodeList.size()<<endl;
	for(size_t i=0;i<noExistInTopoNodeList.size();++i)
	{
		output4<<noExistInTopoNodeList[i].getBusName()<<endl
			<<noExistInTopoNodeList[i].getBusOff()<<endl<<endl;
	}
	
	// printNum=0;
	// output5<<"ACline中有断开："<<endl;
	
	// printAClineOfflineBus
	/*output5<<"ACline中断开的节点："<<endl;
	int breakBusInAcline(0);
	for(size_t i=0;i<aclineList.size();++i)
	{
		if(aclineList[i].getAClineI_off())
		{
			output5<<busList[aclineList[i].getAClineI_node()]<<endl;
			breakBusInAcline++;
		}
		else if(aclineList[i].getAClineJ_off())
		{
			output5<<busList[aclineList[i].getAClineJ_node()]<<endl;
			breakBusInAcline++;
		}
		else
			continue;
	}
	output5<<endl<<breakBusInAcline<<endl;*/
	
	input.close();
	output1.close();
	output2.close();
	output3.close();
	output4.close();
	return 0;
}