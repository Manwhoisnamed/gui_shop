//maxwell sanders 1001069652
//this is the leg h file

 #include "RoboPart.h"
 
 using namespace std;
 #ifndef __LEG_H
 #define __LEG_H 2016
 class Leg : public RoboPart{
  private:
    double passiveDraw;
    double activeDraw;
    int speed;    
    string picture;
  public:
    Leg(){};
    Leg(string iname, int iSN, double iweight, double icost, string idescription, double ipassiveDraw, double iactiveDraw, int ispeed, string ipicture): 
    RoboPart(iname, iSN, iweight, icost, idescription), 
    passiveDraw(ipassiveDraw), 
    activeDraw(iactiveDraw), 
    speed(ispeed),
    picture(ipicture){}
    double getpassiveDraw();
    double getactiveDraw();
    int getSpeed();
    string getPicture();
 };
 #endif
