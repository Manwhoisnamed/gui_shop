


 #include "RoboPart.h"
 
 using namespace std;
 #ifndef __LEG_H
 #define __LEG_H 2016
 class Leg : public RoboPart{
  private:
    double passiveDraw;
    double activeDraw;
    int speed;    
  public:
    Leg(){};
    Leg(string iname, int iSN, double iweight, double icost, string idescription, double ipassiveDraw, double iactiveDraw, int ispeed) : RoboPart(iname, iSN, iweight, icost, idescription) , passiveDraw(ipassiveDraw), activeDraw(iactiveDraw), speed(ispeed){}
    double getpassiveDraw();
    double getactiveDraw();
    int getSpeed();
    string getType() override;
 };
 #endif
