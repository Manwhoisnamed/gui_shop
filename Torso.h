
 #include "RoboPart.h"
 
 using namespace std;

 #ifndef __TORSO_H
 #define __TORSO_H 2016
 class Torso : public RoboPart{
  private:
    double draw;
    int batterySpace;
  public:
    Torso(){};
    Torso(string iname, int iSN, double iweight, double icost, string idescription, double idraw, int bspace) : RoboPart(iname, iSN, iweight, icost, idescription) , draw(idraw), batterySpace(bspace){}
    double getDraw();
    int getBSpace();
    int getASockets();
    int getLSockets();
 };
 #endif
