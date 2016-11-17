//maxwell sanders 1001069652
//this is the torso h file

 #include "RoboPart.h"
 
 using namespace std;

 #ifndef __TORSO_H
 #define __TORSO_H 2016
 class Torso : public RoboPart{
  private:
    double draw;
    int batterySpace;
    string picture;
  public:
    Torso(){};
    Torso(string iname, int iSN, double iweight, double icost, string idescription, double idraw, int bspace, string ipicture): 
    RoboPart(iname, iSN, iweight, icost, idescription), 
    draw(idraw), 
    batterySpace(bspace),
    picture(ipicture){}

    double getDraw();
    int getBSpace();
    int getASockets();
    int getLSockets();
    string getPicture();
 };
 #endif
