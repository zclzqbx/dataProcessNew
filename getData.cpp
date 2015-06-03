#include "share.h"
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

ifstream input("nx_20150427_1355.txt",ios::in);
//ָ����������λ��
ofstream output1("busdata.txt",ios::ate);
ofstream output2("aclinedata.txt",ios::ate);
ofstream output3("toponodedata.txt",ios::ate);
ofstream output4("unitdata.txt",ios::ate);
ofstream output5("transformerdata.txt",ios::ate);
ofstream output6("busInTransformer.txt",ios::ate);
ofstream output7("totalBranch.txt",ios::ate);
ofstream output8("busNameInBranch.txt",ios::ate);

int main()
{
	vector<Bus> busList;//��������нڵ�
	vector<ACline> aclineList;//���������ACline
	vector<TopoNode> topoNodeList;
	vector<Transformer> transformerList;
	vector<Unit> unitList;
	
	getData(input,busList,aclineList,topoNodeList,unitList,transformerList);
	
	// int printNum=0;
	for(size_t i=0;i!=busList.size();++i)
	{
		output1<<busList[i]<<endl;//�޲�����
		// if(busList[i].printBusOnline(output1))//������߽ڵ�
		// {
			// printNum++;
			// output1<<endl;
		// }
		
	}
	// output1<<endl<<"�������:"<<printNum<<endl;
	
	// printNum=0;
	for(size_t j=0;j!=aclineList.size();++j)
	{
		output2<<aclineList[j]<<endl;
		// if(aclineList[j].printAClineOnline(output2))
		// {
			// printNum++;
			// output2<<endl;
		// }
	}
	// output2<<endl<<"֧·����:"<<printNum<<endl;
	
	// printNum=0;
	for(size_t j=0;j!=topoNodeList.size();++j)
	{
		output3<<topoNodeList[j]<<endl;
	}
	
	for(size_t t=0;t<unitList.size();++t)
	{
		output4<<unitList[t]<<endl;
		// size_t k=0;
		// for(;k<topoNodeList.size();++k)
		// {
			// if(busList[t].getBusName()==topoNodeList[k].getTopoNodeName())
				// break;
		// }
		// if(k>=topoNodeList.size())
			// noExistInTopoNodeList.push_back(busList[t]);
	}
	// output4<<"��Bus�д��ڣ�����Toponode�в����ڵĽڵ㣺"<<noExistInTopoNodeList.size()<<endl;
	// for(size_t i=0;i<noExistInTopoNodeList.size();++i)
	// {
		// output4<<noExistInTopoNodeList[i].getBusName()<<endl
			// <<noExistInTopoNodeList[i].getBusOff()<<endl<<endl;
	// }
	
	// printNum=0;
	// output5<<"ACline���жϿ���"<<endl;
	
	// printAClineOfflineBus
	/*output5<<"ACline�жϿ��Ľڵ㣺"<<endl;
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
	for(size_t i=0;i<transformerList.size();++i)
	{
		output5<<transformerList[i]<<endl;
	}	
	
	cout<<"Bus�����ߵĽڵ�:"<<getNumberOfBusOnline(busList)<<endl;
	//��ȡ���ߵ�ACline
	vector<ACline> aclineOnline=getAClineOnline(aclineList);
	cout<<"ACline�����ߵ�֧·:"<<aclineOnline.size()<<endl;
	cout<<"Unit�����ߵĻ���:"<<getNumberOfUnitOnline(unitList)<<endl;	
	cout<<"ACline�г��ֵ����нڵ�:"<<busNameInAcline(aclineList).size()<<endl;
	cout<<"����ACline�г��ֵ����нڵ�:"<<busNameInAcline(aclineOnline).size()<<endl;
	vector<string> busInTrans=busNameInTransformer(transformerList);
	cout<<"Transformer�г��ֵ����нڵ�:"<<busInTrans.size()<<endl;
	for(size_t i=0;i<busInTrans.size();++i)
		output6<<busInTrans[i]<<endl;
	
	vector<Branch> branchList;
	//��ȡacline��transformer�е���������֧·
	branchList=totalBranch(aclineList,transformerList);
	cout<<"֧·����:"<<branchList.size()<<endl;
	for(size_t i=0;i<branchList.size();++i)
	{
		// output7<<branchList[i]<<endl;
		branchList[i].printUnitStyle(output7);
	}
	
	//��ȡBranch���������ߵĽڵ�
	vector<string> vecBranchBusName;
	vecBranchBusName=busNameInBranchList(branchList);
	cout<<"BranchList�е��ܽڵ�����"<<vecBranchBusName.size()<<endl;
	for(size_t i=0;i<vecBranchBusName.size();++i)
	{
		output8<<vecBranchBusName[i]<<endl;
	}
	input.close();
	output1.close();
	output2.close();
	output3.close();
	output4.close();
	output5.close();
	output6.close();
	output7.close();
	output8.close();
	return 0;
}