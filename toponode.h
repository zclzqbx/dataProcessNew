#ifndef TOPONODE
#define TOPONODE

#include <iostream>
#include <string>

using namespace std;

class TopoNode{
public:
	void setTopoNodeName(string name){topoNodeName=name;}
	void setTopoNodeV(double V){topoNodeV=V;}
	void setTopoNodeAng(double ang){topoNodeAng=ang;}
	void setTopoNodeVbase(double vBase){topoNodeVbase=vBase;}
	
	string getTopoNodeName()const{return topoNodeName;}
	double getTopoNodeV()const{return topoNodeV;}
	double getTopoNodeAng()const{return topoNodeAng;}
	double getTopoNodeVbase()const{return topoNodeVbase;}
	
	bool operator==(const TopoNode&);//жиди
	friend ostream& operator<<(ostream& ,TopoNode&);
	
private:
	string topoNodeName;
	double topoNodeV;
	double topoNodeAng;
	double topoNodeVbase;

};

#endif //TOPONODE