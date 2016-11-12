
 #include <string>
 #include <iostream>
 
 using namespace std;

 #ifndef __ROBOPART_H
 #define __ROBOPART_H 2016
 class RoboPart {
  public:
    RoboPart(){};
    RoboPart(string iname, int iSN, double iweight, double icost, string idescription): 
        name(iname), 
    	SN(iSN), 
    	weight(iweight), 
	cost(icost), 
	description(idescription){} 
    string getName();
    int getSN();
    double getWeight();
    double getCost();
    string getDescription();
  private:
    string name;
    int SN;
    double weight;
    double cost;
    string description;
 };
 #endif
