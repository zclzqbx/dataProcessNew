#include "toponode.h"

//TopoNode
bool TopoNode::operator==(const TopoNode& topoNode)
{
	return this->topoNodeName==topoNode.getTopoNodeName();
}

ostream& operator<<(ostream& output,TopoNode& topoNode)
{
	output<<"�ڵ����ƣ�"<<topoNode.getTopoNodeName()<<endl;
	output<<"�ڵ��ѹ��"<<topoNode.getTopoNodeV()<<endl;
	output<<"�ڵ���ǣ�"<<topoNode.getTopoNodeAng()<<endl;
	output<<"�ڵ��ѹ��׼��"<<topoNode.getTopoNodeVbase()<<endl;
	return output;
}
