

 #include "RoboPart.h"
 
 using namespace std;

 #ifndef __ARM_H
 #define __ARM_H 2016
 class Arm : public RoboPart{
  private:
    double passiveDraw;
    double activeDraw;
    bool laser;    
    string picture;
  public:
    Arm(){};
    Arm(string iname, int iSN, double iweight, double icost, string idescription, double ipassiveDraw, double iactiveDraw, bool ilaser, string ipicture): 
  	RoboPart(iname, iSN, iweight, icost, idescription), 
	passiveDraw(ipassiveDraw), 
	activeDraw(iactiveDraw), 
	laser(ilaser),
	picture(ipicture){}
    double getpassiveDraw();
    double getactiveDraw();
    bool getLaser();
    string getPicture();
 };
 #endif
