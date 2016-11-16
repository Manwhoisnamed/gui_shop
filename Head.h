


 #include "RoboPart.h"
 
 using namespace std;

 #ifndef __HEAD_H
 #define __HEAD_H 2016
 class Head : public RoboPart{
  private:
    double draw;
    bool laser;    
    string picture;
  public:
    Head(){};
    Head(string iname, int iSN, double iweight, double icost, string idescription, double idraw, bool ilaser, string ipicture): 
    RoboPart(iname, iSN, iweight, icost, idescription), 
    draw(idraw), 
    laser(ilaser),
    picture(ipicture){}
    double getDraw();
    bool getLaser();
    string getPicture();
 };
 #endif
