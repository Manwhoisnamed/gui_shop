
 #include "RoboPart.h"
 
 using namespace std;

 #ifndef __BATTERY_H
 #define __BATTERY_H 2016
 class Battery : public RoboPart{
  private:
    double charge;    
  public:
    Battery(){};
    Battery(string iname, int iSN, double iweight, double icost, string idescription, double icharge): 
    RoboPart(iname, iSN, iweight, icost, idescription),
    charge(icharge){}
    double getCharge();
 };
 #endif
