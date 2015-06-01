#include "toponode.h"

//TopoNode
bool TopoNode::operator==(const TopoNode& topoNode)
{
	return this->topoNodeName==topoNode.getTopoNodeName();
}

ostream& operator<<(ostream& output,TopoNode& topoNode)
{
	output<<"节点名称："<<topoNode.getTopoNodeName()<<endl;
	output<<"节点电压："<<topoNode.getTopoNodeV()<<endl;
	output<<"节点相角："<<topoNode.getTopoNodeAng()<<endl;
	output<<"节点电压基准："<<topoNode.getTopoNodeVbase()<<endl;
	return output;
}
