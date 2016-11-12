


 #include "RoboPart.h"
 
 using namespace std;

 #ifndef __HEAD_H
 #define __HEAD_H 2016
 class Head : public RoboPart{
  private:
    double draw;
    bool laser;    
  public:
    Head(){};
    Head(string iname, int iSN, double iweight, double icost, string idescription, double idraw, bool ilaser) : RoboPart(iname, iSN, iweight, icost, idescription) , draw(idraw), laser(ilaser){}
    double getDraw();
    bool getLaser();
 };
 #endif
